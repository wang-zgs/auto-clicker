#include <windows.h>
#include <stdio.h>
#include <commctrl.h>
#include <time.h>

#pragma comment(lib, "comctl32.lib")

// 窗口ID定义
#define ID_MAIN_WINDOW 1000
#define ID_START_BUTTON 1001
#define ID_STOP_BUTTON 1002
#define ID_INTERVAL_EDIT 1003
#define ID_INTERVAL_LABEL 1004
#define ID_LEFT_RADIO 1005
#define ID_RIGHT_RADIO 1006
#define ID_POSITION_LABEL 1007
#define ID_SET_POSITION_BUTTON 1008
#define ID_STATUS_LABEL 1009
#define ID_CLICK_COUNT_LABEL 1010
#define ID_HOTKEY_LABEL 1011
#define ID_BUTTON_TYPE_LABEL 1012

// 全局变量
HWND hMainWindow;
HWND hStartButton, hStopButton;
HWND hIntervalEdit, hIntervalLabel;
HWND hLeftRadio, hRightRadio;
HWND hPositionLabel, hSetPositionButton;
HWND hStatusLabel, hClickCountLabel;
HWND hHotkeyLabel, hButtonTypeLabel;

int isClicking = 0;
int clickInterval = 100;
int isLeftClick = 1;
int clickX = 0, clickY = 0;
int clickCount = 0;
HANDLE clickThread = NULL;
HANDLE delayThread = NULL;
HHOOK mouseHook = NULL;
HHOOK globalMouseHook = NULL;
int isSettingPosition = 0;
int isCountingDown = 0;

// 窗口过程函数声明
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// 鼠标钩子过程函数声明
LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK GlobalMouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);

// 其他函数声明
void startClicking();
void stopClicking();
void setClickPosition();
DWORD WINAPI DelayStartThreadProc(LPVOID lpParam);

// 鼠标钩子回调函数
LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && isSettingPosition) {
        if (wParam == WM_LBUTTONDOWN) {
            // 获取鼠标点击位置
            POINT cursor;
            GetCursorPos(&cursor);
            clickX = cursor.x;
            clickY = cursor.y;
            
            // 更新位置显示
            wchar_t posText[100];
            swprintf(posText, 100, L"点击位置: (%d, %d)", clickX, clickY);
            SetWindowTextW(hPositionLabel, posText);
            
            // 取消设置位置模式
            isSettingPosition = 0;
            UnhookWindowsHookEx(mouseHook);
            mouseHook = NULL;
            
            // 更新按钮文本
            SetWindowTextW(hSetPositionButton, L"设置点击位置");
            
            // 自动开始连点
            if (!isClicking) {
                startClicking();
            }
            
            // 阻止这次点击传递给其他窗口
            return 1;
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

// 全局鼠标钩子回调函数（用于检测停止连点的按键）
LRESULT CALLBACK GlobalMouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && isClicking && !isCountingDown) {
        // 如果当前在连点过程中
        if ((isLeftClick && wParam == WM_RBUTTONDOWN) || // 左键连点时检测右键
            (!isLeftClick && wParam == WM_LBUTTONDOWN)) { // 右键连点时检测左键
            
            // 停止连点
            stopClicking();
            
            // 阻止这次点击传递给其他窗口
            return 1;
        }
    }
    return CallNextHookEx(globalMouseHook, nCode, wParam, lParam);
}

// 点击模拟函数
void simulateClick() {
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    
    // 如果设置了特定位置，则移动鼠标到该位置
    if(clickX != 0 || clickY != 0) {
        SetCursorPos(clickX, clickY);
    }
    
    if(isLeftClick) {
        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &input, sizeof(INPUT));
        input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    } else {
        input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        SendInput(1, &input, sizeof(INPUT));
        input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    }
    SendInput(1, &input, sizeof(INPUT));
    
    clickCount++;
    
    // 更新点击计数显示
    wchar_t countText[100];
    swprintf(countText, 100, L"点击次数: %d", clickCount);
    SetWindowTextW(hClickCountLabel, countText);
}

