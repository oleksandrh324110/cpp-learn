CC := c++
CFLAGS := -std=c++17 -O0
LDFLAGS :=

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
	$(CC) $(OBJS) -o bin/main.exe $(LDFLAGS)

run:
	bin/main.exe

clean:
	rm $(OBJS)