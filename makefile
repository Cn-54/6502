
CC      = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude -g -O0

SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

TARGET = $(BIN_DIR)/cpu

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
