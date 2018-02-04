SHELL = /bin/sh

CXX = g++
CXXFLAGS_MIN = -ansi -pedantic -Wall -std=c++11
CXXFLAGS_EXTRA = -Wextra -Weffc++
CXXFLAGS = $(CXXFLAGS_MIN) $(CXXFLAGS_EXTRA)
LDFLAGS= 
RM = rm
RMFLAGS = -f

SRC_DIR=src
OBJ_DIR=build
BIN_DIR=bin
TESTS_DIR=Tests

SRC = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.h)
MAKEFILE = Makefile
OBJ=$(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC:.cpp=.o))
TARGET_NAME=analog
TARGET=$(BIN_DIR)/$(TARGET_NAME)

.SUFFIXES:

.PHONY: all
all: release test

.PHONY: release
release: CXXFLAGS += -O3
release: $(OBJ_DIR) $(BIN_DIR) $(TARGET)

.PHONY: debug
debug: CXXFLAGS += -Og -g -DDEBUG
debug: $(OBJ_DIR) $(BIN_DIR) $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) $(MAKEFILE)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

.PHONY: test
test: $(TARGET)
	cd $(TESTS_DIR); ./mktest.sh

.PHONY: clean
clean:
	$(RM) $(RMFLAGS) -r $(BIN_DIR) $(OBJ_DIR)

