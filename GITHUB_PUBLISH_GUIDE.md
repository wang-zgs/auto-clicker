# GitHub 发布指南

## 📋 发布步骤

### 1. 在GitHub上创建新仓库

1. 登录 [GitHub](https://github.com)
2. 点击右上角的 "+" 按钮，选择 "New repository"
3. 填写仓库信息：
   - **Repository name**: `auto-clicker` 或 `click-tool`
   - **Description**: `一个功能强大的Windows自动连点器`
   - **Visibility**: Public（公开）或 Private（私有）
   - **不要**勾选 "Initialize this repository with:"下面的任何选项

### 2. 连接本地仓库到GitHub

```bash
# 添加远程仓库（替换 YOUR_USERNAME 为您的GitHub用户名）
git remote add origin https://github.com/YOUR_USERNAME/auto-clicker.git

# 推送代码到GitHub
git branch -M main
git push -u origin main
```

### 3. 创建发布版本

1. 在GitHub仓库页面，点击 "Releases"
2. 点击 "Create a new release"
3. 填写发布信息：
   - **Tag version**: `v1.2`
   - **Release title**: `Auto Clicker v1.2 - 防误触版本`
   - **Description**: 
     ```
     ## 🎉 新功能
     - ⏱️ 新增2秒延迟启动功能，防止误触
     - 🔄 倒计时期间可通过F7或停止按钮取消
     - 📊 改进状态显示，实时显示倒计时
     
     ## 📁 下载文件
     - `clicker_app.exe` - 主程序（需要自行编译）
     - 源代码包含完整构建脚本
     ```

4. 上传 `clicker_app.exe` 文件作为发布资产
5. 点击 "Publish release"

### 4. 更新README中的链接

将README.md中的以下内容：
- `https://github.com/yourusername/auto-clicker` → 替换为您的实际仓库URL
- `yourusername` → 替换为您的GitHub用户名

### 5. 后续维护

#### 推送更新
```bash
git add .
git commit -m "Update: 描述您的更改"
git push
```

#### 创建新版本
```bash
git tag v1.3
git push origin v1.3
```

然后在GitHub上创建对应的Release。

## 🔧 可选：设置GitHub Pages

如果想要一个项目展示页面：

1. 在仓库设置中找到 "Pages"
2. 选择 "Deploy from a branch"
3. 选择 "main" 分支和 "/ (root)" 文件夹
4. 保存设置

## 📊 项目统计

当前项目包含：
- ✅ 完整的C语言源代码
- ✅ 构建脚本和Makefile
- ✅ 详细的README文档
- ✅ MIT开源许可证
- ✅ 贡献指南
- ✅ Git配置文件

## 🎯 下一步建议

1. 考虑添加更多功能（如自动更新检查）
2. 创建CI/CD流水线自动构建
3. 添加更多测试用例
4. 支持更多操作系统

## ❓ 常见问题

**Q: 如何更改仓库名称？**
A: 在GitHub仓库设置页面可以更改。

**Q: 如何设置仓库为私有？**
A: 在仓库设置的"General"部分可以更改可见性。

**Q: 忘记GitHub密码怎么办？**
A: 建议使用Personal Access Token代替密码。
