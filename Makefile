APP_NAME = FlappyDragon
BUILD_DIR = ./bin
C_FILES = ./src/*.c ./src/libraylib.a
CFLAGS = -Wall -g

APP_DEFINES:=
APP_INCLUDES:= -I./src/raylib -framework CoreVideo -framework GLUT -framework Cocoa -framework OpenGL -framework IOKit -ldl

build:
	clang $(CFLAGS) $(C_FILES) -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES)

levels:
	cc -c ./src/levels/level_one.c -o ./src/levels/level_one.o
	cc -shared -o ./src/levels/level_one.so ./src/levels/level_one.o
