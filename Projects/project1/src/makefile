all: driver

clean:
	rm -rf *.o
	rm -f *.out

valgrind:
	valgrind ./Driver.out

driver: driver.o Llama.o
	g++ -o Driver.out driver.o Llama.o

Llama.o: Llama.cpp Llama.h LlamaNode.h
	g++ -c -Wall Llama.cpp

driver.o: driver.cpp Llama.h
	g++ -c -Wall driver.cpp
