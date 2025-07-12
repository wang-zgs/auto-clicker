@echo off
title 连点器应用完整编译器
color 0A
echo ================================
echo       连点器应用完整编译器 v1.0
echo ================================
echo.

echo [1/5] 清理旧文件...
del /q clicker_app.exe 2>nul
del /q app.res 2>nul
del /q click.exe 2>nul

echo [2/5] 关闭运行中的程序...
taskkill /f /im clicker_app.exe 2>nul
taskkill /f /im click.exe 2>nul

echo [3/5] 编译资源文件...
windres app.rc -O coff -o app.res 2>nul
if %errorlevel% equ 0 (
    echo ✓ 资源文件编译成功
) else (
    echo ! 资源文件编译失败，将使用默认资源
)

echo [4/5] 编译主程序...
if exist app.res (
    gcc clicker_app.c app.res -o clicker_app.exe -mwindows -lcomctl32 -lgdi32 -luser32
) else (
    gcc clicker_app.c -o clicker_app.exe -mwindows -lcomctl32 -lgdi32 -luser32
)

echo [5/5] 检查编译结果...
if %errorlevel% equ 0 (
    echo.
    echo ✓ 编译完成！
    echo 生成文件: clicker_app.exe
    echo 文件大小: 
    for %%f in (clicker_app.exe) do echo %%~zf bytes
    echo.
    echo 正在启动应用程序...
    start clicker_app.exe
    echo.
    echo ========================================
    echo 连点器应用已成功启动！
    echo.
    echo 主要功能：
    echo - 图形化界面操作
    echo - 热键支持 (F6开始/F7停止)
    echo - 自定义点击间隔
    echo - 支持左键/右键选择
    echo - 固定位置点击
    echo - 实时点击计数
    echo ========================================
) else (
    echo.
    echo ✗ 编译失败！
    echo.
    echo 可能的解决方案：
    echo 1. 确保MinGW已正确安装
    echo 2. 检查PATH环境变量是否包含MinGW/bin
    echo 3. 以管理员身份运行此脚本
    echo 4. 检查clicker_app.c文件是否存在
    echo.
    echo 错误代码: %errorlevel%
)

echo.
echo 按任意键退出...
pause >nul
