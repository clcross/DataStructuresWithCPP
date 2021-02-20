#This is a comment
MAIN=src/main.cpp
SRCS := $(filter-out $(MAIN), $(wildcard src/*.cpp))
OBJS := $(SRCS:src/%.cpp=obj/%.o)
CFLAGS = -g -Wall

simple: $(OBJS)
	g++ $(CFLAGS) obj/* -o simple src/main.cpp

obj/%.o: src/%.cpp obj
	g++ -c $(CFLAGS) $< -o $@

obj:
	mkdir obj

%test: $(OBJS)
	cxxtestgen --error-printer -o test/runner.cpp test/$@.cpp
	g++ -o runner test/runner.cpp -I src/ $(OBJS)
	./runner

clean:
	rm -rf simple *.o obj/
