###############################################
# Makefile for Game Engine Project
###############################################

CC = g++
LANG_STD = -std=c++17
LDFLAGS = `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua-5.4
COMPILTER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = -I"./libs/"
SRC_FILES =  ./src/*.cpp ./src/**/*.cpp
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua-5.4
OBJ_NAME = gameengine

###############################################
# Makefile rules
###############################################
build:
	$(CC) $(COMPILTER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME);

run:
	./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)