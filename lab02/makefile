all: objs node.o list.o main.o lab02exe

objs:
	rm -rf src/objs; mkdir src/objs
main.o: src/main.cpp src/node.h src/list.h
	g++ -g -Wall -c src/main.cpp -o src/objs/main.o
list.o: src/list.cpp src/list.h src/node.h
	g++ -g -Wall -c src/list.cpp -o src/objs/list.o
node.o: src/node.cpp src/node.h
	g++ -g -Wall -c src/node.cpp -o src/objs/node.o
lab02exe: src/objs/main.o src/objs/node.o src/objs/list.o
	g++ src/objs/main.o src/objs/node.o src/objs/list.o -o lab02exe
run:
	valgrind ./lab02exe
clean:
	rm -rf src/objs/*.o | rm -rf lab02exe | rm -rf src/objs
