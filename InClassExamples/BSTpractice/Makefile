Driver.out: BinarySearchTree.h Driver.o
	g++ -ansi -Wall BinarySearchTree.h Driver.o -o Driver.out

#BinarySearchTree.o: BinarySearchTree.h
#	g++ -ansi -Wall -c BinarySearchTree.h

Driver.o: Driver.cpp
	g++ -ansi -Wall -c Driver.cpp

clean:
	rm -f *.o *.out *~ *.gch

run:
	./Driver.out