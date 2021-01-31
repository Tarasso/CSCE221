CXX = g++
CXXFLAGS = -g -ansi -Wall -std=c++11



all: driver

driver: MapExercise.cpp TempData.h
	$(CXX) $(CXXFLAGS) -o run.out $<


clean:
	rm -rf *.o
	rm -f *.out

run:
	./run.out
