build:
	g++ -Wall -std=c++17 -I"./libs/" src/*.cpp `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua-5.4 -o gameengine;

run:
	./gameengine

clean:
	rm gameengine