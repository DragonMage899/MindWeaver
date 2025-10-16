CC = g++
CFLAGS = -Wall -std=c++11
LIBS = -lGL -lGLEW -lglfw

all: airplane

airplane: main.cpp shader.hpp
	$(CC) $(CFLAGS) -o airplane main.cpp $(LIBS)

clean:
	rm -f airplane