cc = c++
cflags = -std=c++11 -Os -o main.exe
sources = src/main.cpp

main:
	$(cc) $(cflags) $(sources)