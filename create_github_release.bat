@echo off
title GitHub Release Creator v1.3
echo ====================================
echo       GitHub Release Creator v1.3
echo ====================================
echo.

echo 准备创建 GitHub Release v1.3...
echo.

echo 1. 检查当前Git状态...
git status
echo.

echo 2. 检查标签是否存在...
git tag -l | findstr v1.3
if %ERRORLEVEL% neq 0 (
    echo 创建v1.3标签...
    git tag -a v1.3 -m "Auto Clicker v1.3 - 鼠标按键停止版本"
    git push origin v1.3
) else (
    echo v1.3标签已存在
)
echo.

echo 3. 确保所有更改已推送...
git push origin main
echo.

echo ====================================
echo Release创建指南:
echo ====================================
echo.
echo 请手动在GitHub上创建Release:
echo.
echo 1. 访问: https://github.com/wang-zgs/auto-clicker/releases/new
echo.
echo 2. 填写以下信息:
echo    - Tag version: v1.3
echo    - Release title: Auto Clicker v1.3 - 鼠标按键停止版本
echo    - Description: 复制 RELEASE_NOTES_v1.3.md 的内容
echo.
echo 3. 上传以下文件作为Assets:
echo    - clicker_app.exe (主程序文件)
echo    - Source code (zip) (GitHub自动生成)
echo    - Source code (tar.gz) (GitHub自动生成)
echo.
echo 4. 勾选 "Set as the latest release"
echo.
echo 5. 点击 "Publish release"
echo.

echo 主要文件列表:
echo ====================================
dir /b *.exe *.md *.bat
echo.

echo Release说明文档已创建: RELEASE_NOTES_v1.3.md
echo 您可以复制此文件内容作为Release描述
echo.

echo 按任意键在浏览器中打开GitHub Release页面...
pause >nul

echo 正在打开GitHub Release页面...
start https://github.com/wang-zgs/auto-clicker/releases/new

echo.
echo 创建完成后，请验证Release是否正确发布。
pause
