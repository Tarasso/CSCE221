FLAGS = -Wall


all: Driver.o Student.o
	g++ $(FLAGS) Driver.o Student.o -o Output.out

Student.o: Student.cpp
	g++ $(FLAGS) -c Student.cpp

Driver.o: Driver.cpp
	g++ $(FLAGS) -c Driver.cpp

run:
	./Output.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
