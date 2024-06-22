# コンパイラとフラグの設定
CXX := g++
CXXFLAGS := -std=c++20 -w

# ディレクトリ設定
SRC_DIR := $(or $(src_dir), 11_Composite/C++)
OBJ_DIR := obj
BIN_DIR := bin

# ターゲットの設定
TARGET := $(BIN_DIR)/program

# ソースファイルとオブジェクトファイルの設定
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# ルールの設定
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
