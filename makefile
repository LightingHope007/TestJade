compile: main.cpp
	 g++ main.cpp Player.cpp NODE.cpp LL.cpp Minigame.cpp -o start


run: start
	 ./start


clean: start
	 rm start