CC = gcc
CFLAGS = -g -Wall -Werror -std=c99 -m64

page: page.c
	$(CC) $(CFLAGS) -o page page.c

test: page
	./page -f test.txt -m 16 -n 12

clean:
	rm -rf *.o
