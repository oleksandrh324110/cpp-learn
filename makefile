ifeq ($(OS), Windows_NT) 
	CXX := g++
	CXXFLAGS :=
	LDFLAGS :=
else ifeq ($(shell uname), Darwin)
	CXX := clang++
	CXXFLAGS :=
	LDFLAGS :=
endif

SRCS = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all: compile link run

compile: $(OBJS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

link:
	$(CXX) $(OBJS) -o bin/main.exe $(LDFLAGS)

run:
	bin/main.exe

clean:
	rm $(OBJS)
