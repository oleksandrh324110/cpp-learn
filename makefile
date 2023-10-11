cc = clang++
cflags = -std=c++17 -o main.exe -Os -Xlinker -unexported_symbol -Xlinker "*"

main:
	$(cc) $(cflags) src/main.cpp

homework:
	$(cc) $(cflags) src/homework.cpp