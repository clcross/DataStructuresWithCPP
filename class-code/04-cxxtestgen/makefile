all: simple-test

simple-test:
	cxxtestgen --error-printer -o test/runner.cpp test/simple-test.cpp
	g++ -o runner test/runner.cpp -I src/
	./runner

clean:
	rm runner test/runner.cpp
