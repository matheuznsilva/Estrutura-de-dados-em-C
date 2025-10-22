main:	main.o	Stack.o
	gcc main.o Stack.c.o -o main

main.o:	main.c
	gcc -c main.c

Stack.c.o:	Stack.c.c	Stack.c.h
	gcc -c Stack.c.c

clean:
	rm *.o

run:
	./main
