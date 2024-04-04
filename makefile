default-target: test
.PHONY: default-target

ifndef target
$(error target is NOT defined)
endif

CXXFLAGS = -std=c++17 -O0 -Wall -Wextra -Wpedantic -Wno-parentheses -MMD -MP
CXXFLAGS += -Ilibs/googletest/googletest/include
LDFLAGS = libs/googletest/lib/libgtest.a

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

TEST_SRC = $(shell find src test -name "*.cpp" -not -wholename "src/main.cpp")
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_DEP = $(TEST_SRC:.cpp=.d)

libs:
	cd libs/googletest && cmake . && make

all: compile link run
test: compile_test link_test run_test

compile: $(OBJ)
compile_test: $(TEST_OBJ)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

link:
	$(CXX) -o ./bin/main.exe $(OBJ) $(LDFLAGS)
link_test:
	$(CXX) -o ./bin/test.exe $(TEST_OBJ) $(LDFLAGS)

run:
	./bin/main.exe
run_test:
	./bin/test.exe

clean:
	rm $(OBJ) $(DEP) $(TEST_OBJ) $(TEST_DEP)
.PHONY: clean

-include $(DEP)
-include $(TEST_DEP)