# 贡献指南

感谢您对连点器项目的关注！我们欢迎各种形式的贡献。

## 如何贡献

### 报告问题
- 使用 [Issues](https://github.com/yourusername/auto-clicker/issues) 报告 bug
- 请详细描述问题的重现步骤
- 包含您的系统环境信息

### 提出功能建议
- 在 Issues 中使用 "enhancement" 标签
- 详细描述您期望的功能
- 说明为什么这个功能有用

### 代码贡献

1. **Fork 仓库**
   ```bash
   git clone https://github.com/yourusername/auto-clicker.git
   ```

2. **创建分支**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **开发环境设置**
   - 安装 MinGW GCC 编译器
   - 确保能正常编译项目

4. **编码规范**
   - 使用清晰的变量和函数名
   - 添加必要的注释
   - 保持代码风格一致

5. **测试**
   - 编译并测试您的更改
   - 确保现有功能正常工作

6. **提交更改**
   ```bash
   git add .
   git commit -m "Add: 描述您的更改"
   ```

7. **推送并创建 PR**
   ```bash
   git push origin feature/your-feature-name
   ```

## 开发指南

### 项目结构
```
auto-clicker/
├── clicker_app.c      # 主程序源码
├── app.rc             # 资源文件
├── Makefile           # Make构建文件
├── build_clicker.bat  # Windows构建脚本
└── README.md          # 项目说明
```

### 编译项目
```bash
# Windows (MinGW)
gcc clicker_app.c -o clicker_app.exe -mwindows -lcomctl32 -lgdi32 -luser32

# 或使用构建脚本
build_clicker.bat
```

## 代码风格

- 函数名使用驼峰命名法
- 变量名使用有意义的英文名称
- 常量使用大写字母
- 适当添加注释说明复杂逻辑

## 提交信息格式

```
类型: 简短描述

详细描述（可选）
```

类型包括：
- `Add`: 新增功能
- `Fix`: 修复bug
- `Update`: 更新现有功能
- `Doc`: 文档更新
- `Style`: 代码格式调整

## 联系我们

如有任何问题，请通过以下方式联系：
- 创建 Issue
- 发送邮件到 [your-email@example.com]

感谢您的贡献！
