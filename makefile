compile: main.cpp
	 g++ gamefn.cpp LL.cpp main.cpp -o start


run: start
	 ./start


clean: start
	 rm start