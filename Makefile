CC = g++
CFLAGS = -std=c++11 -Wall -g
EXECUTABLE = numinfo

all: numinfo

numinfo: main.o math.o
	$(CC) $(CFLAGS) main.o math.o -o $(EXECUTABLE)

main.o: main.cpp math.h
	$(CC) $(CFLAGS) -c main.cpp

math.o: math.cpp math.h
	$(CC) $(CFLAGS) -c math.cpp

clean:
	rm -rf *.o $(EXECUTABLE)
