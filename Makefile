CC = gcc
CFLAGS = -fno-stack-protector -z execstack -m32 -g
EFLAGS = -m32

guesser: guesser.o
	$(CC) $(EFLAGS) -o guesser guesser.o

guesser.o: guesser.c
	$(CC) $(CFLAGS) -c guesser.c

guesser2: guesser2.o
	$(CC) $(EFLAGS) -o guesser2 guesser2.o

guesser2.o: guesser2.c
	$(CC) $(CFLAGS) -c guesser2.c

clean:
	rm -f *.o guesser guesser2