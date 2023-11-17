CC = clang++
CFLAGS = -std=c++17 -Os
LDFLAGS = 

SRCS = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp)
OBJS  = $(SRCS:.cpp=.o)
BIN = bin

all: dirs link run

dirs:
	mkdir -p $(BIN)

run:
	$(BIN)/main

link: $(OBJS)
	$(CC) -o $(BIN)/main $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(cflags)