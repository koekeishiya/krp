FRAMEWORKS     = -framework Carbon
BUILD_PATH     = ./bin
BUILD_FLAGS    = -std=gnu89 -Wall -g
SRC        = ./src/krp.c
BIN           = $(BUILD_PATH)/krp

.PHONY: all clean install

all: clean $(BIN)

install: BUILD_FLAGS=-std=gnu89 -O3
install: clean $(BIN)

clean:
	rm -rf $(BUILD_PATH)

$(BUILD_PATH)/krp: $(SRC)
	mkdir -p $(BUILD_PATH)
	clang $^ $(BUILD_FLAGS) $(FRAMEWORKS) -o $@
