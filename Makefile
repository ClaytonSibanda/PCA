#make file for my assignment 2
FLAGS=  -g -std=c++11
CC=g++


pca:pca.o main.o
	$(CC) $(FLAGS) -o $@ $^

main.o:main.cpp pca.cpp pca.h
	$(CC) $(FLAGS) -c $^

pca.o:pca.cpp pca.h
	$(CC) $(FLAGS) -c $^
run:
	./pca

test:
	 $(CC) $(FLAGS) -Wall -o tests tests.cpp imageops.cpp imageops.h


run_test:
	./tests

clean:
	rm -f *.o *.exe pca
