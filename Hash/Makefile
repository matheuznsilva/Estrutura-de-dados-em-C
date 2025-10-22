main:	main.o	hash.o	ListaDinEncad.o	arquivo.o
	gcc main.o hash.o ListaDinEncad.o arquivo.o -o main

main.o:	main.c
	gcc -c main.c

hash.o:	hash.c	hash.h
	gcc -c hash.c

ListaDinEncad.o:	ListaDinEncad.c	ListaDinEncad.h
	gcc -c ListaDinEncad.c

arquivo.o:	arquivo.c	arquivo.h
	gcc -c arquivo.c

clean:
	rm *.o
