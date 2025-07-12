# 连点器 (Auto Clicker)

<div align="center">

![Version](https://img.shields.io/badge/version-1.3-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

一个功能强大、界面友好的 Windows 自动连点器

[下载最新版本](https://github.com/wang-zgs/auto-clicker/releases) | [使用说明](#使用方法) | [功能特点](#功能特点)

[🇨🇳 中文版](README.md) | [🇺🇸 English](README_EN.md)

</div>

## 🎯 功能特点

- ✨ **图形化界面** - 简洁直观的用户界面
- ⌨️ **全局热键** - F6开始，F7停止（全局有效）
- ⏱️ **防误触保护** - 2秒延迟启动，防止意外触发
- 🎯 **智能定位** - 点击屏幕任意位置设定连点目标
- 🔄 **双键支持** - 支持左键和右键连点
- 🖱️ **智能停止** - 左键连点时按右键停止，右键连点时按左键停止
- ⚙️ **自定义间隔** - 可设置点击间隔时间
- 📊 **实时统计** - 显示点击次数和运行状态

## 🚀 快速开始

### 下载使用
1. 下载 [最新版本](https://github.com/yourusername/auto-clicker/releases)
2. 解压文件
3. 运行 `clicker_app.exe`

### 从源码编译
```bash
# 克隆仓库
git clone https://github.com/yourusername/auto-clicker.git
cd auto-clicker

# 编译运行
build_clicker.bat
```

## 📖 使用方法

### 基本操作
1. **开始连点**: 点击"开始连点"按钮或按F6键（2秒后开始）
2. **停止连点**: 
   - 点击"停止连点"按钮或按F7键
   - **新功能**: 左键连点时按右键停止，右键连点时按左键停止
3. **设置间隔**: 在输入框中设置点击间隔(毫秒)
4. **选择按键**: 选择左键或右键单选按钮

### 智能定位
1. 点击"设置点击位置"按钮
2. 直接点击屏幕上要连点的位置
3. 程序自动记录位置并开始连点

### 热键控制
- `F6` - 开始连点（全局热键）
- `F7` - 停止连点（全局热键，倒计时期间可取消）
- **鼠标按键**: 左键连点时按右键停止，右键连点时按左键停止

## 🛠️ 编译要求

- **编译器**: MinGW GCC 或 Visual Studio
- **系统**: Windows 7 及以上
- **依赖库**: Windows API, ComCtl32

### 安装编译环境
```bash
# 使用 MSYS2 安装 MinGW
winget install MSYS2.MSYS2
# 或下载安装包: https://www.msys2.org/

# 安装 GCC 编译器
pacman -S mingw-w64-x86_64-gcc
```

## 📝 版本历史

### v1.3 (2025-07-13) - 智能停止版本
- 🖱️ 新增鼠标按键智能停止功能
- 左键连点时按右键停止，右键连点时按左键停止
- 改进状态显示，显示当前连点类型和停止方式
- 优化钩子管理和资源清理

### v1.2 (2025-07-13) - 防误触版本
- ✨ 新增2秒延迟启动功能，防止误触
- 🔄 倒计时期间可通过F7或停止按钮取消
- 📊 改进状态显示，实时显示倒计时
- 🧹 优化线程管理和资源清理

### v1.1 (2025-07-13) - 增强版本
- 🎯 新增智能位置选择功能
- 🖱️ 修复单选按钮选择问题
- ✨ 改进用户交互体验

### v1.0 (2025-01-13) - 初始版本
- 🎉 基本连点功能和图形界面

## ⚠️ 注意事项

1. 请合理使用连点器，避免对其他应用造成干扰
2. 连点间隔建议不要设置过小，以免系统负载过重
3. 设置点击位置功能需要管理员权限才能正常工作
4. 开始连点后有2秒准备时间，可在此期间取消操作

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

1. Fork 本仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情

## 📧 联系方式

如有问题或建议，请提交 [Issue](https://github.com/yourusername/auto-clicker/issues)

---

<div align="center">
Made with ❤️ by [Your Name]
</div>
