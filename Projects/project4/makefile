CXX = g++
CXXFLAGS = -g -ansi -Wall -std=c++11
OBJECTS = Heap.o PinHit.o



all: Driver

Driver: Driver.cpp $(OBJECTS) MaxHeap.h
	$(CXX) $(CXXFLAGS) -o driver.out $< $(OBJECTS)

PinHit.o: PinHit.cpp PinHit.h
	$(CXX) $(CXXFLAGS) -c $<

Heap.o: Heap.cpp Heap.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o
	rm -f *.out

run:
	./driver.out $(FILE) $(TYPE)

valgrind:
	valgrind ./driver.out $(FILE) $(TYPE)
