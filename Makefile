BUILD_DIR:=build
TARGET:= $(BUILD_DIR)/Dijkstra
CFLAGS:= -O0 -Wall -Wextra -g -Iinclude -std=c11

C_FILES := $(wildcard src/*.c)
OBJ_FILES := $(C_FILES:src/%.c=$(BUILD_DIR)/%_c.o)

.PHONY: clean all build
all: build

#compile cpp files and generate obj files
build/%_c.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

#link obj files to excutable file
build: $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)
