cc = clang++
cflags = -std=c++17 -o main.exe -Os

main:
	$(cc) $(cflags) main.cpp

homework:
	$(cc) $(cflags) homework.cpp