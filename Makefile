# 连点器应用程序 Makefile

# 编译器设置
CC = gcc
WINDRES = windres
CFLAGS = -Wall -Wextra -O2
LIBS = -mwindows -lcomctl32 -lgdi32 -luser32
TARGET = clicker_app.exe
SOURCE = clicker_app.c
RESOURCE = app.rc
RESOURCE_OBJ = app.res

# 默认目标
all: $(TARGET)

# 编译资源文件
$(RESOURCE_OBJ): $(RESOURCE)
	@echo "编译资源文件..."
	$(WINDRES) $(RESOURCE) -O coff -o $(RESOURCE_OBJ)

# 编译主程序
$(TARGET): $(SOURCE) $(RESOURCE_OBJ)
	@echo "编译主程序..."
	$(CC) $(CFLAGS) $(SOURCE) $(RESOURCE_OBJ) -o $(TARGET) $(LIBS)
	@echo "编译完成！"

# 编译主程序(不包含资源)
simple: $(SOURCE)
	@echo "编译主程序(无资源)..."
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) $(LIBS)
	@echo "编译完成！"

# 清理
clean:
	@echo "清理文件..."
	del /q $(TARGET) $(RESOURCE_OBJ) 2>nul || true
	@echo "清理完成！"

# 运行
run: $(TARGET)
	@echo "启动应用程序..."
	start $(TARGET)

# 帮助
help:
	@echo "可用命令："
	@echo "  make all    - 编译完整程序(包含资源)"
	@echo "  make simple - 编译简单程序(不包含资源)"
	@echo "  make clean  - 清理编译文件"
	@echo "  make run    - 运行程序"
	@echo "  make help   - 显示此帮助"

# 声明伪目标
.PHONY: all simple clean run help
