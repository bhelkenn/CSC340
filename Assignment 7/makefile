CC=g++
CFLAGS=-c -Wall -std=c++0x
LINKS=main.o budget.o account.o envelope.o budget_item.o menu.o budget_application.o budget_envelope.o envelope_box.o

all: driver

driver: $(LINKS)
	$(CC) $(LINKS) -o driver

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
menu.o: menu.cpp menu.h
	$(CC) $(CFLAGS) menu.cpp
budget_application.o: budget_application.cpp budget_application.h
	$(CC) $(CFLAGS) budget_application.cpp
budget_envelope.o: budget_envelope.cpp budget_envelope.h
	$(CC) $(CFLAGS) budget_envelope.cpp
envelope_box.o: envelope_box.cpp envelope_box.h
	$(CC) $(CFLAGS) envelope_box.cpp
clean:
	rm *.o driver