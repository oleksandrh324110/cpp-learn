<<<<<<< HEAD
OS = $(shell uname -s)

CXX = c++
CXXFLAGS = -std=c++17 -O0
LDFLAGS = 
=======
CC := c++
CFLAGS := -std=c++17 -O0
LDFLAGS :=
>>>>>>> 1da12e04b4962129f63c127720ff5fb46bcfd97b

SRCS = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp)
OBJS = $(SRCS:.cpp=.o)

ifeq ($(OS), Darwin) 
	CXX = clang++
endif

all: compile link run

compile: $(OBJS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

link:
<<<<<<< HEAD
	$(CXX) $(OBJS) -o bin/main $(LDFLAGS)
=======
	$(CC) $(OBJS) -o bin/main.exe $(LDFLAGS)
>>>>>>> 1da12e04b4962129f63c127720ff5fb46bcfd97b

run:
	bin/main.exe

clean:
	rm $(OBJS)