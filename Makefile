CC = g++
CFLAGS = -std=c++11 -Wall -g
EXECUTABLE = numinfo

all: numinfo

numinfo: main.o math.o output.o parse.o
	$(CC) $(CFLAGS) main.o output.o math.o parse.o -o $(EXECUTABLE)

main.o: main.cpp output.h parse.h
	$(CC) $(CFLAGS) -c main.cpp

parse.o: parse.cpp parse.h
	$(CC) $(CFLAGS) -c parse.cpp

output.o: output.cpp output.h math.h
	$(CC) $(CFLAGS) -c output.cpp

math.o: math.cpp math.h
	$(CC) $(CFLAGS) -c math.cpp


clean:
	rm -rf *.o $(EXECUTABLE)
