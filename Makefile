CC = gcc
FLAGS = -Wall -g

all: main

main: main.o libMyBank.a
	${CC} ${FLAGS} main.o libMyBank.a -o main

main.o: main.c 
	${CC} -c -fPIC main.c -o main.o -I.

libMyBank.a: myBank.o myBank.h
	ar -rcs libMyBank.a myBank.o

myBank.o: myBank.c myBank.h
	${CC} -c -fPIC myBank.c -o myBank.o

clean:
	rm -f *.txt *.o *.a *.so main

.PHONY:  all main