// 点击线程函数
DWORD WINAPI ClickThreadProc(LPVOID lpParam) {
    while(isClicking) {
        simulateClick();
        
        // 检查是否按下了停止按键
        if(isLeftClick) {
            // 左键连点时检查右键是否按下
            if(GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
                break; // 退出循环，停止连点
            }
        } else {
            // 右键连点时检查左键是否按下
            if(GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
                break; // 退出循环，停止连点
            }
        }
        
        Sleep(clickInterval);
    }
    
    // 如果是通过按键停止的，需要调用停止函数更新UI
    if(isClicking) {
        isClicking = 0;
        PostMessage(hMainWindow, WM_USER + 1, 0, 0); // 发送自定义消息更新UI
    }
    
    return 0;
}

// 延迟启动线程函数
DWORD WINAPI DelayStartThreadProc(LPVOID lpParam) {
    for(int i = 2; i >= 1; i--) {
        if(!isCountingDown) break; // 如果用户取消了，退出倒计时
        
        wchar_t countdownText[100];
        swprintf(countdownText, 100, L"状态: %d秒后开始连点...", i);
        SetWindowTextW(hStatusLabel, countdownText);
        
        Sleep(1000);
    }
    
    if(isCountingDown) {
        // 倒计时结束，开始实际的点击
        isClicking = 1;
        isCountingDown = 0;
        
        clickThread = CreateThread(NULL, 0, ClickThreadProc, NULL, 0, NULL);
        
        // 更新状态显示，包含停止提示
        if(isLeftClick) {
            SetWindowTextW(hStatusLabel, L"状态: 左键连点中... (按右键停止)");
        } else {
            SetWindowTextW(hStatusLabel, L"状态: 右键连点中... (按左键停止)");
        }
    }
    
    delayThread = NULL;
    return 0;
}

// 开始连点
void startClicking() {
    if(clickThread || delayThread) return;
    
    // 获取间隔时间
    wchar_t intervalText[20];
    GetWindowTextW(hIntervalEdit, intervalText, 20);
    clickInterval = _wtoi(intervalText);
    if(clickInterval <= 0) clickInterval = 100;
    
    // 获取点击类型
    isLeftClick = SendMessage(hLeftRadio, BM_GETCHECK, 0, 0) == BST_CHECKED;
    
    // 开始倒计时
    isCountingDown = 1;
    clickCount = 0; // 重置点击计数
    
    // 创建延迟启动线程
    delayThread = CreateThread(NULL, 0, DelayStartThreadProc, NULL, 0, NULL);
    
    // 更新UI状态
    EnableWindow(hStartButton, FALSE);
    EnableWindow(hStopButton, TRUE);
    SetWindowTextW(hStatusLabel, L"状态: 2秒后开始连点...");
    SetWindowTextW(hClickCountLabel, L"点击次数: 0");
}

// 停止连点
void stopClicking() {
    // 停止倒计时
    isCountingDown = 0;
    
    // 停止点击
    isClicking = 0;
    
    // 移除全局鼠标钩子
    if(globalMouseHook) {
        UnhookWindowsHookEx(globalMouseHook);
        globalMouseHook = NULL;
    }
    
    // 等待延迟线程结束
    if(delayThread) {
        WaitForSingleObject(delayThread, INFINITE);
        CloseHandle(delayThread);
        delayThread = NULL;
    }
    
    // 等待点击线程结束
    if(clickThread) {
        WaitForSingleObject(clickThread, INFINITE);
        CloseHandle(clickThread);
        clickThread = NULL;
    }
    
    // 更新UI状态
    EnableWindow(hStartButton, TRUE);
    EnableWindow(hStopButton, FALSE);
    SetWindowTextW(hStatusLabel, L"状态: 已停止");
}

