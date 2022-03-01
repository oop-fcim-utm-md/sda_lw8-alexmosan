all: a.out

a.out:
	g++ -std=c++17 header.cpp main.cpp

test: a.out
	./a.out

clean:
	rm a.out