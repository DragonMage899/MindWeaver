#add all the files that you need to the files makefile variable below as a space seperated list


main: main.cpp glad.c
	g++ -g $(files) main.cpp glad.c -Iglad/include -lglfw3 -pthread -lGLEW -ldl -lGL -o main


window: window.cpp glad.c
	g++ -g $(files) window.cpp glad.c -Iglad/include -lglfw3 -pthread -lGLEW -ldl -lGL -o window

clean:
	rm -f *.o main

run:
	./main

all:
	make clean
	make
	make run