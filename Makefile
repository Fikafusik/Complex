
objects = main.o complex.o
executable = complex_test
compiler = g++

all: $(objects)
	$(compiler) -o $(executable) $(objects)

main.o: main.cpp complex.hpp complex.cpp
	$(compiler) -c main.cpp

complex.o: complex.hpp complex.cpp
	$(compiler) -c complex.cpp

clean:
	rm $(objects)