compile: main.cpp
	 g++ main.cpp -o start


run: start
	 ./start


clean: start
	 rm start