all: driver

driver: Proj2Aux.o AugmentedBinarySearchTree.o driver.cpp
	g++ -o Proj2 -std=c++11 Proj2Aux.o AugmentedBinarySearchTree.o driver.cpp

Proj2Aux.o: Proj2Aux.cpp Proj2Aux.h Exceptions.h AugmentedBinarySearchTree.h
	g++ -c -std=c++11 Proj2Aux.cpp

AugmentedBinarySearchTree.o: AugmentedBinarySearchTree.cpp AugmentedBinarySearchTree.h Exceptions.h
	g++ -c -std=c++11 AugmentedBinarySearchTree.cpp

run:
	./Proj2 $(FILE) $(COMMANDS)

clean:
	rm -rf *.o
	rm -f *.out

valgrind:
	valgrind ./Proj2 $(FILE) $(COMMANDS)
