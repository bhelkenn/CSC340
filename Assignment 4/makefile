CC=g++
CFLAGS=-c -Wall -std=c++0x

all: driver

driver: main.o budget.o account.o envelope.o budget_item.o
	$(CC) main.o budget.o account.o envelope.o budget_item.o -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
budget.o: budget.cpp budget.h
	$(CC) $(CFLAGS) budget.cpp
account.o: account.cpp account.h
	$(CC) $(CFLAGS) account.cpp
envelope.o: envelope.cpp envelope.h
	$(CC) $(CFLAGS) envelope.cpp
budget_item.o: budget_item.cpp budget_item.h
	$(CC) $(CFLAGS) budget_item.cpp
clean:
	rm *.o driver