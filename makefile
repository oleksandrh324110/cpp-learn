cc = c++
cflags = -std=c++11 -Os

%: src/%.cpp
	$(cc) $(cflags) -o bin/$@.exe $<