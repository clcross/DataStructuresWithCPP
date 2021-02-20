#This is a comment
simple: simple.o print.o
	g++ -Wall simple.o print.o -o simple

print.o: print.cpp print.hpp
	g++ -Wall print.cpp -c

simple.o: simple.cpp	
	g++ -Wall simple.cpp -c

obj:
	mkdir obj

obj/my-src.o: obj src/my-src.cpp
	g++ -g -Wall -c src/my-src.cpp -o obj/my-src.o
clean:
	rm -rf simple *.o obj/
