main: main.cpp glad.c
	g++ -g Shapes2D.cpp shader.cpp main.cpp glad.c -lglfw3 -pthread -lGLEW -ldl -lGL -o main

clean:
	rm -f *.o main

run:
	./main

all:
	make clean
	make
	make run