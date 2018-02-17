CC = gcc
AFLAGS = -fno-stack-protector -z execstack -m32
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

guesser2.s: guesser2.c
	$(CC) $(AFLAGS) -S guesser2.c

clean:
	rm -f *.o *.s *.dump guesser guesser2