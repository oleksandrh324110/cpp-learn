OS = $(shell uname -s)

CXX = c++
CXXFLAGS = -std=c++17 -O0
LDFLAGS = 

SRCS = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp)
OBJS  = $(SRCS:.cpp=.o)

ifeq ($(OS), Darwin) 
	CXX = clang++
endif

all: compile link run

compile: $(OBJS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

link:
	$(CXX) $(OBJS) -o bin/main $(LDFLAGS)

run:
	bin/main

clean:
	rm $(OBJS)