// 设置点击位置
void setClickPosition() {
    if (isSettingPosition) {
        // 如果已经在设置模式，取消设置
        isSettingPosition = 0;
        if (mouseHook) {
            UnhookWindowsHookEx(mouseHook);
            mouseHook = NULL;
        }
        SetWindowTextW(hSetPositionButton, L"设置点击位置");
        SetWindowTextW(hPositionLabel, L"位置设置已取消");
    } else {
        // 进入设置位置模式
        isSettingPosition = 1;
        
        // 安装鼠标钩子
        mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, GetModuleHandle(NULL), 0);
        
        if (mouseHook) {
            SetWindowTextW(hSetPositionButton, L"取消设置");
            SetWindowTextW(hPositionLabel, L"请点击屏幕上要连点的位置...");
        } else {
            isSettingPosition = 0;
            MessageBoxW(hMainWindow, L"无法安装鼠标钩子，请以管理员身份运行程序", L"错误", MB_OK | MB_ICONERROR);
        }
    }
}

// 创建控件
void createControls(HWND hwnd) {
    // 开始按钮
    hStartButton = CreateWindowW(L"BUTTON", L"开始连点", 
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20, 20, 100, 30, hwnd, (HMENU)ID_START_BUTTON, NULL, NULL);
    
    // 停止按钮
    hStopButton = CreateWindowW(L"BUTTON", L"停止连点", 
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        140, 20, 100, 30, hwnd, (HMENU)ID_STOP_BUTTON, NULL, NULL);
    EnableWindow(hStopButton, FALSE);
    
    // 间隔时间标签
    hIntervalLabel = CreateWindowW(L"STATIC", L"点击间隔(ms):", 
        WS_CHILD | WS_VISIBLE,
        20, 70, 100, 20, hwnd, (HMENU)ID_INTERVAL_LABEL, NULL, NULL);
    
    // 间隔时间输入框
    hIntervalEdit = CreateWindowW(L"EDIT", L"100", 
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
        140, 70, 100, 20, hwnd, (HMENU)ID_INTERVAL_EDIT, NULL, NULL);
    
    // 左键单选按钮
    hLeftRadio = CreateWindowW(L"BUTTON", L"左键", 
        WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON | WS_GROUP,
        20, 110, 60, 20, hwnd, (HMENU)ID_LEFT_RADIO, NULL, NULL);
    SendMessage(hLeftRadio, BM_SETCHECK, BST_CHECKED, 0);
    
    // 右键单选按钮
    hRightRadio = CreateWindowW(L"BUTTON", L"右键", 
        WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
        100, 110, 60, 20, hwnd, (HMENU)ID_RIGHT_RADIO, NULL, NULL);
    
    // 设置位置按钮
    hSetPositionButton = CreateWindowW(L"BUTTON", L"设置点击位置", 
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20, 150, 120, 30, hwnd, (HMENU)ID_SET_POSITION_BUTTON, NULL, NULL);
    
    // 位置显示标签
    hPositionLabel = CreateWindowW(L"STATIC", L"点击位置: 当前鼠标位置", 
        WS_CHILD | WS_VISIBLE,
        20, 190, 300, 20, hwnd, (HMENU)ID_POSITION_LABEL, NULL, NULL);
    
    // 状态标签
    hStatusLabel = CreateWindowW(L"STATIC", L"状态: 就绪", 
        WS_CHILD | WS_VISIBLE,
        20, 220, 200, 20, hwnd, (HMENU)ID_STATUS_LABEL, NULL, NULL);
    
    // 点击计数标签
    hClickCountLabel = CreateWindowW(L"STATIC", L"点击次数: 0", 
        WS_CHILD | WS_VISIBLE,
        20, 250, 200, 20, hwnd, (HMENU)ID_CLICK_COUNT_LABEL, NULL, NULL);
    
    // 热键说明标签
    hHotkeyLabel = CreateWindowW(L"STATIC", L"热键: F6开始 F7停止", 
        WS_CHILD | WS_VISIBLE,
        20, 280, 200, 20, hwnd, (HMENU)ID_HOTKEY_LABEL, NULL, NULL);
    
    // 按钮类型显示标签
    hButtonTypeLabel = CreateWindowW(L"STATIC", L"当前选择: 左键", 
        WS_CHILD | WS_VISIBLE,
        20, 310, 200, 20, hwnd, (HMENU)ID_BUTTON_TYPE_LABEL, NULL, NULL);
}

