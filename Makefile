#compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g -IInclude
#directory names
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
#create objects
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
#output to bin folder
TARGET = $(BIN_DIR)/Library

all: $(TARGET)
#Compiling
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)
#linking turning each .cpp to .o
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
#defines make run
run: all
	./$(TARGET)

debug: all
	@echo "Debugging with gdb..."
	gdb ./$(target)

val: all
	@echo "Running with valgrind..."
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)
#defines make clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
#tells compiler all, run, and clean arent directory or files
.PHONY: all run clean
