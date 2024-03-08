default-target: all
.PHONY: default-target

ifndef target
$(error target is NOT defined)
endif

CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic
CXXFLAGS +=
LDFLAGS = -lm

ifeq ($(target), linux)
	CXX = g++
	CXXFLAGS +=
	LDFLAGS +=
else ifeq ($(target), darwin)
	CXX = clang++
	CXXFLAGS +=
	LDFLAGS +=
endif

SRC := $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp)
OBJ := $(SRC:.cpp=.o)

.PHONY: all clean

all: compile link run

compile: $(OBJ)
	
%.o: %.c
	$(CXX) -o $@ -c $< $(CXXFLAGS)

link:
	$(CXX) -o ./bin/main.exe $(OBJ) $(LDFLAGS)

run:
	./bin/main.exe