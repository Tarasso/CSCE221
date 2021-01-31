# Bryson Mrosko
# UIN: 928003182
# CSCE 222-518
# 1-15-2020
# An Aggie does not lie, cheat or steal or tolerate those who do.

run: driver

driver: Lecturer.o driver.o
	g++ -Wall driver.o Lecturer.o -o output.out

Lecturer.o : Lecturer.cpp Lecturer.h
	g++ -Wall -c Lecturer.cpp

driver.o: driver.cpp Lecturer.h
	g++ -Wall -c driver.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
