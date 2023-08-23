# Define the compiler
CXX = clang++
#CXX = g++

# Define compilation options
CXXFLAGS = -std=c++20 -fcolor-diagnostics -fansi-escape-codes -g
#CXXFLAGS = -Wall -std=c++20

# Define file directories
SRC_DIR = ./src
BIN_DIR = ./bin
INC_DIR = ./include
MAIN = ./main.cpp

# Add the header inclusion directory
CXXFLAGS += -I$(INC_DIR)

# Recursively find all .cpp files in SRC_DIR
SRCS := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Get the corresponding .o file names
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))

# Define the executable name
TARGET = clirpg

# Rule to generate object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c -o $@ $<

# Rule to generate the executable
$(BIN_DIR)/$(TARGET): $(OBJS) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(MAIN)

all: $(BIN_DIR)/$(TARGET)

# Rule to clean
clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all clean

# Manual reminder

# Clean /bin
# For each file inside /src
# clang++ -c ./src/file.cpp -o ./bin/file.o
# Once
# clang++ ./main.cpp ./bin/*.o -o Program