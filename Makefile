
objects = main.o complex.o mathematics.o algorithms.o combinatorics.o primes.o
executable = FTkL
compiler = g++

all: $(objects)
	$(compiler) -o $(executable) $(objects)

main.o: main.cpp complex.hpp mathematics.hpp algorithms.hpp combinatorics.hpp primes.hpp
	$(compiler) -c main.cpp

complex.o: complex.cpp
	$(compiler) -c complex.cpp

mathematics.o: mathematics.cpp algorithms.hpp
	$(compiler) -c mathematics.cpp

algorithms.o: algorithms.cpp 
	$(compiler) -c algorithms.cpp

combinatorics.o: combinatorics.cpp
	$(compiler) -c combinatorics.cpp

primes.o: primes.cpp
	$(compiler) -c primes.cpp

clean:
	rm $(objects)