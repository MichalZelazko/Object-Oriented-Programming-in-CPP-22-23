# List your *.h files (if you do not have them in your project then leave the variable "headers" empty):
headers = Polygon.h Point.h

# List your *.cpp files:
sources = TestPolygon.cpp Polygon.cpp Point.cpp

# Specify name of your program:
executable = Polygon

$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
