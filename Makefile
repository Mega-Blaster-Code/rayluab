CC = gcc
LUA = C:/lua/lua.exe

LIB_PATH = lib
CFLAGS = -std=c11 -Wall -Wextra -O0 -g -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function

LDFLAGS = -shared -LC:/lua -llua54 -L$(LIB_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm

SRC_PATH = src
OBJ_PATH = objs

SRC := $(wildcard $(SRC_PATH)/*.c)
OBJ := $(patsubst %.c,$(OBJ_PATH)/%.o,$(notdir $(SRC)))

TARGET = rayluab.dll

all: $(OBJ_PATH) $(TARGET) run

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

run:
	@$(LUA) main.lua

clean:
	rm -rf $(OBJ_PATH)/*.o $(TARGET)