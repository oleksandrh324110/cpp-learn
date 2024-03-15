default-target: all
.PHONY: default-target

ifndef target
$(error target is NOT defined)
endif

CXXFLAGS = -std=c++17 -O0 -Wall -Wextra -Wpedantic -MMD -MP
CXXFLAGS +=
LDFLAGS =

ifeq ($(target), linux)
	CXX = g++
	CXXFLAGS +=
	LDFLAGS +=
else ifeq ($(target), darwin)
	CXX = clang++
	CXXFLAGS +=
	LDFLAGS +=
endif

SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

.PHONY: all clean

all: compile link run

compile: $(OBJ)
	
%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

link:
	$(CXX) -o ./bin/main.exe $(OBJ) $(LDFLAGS)

run:
	./bin/main.exe

clean:
	rm $(OBJ) $(DEP)

-include $(DEP)