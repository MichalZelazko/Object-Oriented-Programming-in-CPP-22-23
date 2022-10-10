# List your *.h files (if you do not have them in your project then leave the variable "headers" empty):
headers = Stack.h

# List your *.cpp files:
sources = TestStack.cpp Stack.cpp

# Specify name of your program:
executable = Stack

$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(executable)
