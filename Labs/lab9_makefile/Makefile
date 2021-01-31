PROJ        = output.out
CXX         = g++
CXXFLAGS    = -g -Wall -std=c++11
OBJS        = driver.o Lecturer.o

$(PROJ): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# method 1: using pattern subsitution

%.o : %.cpp %.h
		$(CXX) $(CXXFLAGS) -c $<

# method 2: does not use pattern subsitution

	# Lecturer.o: Lecturer.cpp Lecturer.h
	# 	$(CXX) $(CXXFLAGS) -c $<
	# driver.o: driver.cpp Lecturer.h
	# 	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean run valgrind finish
clean:
	rm $(OBJS)
	rm $(PROJ)
run: $(PROJ)
	./$(PROJ) $(PARAM)
valgrind: $(PROJ)
	valgrind ./$(PROJ) $(PARAM)
finish: clean
	rm -f lab9_makefile2.zip
	zip -r lab9_makefile2.zip ./*
