# Auto Clicker

<div align="center">

![Version](https://img.shields.io/badge/version-1.3-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A powerful and user-friendly Windows auto clicker application

[Download Latest Release](https://github.com/wang-zgs/auto-clicker/releases) | [Usage Guide](#usage) | [Features](#features)

[🇨🇳 中文版](README.md) | [🇺🇸 English](README_EN.md)

</div>

## 🎯 Features

- ✨ **Graphical Interface** - Clean and intuitive user interface
- ⌨️ **Global Hotkeys** - F6 to start, F7 to stop (works system-wide)
- ⏱️ **Misclick Protection** - 2-second delay before starting to prevent accidental triggers
- 🎯 **Smart Positioning** - Click anywhere on screen to set target location
- 🖱️ **Dual Mode Control** - Support for both left and right mouse button clicking
- 🛑 **Mouse Button Stop** - Stop clicking instantly by pressing opposite mouse button

## 🔧 System Requirements

- **Operating System**: Windows 7 or later
- **Compiler**: MinGW GCC (MSYS2 recommended)
- **Dependencies**: Windows API (comctl32, gdi32, user32)

## 📦 Installation

### Method 1: Direct Download
1. Download `clicker_app.exe` from the [Releases page](https://github.com/wang-zgs/auto-clicker/releases)
2. Run the executable directly

### Method 2: Build from Source
1. Install MinGW development environment
2. Run `build_clicker.bat` compilation script
3. Execute the compiled `clicker_app.exe`

## 🎮 Usage

1. **Launch Program**: Double-click `clicker_app.exe`
2. **Set Click Mode**: Choose "Left Click" or "Right Click"
3. **Set Click Position**: Click "Set Click Position" button, then click the target location on screen
4. **Start Clicking**: Press `F6` key to start (2-second delay before actual clicking begins)
5. **Stop Clicking**:
   - Press `F7` key to stop
   - Or press the opposite mouse button (right button when left-clicking, left button when right-clicking)

## 🏗️ Building from Source

### Prerequisites
- Windows 7 or later
- MinGW-w64 compiler (recommended via MSYS2)
- Git (for cloning the repository)

### Build Steps
```bash
# Clone the repository
git clone https://github.com/wang-zgs/auto-clicker.git
cd auto-clicker

# Method 1: Using batch script
build_clicker.bat

# Method 2: Using Makefile
make

# Method 3: Manual compilation
gcc -o clicker_app.exe clicker_app.c app.rc -lcomctl32 -lgdi32 -luser32 -mwindows
```

## 📋 Version History

### v1.3 (2025-07-13) - Mouse Button Stop Version
- ➕ Added mouse button stop functionality
- 🔧 Optimized GetAsyncKeyState implementation
- 📚 Enhanced project documentation and version info
- 🧹 Cleaned up project structure, removed temporary files

### v1.2 (2025-07-13) - Misclick Protection Version
- ➕ Added 2-second delay start feature
- 🛡️ Prevents accidental trigger of clicking operations
- 🔧 Fixed radio button selection issues

### v1.1 (2025-07-13) - Position Selection Version
- ➕ Added "Set Click Position" functionality
- 🎯 Support for visual position selection
- 🖱️ Mouse hook implementation for position capture

### v1.0 (2025-07-13) - Basic Version
- 🎉 Initial version release
- ⌨️ Basic clicking functionality
- 🖱️ Left and right button selection

## ⚠️ Important Notes

- Please use the auto clicker responsibly and comply with the terms of service of games and applications
- The program has a 2-second delay after startup to prevent accidental triggers
- Global hotkeys work system-wide, please be mindful of your usage environment
- It's recommended to test the functionality before use to ensure it meets your requirements

## 🤝 Contributing

Contributions are welcome! Please feel free to submit Issues and Pull Requests to improve this project.

See [CONTRIBUTING.md](CONTRIBUTING.md) for detailed contribution guidelines.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🔗 Links

- **GitHub Repository**: https://github.com/wang-zgs/auto-clicker
- **Issue Tracker**: https://github.com/wang-zgs/auto-clicker/issues
- **Latest Releases**: https://github.com/wang-zgs/auto-clicker/releases

---

<div align="center">

**Made with ❤️ for the community**

If you find this project helpful, please consider giving it a ⭐️!

</div>
