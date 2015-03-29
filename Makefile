CC = gcc
OBJS = main.o vm.o lexer.o parser.o
CFLAGS = -g -pedantic -Wall

.PHONY: main clean

main: bf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bf: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@


clean:
	rm -rf *.o

