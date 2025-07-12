@echo off
title GitHub发布脚本
echo ===================================
echo     GitHub 发布脚本
echo ===================================
echo.

echo 📋 发布检查清单：
echo.
echo ✅ 1. 在GitHub上创建新仓库
echo    - 仓库名建议: auto-clicker 或 click-tool
echo    - 设置为公开仓库
echo    - 不要初始化README、.gitignore或LICENSE
echo.
echo ✅ 2. 本地Git仓库已初始化
git log --oneline -3
echo.

echo ⚠️  3. 请配置远程仓库连接：
echo    git remote add origin https://github.com/YOUR_USERNAME/auto-clicker.git
echo    （替换 YOUR_USERNAME 为您的GitHub用户名）
echo.

echo 🚀 4. 推送到GitHub：
echo    git branch -M main
echo    git push -u origin main
echo.

echo 📦 5. 创建Release发布：
echo    - 访问GitHub仓库页面
echo    - 点击 "Releases" → "Create a new release"
echo    - Tag: v1.2
echo    - 标题: Auto Clicker v1.2 - 防误触版本
echo    - 上传 clicker_app.exe 作为附件
echo.

echo 当前项目文件：
dir /b *.c *.md *.bat Makefile LICENSE .gitignore 2>nul
echo.

echo 📖 详细步骤请参考: GITHUB_PUBLISH_GUIDE.md
echo.
pause
