@echo off
title 连点器应用编译器 v1.3
echo ================================
echo       连点器应用编译器 v1.3
echo ================================
echo.

echo 正在检查和关闭已运行的程序...
taskkill /f /im clicker_app.exe 2>nul
taskkill /f /im click.exe 2>nul

echo 等待2秒钟...
timeout /t 2 /nobreak > nul

echo 正在编译连点器应用...
gcc clicker_app.c -o clicker_app.exe -mwindows -lcomctl32 -lgdi32 -luser32

if %errorlevel% equ 0 (
    echo.
    echo ✓ 编译成功！
    echo 正在启动连点器应用...
    echo.
    start clicker_app.exe
    echo 程序已启动！
    echo.
    echo 使用说明：
    echo - 点击"开始连点"按钮或按F6键开始连点（2秒后开始）
    echo - 点击"停止连点"按钮或按F7键停止连点
    echo - 可以设置点击间隔时间(毫秒)
    echo - 可以选择左键或右键点击
    echo - 点击"设置点击位置"后可直接点击屏幕任意位置设定目标
    echo - 设置位置后程序会自动开始连点（含2秒倒计时）
    echo - 倒计时期间可按F7或停止按钮取消
    echo.
) else (
    echo.
    echo ✗ 编译失败！
    echo 请检查以下项目：
    echo 1. 确保已安装MinGW编译器
    echo 2. 确保MinGW已添加到系统PATH环境变量
    echo 3. 确保clicker_app.c文件存在于当前目录
    echo.
)

pause
