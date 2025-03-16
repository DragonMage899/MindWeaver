main: main.cpp glad.c
	g++ -g shader.cpp Shapes2D.cpp main.cpp glad.c -lglfw3 -pthread -lGLEW -ldl -lGL -o main

clean:
	rm -f *.o main

run:
	./main

all:
	make clean
	make
	make run