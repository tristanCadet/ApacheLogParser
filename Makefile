SHELL = /bin/sh
CXX = g++
CXXFLAGS_MIN = -ansi -pedantic -Wall -std=c++11
CXXFLAGS_EXTRA = -Wextra -Weffc++
CXXFLAGS = $(CXXFLAGS_MIN) $(CXXFLAGS_EXTRA)
LDFLAGS= 
RM = rm
RMFLAGS = -f
SRC= $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
MAKEFILE = Makefile
OBJ=$(SRC:.cpp=.o)
TARGET=analog

.SUFFIXES:

.PHONY: all
all: release

.PHONY: release
release: CXXFLAGS += -O3
release: $(TARGET)

.PHONY: debug
debug: CXXFLAGS += -Og -g -DDEBUG
debug: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS) $(MAKEFILE)
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(RMFLAGS) *.o $(TARGET)

