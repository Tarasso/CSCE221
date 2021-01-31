all: Driver.o LinkedList.o
	g++ -Wall Driver.o LinkedList.o -o output.out

LinkedList.o: LinkedList.cpp
	g++ -Wall LinkedList.cpp -c

Driver.o: Driver.cpp
	g++ -Wall Driver.cpp -c

run:
	./output.out

val:
	valgrind --leak-check=full ./output.out