// 窗口过程函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CREATE:
            createControls(hwnd);
            // 注册热键
            RegisterHotKey(hwnd, 1, 0, VK_F6);
            RegisterHotKey(hwnd, 2, 0, VK_F7);
            break;
            
        case WM_COMMAND:
            switch(LOWORD(wParam)) {
                case ID_START_BUTTON:
                    startClicking();
                    break;
                case ID_STOP_BUTTON:
                    stopClicking();
                    break;
                case ID_SET_POSITION_BUTTON:
                    setClickPosition();
                    break;
                case ID_LEFT_RADIO:
                    if(HIWORD(wParam) == BN_CLICKED) {
                        SendMessage(hLeftRadio, BM_SETCHECK, BST_CHECKED, 0);
                        SendMessage(hRightRadio, BM_SETCHECK, BST_UNCHECKED, 0);
                        SetWindowTextW(hButtonTypeLabel, L"当前选择: 左键");
                    }
                    break;
                case ID_RIGHT_RADIO:
                    if(HIWORD(wParam) == BN_CLICKED) {
                        SendMessage(hRightRadio, BM_SETCHECK, BST_CHECKED, 0);
                        SendMessage(hLeftRadio, BM_SETCHECK, BST_UNCHECKED, 0);
                        SetWindowTextW(hButtonTypeLabel, L"当前选择: 右键");
                    }
                    break;
            }
            break;
            
        case WM_USER + 1: // 自定义消息：鼠标按键停止连点
            // 更新UI状态
            EnableWindow(hStartButton, TRUE);
            EnableWindow(hStopButton, FALSE);
            SetWindowTextW(hStatusLabel, L"状态: 已通过鼠标按键停止");
            
            // 清理线程句柄
            if(clickThread) {
                WaitForSingleObject(clickThread, 1000); // 等待最多1秒
                CloseHandle(clickThread);
                clickThread = NULL;
            }
            
            // 移除全局鼠标钩子
            if(globalMouseHook) {
                UnhookWindowsHookEx(globalMouseHook);
                globalMouseHook = NULL;
            }
            break;
            
        case WM_HOTKEY:
            if(wParam == 1) { // F6
                if(!isClicking && !isCountingDown) startClicking();
            } else if(wParam == 2) { // F7
                if(isClicking || isCountingDown) stopClicking();
            }
            break;
            
        case WM_DESTROY:
            if(isClicking || isCountingDown) stopClicking();
            if(mouseHook) {
                UnhookWindowsHookEx(mouseHook);
                mouseHook = NULL;
            }
            if(globalMouseHook) {
                UnhookWindowsHookEx(globalMouseHook);
                globalMouseHook = NULL;
            }
            UnregisterHotKey(hwnd, 1);
            UnregisterHotKey(hwnd, 2);
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// 主函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    // 注册窗口类
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"ClickerApp";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    
    RegisterClassW(&wc);
    
    // 创建窗口
    hMainWindow = CreateWindowW(L"ClickerApp", L"连点器 v1.3", 
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,
        CW_USEDEFAULT, CW_USEDEFAULT, 380, 390,
        NULL, NULL, hInstance, NULL);
    
    if(!hMainWindow) {
        MessageBoxW(NULL, L"创建窗口失败!", L"错误", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    ShowWindow(hMainWindow, nCmdShow);
    UpdateWindow(hMainWindow);
    
    // 消息循环
    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
