# Contributing to Auto Clicker

First off, thank you for considering contributing to Auto Clicker! It's people like you that make Auto Clicker such a great tool.

## Code of Conduct

By participating in this project, you are expected to uphold our Code of Conduct:
- Be respectful and inclusive
- Welcome newcomers and help them get started
- Focus on what is best for the community
- Show empathy towards other community members

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check the existing issues to avoid duplicates. When you are creating a bug report, please include as many details as possible:

- **Use a clear and descriptive title**
- **Describe the exact steps to reproduce the problem**
- **Provide specific examples to demonstrate the steps**
- **Describe the behavior you observed and what behavior you expected**
- **Include screenshots if applicable**
- **Include your environment details** (Windows version, etc.)

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, please include:

- **Use a clear and descriptive title**
- **Provide a detailed description of the suggested enhancement**
- **Explain why this enhancement would be useful**
- **List any alternatives you've considered**

### Pull Requests

The process described here has several goals:
- Maintain code quality
- Fix problems that are important to users
- Engage the community in working toward the best possible Auto Clicker

Please follow these steps:

1. **Fork the repository**
2. **Create a new branch** for your feature or bug fix
3. **Make your changes** with clear, concise commits
4. **Test your changes** thoroughly
5. **Update documentation** if necessary
6. **Submit a pull request**

#### Pull Request Guidelines

- Fill in the required template
- Include screenshots and animated GIFs in your pull request whenever possible
- Follow the C coding style conventions
- Include thoughtfully-worded, well-structured commit messages
- Document new code based on the Documentation Styleguide
- End all files with a newline

## Development Setup

### Prerequisites
- Windows 7 or later
- MinGW-w64 compiler (recommended via MSYS2)
- Git
- Text editor or IDE of your choice

### Setting Up Development Environment

1. **Install MSYS2**:
   ```bash
   # Download and install MSYS2 from https://www.msys2.org/
   ```

2. **Install MinGW toolchain**:
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-make
   ```

3. **Clone the repository**:
   ```bash
   git clone https://github.com/wang-zgs/auto-clicker.git
   cd auto-clicker
   ```

4. **Build the project**:
   ```bash
   # Using batch script
   build_clicker.bat
   
   # Or using Makefile
   make
   ```

### Testing

Before submitting your contribution, please test:

1. **Functionality Testing**:
   - Test all clicking modes (left/right)
   - Test position selection
   - Test hotkey functionality
   - Test delay start feature
   - Test mouse button stop feature

2. **Compatibility Testing**:
   - Test on different Windows versions if possible
   - Ensure no memory leaks
   - Check for proper resource cleanup

## Styleguides

### Git Commit Messages

- Use the present tense ("Add feature" not "Added feature")
- Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
- Limit the first line to 72 characters or less
- Reference issues and pull requests liberally after the first line

Example:
```
Add mouse button stop functionality

- Implement GetAsyncKeyState for mouse button detection
- Add opposite button press detection during clicking
- Update documentation and usage instructions

Fixes #123
```

### C Code Style

- Use 4 spaces for indentation (no tabs)
- Use descriptive variable names
- Comment complex logic
- Keep functions reasonably small
- Use consistent naming conventions

### Documentation Style

- Use Markdown for documentation
- Use clear, concise language
- Include code examples where appropriate
- Keep screenshots and GIFs up to date

## Recognition

Contributors who make significant contributions will be:
- Listed in the project's README
- Mentioned in release notes
- Given appropriate credit in commit messages

## Questions?

Don't hesitate to ask questions! You can:
- Open an issue with the "question" label
- Contact the maintainers directly
- Start a discussion in the GitHub Discussions tab

## License

By contributing to Auto Clicker, you agree that your contributions will be licensed under the MIT License.

---

Thank you for your interest in contributing to Auto Clicker! 🎉
