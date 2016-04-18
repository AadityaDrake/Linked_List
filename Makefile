CFLAGS  = -Wall -std=c11 -g
LIBS = -lm

.PHONY: clean 

all : ll

clean :
	rm -f *.o  *~ ll tst
	rm -rf *.dSYM

ll: ui.o ll.o main.o
	gcc $(CFLAGS) -o ll ui.o ll.o main.o $(LIBS)

test : test.c ui.o ll.o
	gcc $(CFLAGS) -o tst ui.o ll.o test.c

main.o : ui.o ll.o main.c ll.h ui.h
	gcc $(CFLAGS) -c main.c

ui.o : ll.o ui.c ui.h ll.h
	gcc $(CFLAGS) -c ui.c

ll.o : ll.c ll.h
	gcc $(CFLAGS) -c ll.c
