all: randomfile.o
	gcc randomfile.o

run:
	./a.out

randomfile.o:
	gcc -c randomfile.c
