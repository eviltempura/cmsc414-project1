CC = gcc
SUDO = sudo
DUMP = objdump
AFLAGS = -fno-stack-protector -z execstack -m32
CFLAGS = -fno-stack-protector -z execstack -m32 -g
DFLAGS = -S --disassemble
EFLAGS = -m32

guesser1.dump: guesser1
	$(DUMP) $(DFLAGS) guesser1 > guesser1.dump

guesser1: guesser1.o
	$(CC) $(EFLAGS) -o guesser1 guesser1.o

guesser1.o: guesser1.c
	$(CC) $(CFLAGS) -c guesser1.c

guesser2.dump: guesser2
	$(DUMP) $(DFLAGS) guesser2 > guesser2.dump

guesser2: guesser2.o
	$(CC) $(EFLAGS) -o guesser2 guesser2.o

guesser2.o: guesser2.c
	$(CC) $(CFLAGS) -c guesser2.c

guesser3.dump: guesser3
	$(DUMP) $(DFLAGS) guesser3 > guesser3.dump

guesser3: guesser3.o
	$(CC) $(EFLAGS) -o guesser3 guesser3.o

guesser3.o: guesser3.c
	$(CC) $(CFLAGS) -c guesser3.c

vuln1: vulnerable1.c
	$(SUDO) $(CC) $(CFLAGS) vulnerable1.c -o vuln1
	$(SUDO) chmod 4755 vuln1

exploit1.dump: exploit1
	$(DUMP) $(DFLAGS) exploit1 > exploit1.dump

exploit1: exploit1.o
	$(CC) $(CFLAGS) -c exploit1.c

exploit1.o: exploit1.c
	$(CC) $(EFLAGS) -o exploit1 exploit1.c

clean:
	rm -f *.o *.dump guesser1 guesser2 guesser3 vuln1 badfile exploit1
