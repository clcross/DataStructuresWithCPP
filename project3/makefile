MAIN   = src/main.cpp
SRCS   = $(filter-out $(MAIN),$(wildcard src/*.cpp))
OBJS   = $(SRCS:src/%.cpp=obj/%.o)
CFLAGS = -g -I src/
EXEC   = selfBal-test
.PHONY: clean test all

all: $(SRCS) $(EXEC)

$(EXEC): $(OBJS) $(MAIN)
	g++ $(CFLAGS) $(OBJS) $(MAIN) -o $@

obj/%.o: src/%.cpp src/%.hpp obj
	g++ -c $(CFLAGS) $< -o $@

obj:
	mkdir -p obj

%test:
	cxxtestgen --runner=ErrorPrinter -o test/test-runner.cpp test/$@.cpp ${SRCS}
	g++ ${CFLAGS} test/test-runner.cpp $(SRCS) -o test-runner
	./test-runner

graph:
	gnuplot Splay_better.plot
	gnuplot AVL_better.plot
	ps2pdf Splay_better.ps
	ps2pdf AVL_better.ps
	evince Splay_better.pdf
	evince AVL_better.pdf

clean:
	rm -rf $(EXEC) obj test/test-runner.cpp test-runner
