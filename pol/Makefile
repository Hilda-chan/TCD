CC=gcc
CPPFLAGS=
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c99 -Isrc/add/ -Isrc/mul/ -Isrc/sub/
EXEC= prog

SRC= stack.c pol.c
OBJ= ${SRC:.c=.o}

all: ${EXEC}

${EXEC}: ${OBJ}

	${CC} ${CFLAGS} -O2 -DNDBUG -o $@ $^

clean:
	rm -f prog
	rm -f test-suite
	rm -f src/prog.o
	rm -f src/add/add.o src/mul/mul.o src/sub/sub.o
	rm -f tests/testfile.o

