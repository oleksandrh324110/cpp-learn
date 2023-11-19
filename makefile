CC = clang++
CFLAGS = -std=c++11 -O0
LDFLAGS =

SRCS = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp)
OBJS  = $(SRCS:.cpp=.o)

all: compile link run

compile: $(OBJS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

link:
	$(CC) $(OBJS) -o bin/main $(LDFLAGS)

run:
	bin/main

clean:
	rm $(OBJS)