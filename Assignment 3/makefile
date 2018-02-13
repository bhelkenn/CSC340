CC=g++
CFLAGS=-c -Wall -std=c++0x

all: driver

driver: main.o budget.o account.o envelope.o
	$(CC) main.o budget.o account.o envelope.o -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
budget.o: budget.cpp budget.h
	$(CC) $(CFLAGS) budget.cpp
account.o: account.cpp account.h
	$(CC) $(CFLAGS) account.cpp
envelope.o: envelope.cpp envelope.h
	$(CC) $(CFLAGS) envelope.cpp
clean:
	rm *.o driver