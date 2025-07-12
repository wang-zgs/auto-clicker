#!/bin/bash
# GitHub 连接和推送脚本示例
# 请将 YOUR_USERNAME 替换为您的实际GitHub用户名

echo "==================================="
echo "    GitHub 发布脚本"
echo "==================================="
echo

# 检查是否已配置远程仓库
if git remote get-url origin 2>/dev/null; then
    echo "✅ 远程仓库已配置"
    git remote -v
else
    echo "⚠️  请先配置远程仓库："
    echo "git remote add origin https://github.com/YOUR_USERNAME/auto-clicker.git"
    echo
    echo "替换 YOUR_USERNAME 为您的GitHub用户名"
    exit 1
fi

echo
echo "当前分支状态："
git status --short

echo
echo "准备推送到GitHub..."
echo "执行命令："
echo "git branch -M main"
echo "git push -u origin main"

# 注意：实际执行需要GitHub仓库存在
# git branch -M main
# git push -u origin main

echo
echo "推送完成后，访问您的GitHub仓库页面查看结果"
echo "仓库地址：https://github.com/YOUR_USERNAME/auto-clicker"
