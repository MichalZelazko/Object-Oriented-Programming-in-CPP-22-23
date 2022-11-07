# List your *.h files (if you do not have them in your project then leave the variable "headers" empty):
headers = Vect.h

# List your *.cpp files:
sources = testVect.cpp Vect.cpp

# Specify name of your program:
executable = testVect

$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
