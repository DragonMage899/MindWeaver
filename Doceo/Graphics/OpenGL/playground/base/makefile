#add all the files that you need to the files makefile variable below as a space seperated list


main: main.cpp glad.c
	g++ -g $(files) main.cpp glad.c -Iglad/include -lglfw -pthread -lGLEW -ldl -lGL -o main


window: window.cpp 
	g++ -g $(files) window.cpp -lglfw -pthread -lGLEW -ldl -lGL -o window

triangle: triangle.cpp
	g++ -g $(files) triangle.cpp shader.cpp -lglfw -pthread -lGLEW -ldl -lGL -o triangle

rectangle: rectangle.cpp
	g++ -g $(files) rectangle.cpp shader.cpp -lglfw -pthread -lGLEW -ldl -lGL -o rectangle

draws: draws.cpp
	g++ -g $(files) draws.cpp shader.cpp -lglfw -pthread -lGLEW -ldl -lGL -o draws

shapes: shapes.cpp
	g++ -g $(files) shapes.cpp shader.cpp -lglfw -pthread -lGLEW -ldl -lGL -o shapes

test: test.cpp
	g++ -g $(files) test.cpp shader.cpp -lglfw -pthread -lGLEW -ldl -lGL -o test

clean:
	rm -f *.o main window triangle rectangle draws test

run:
	./main

all:
	make clean
	make
	make run