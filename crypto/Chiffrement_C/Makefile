CC=gcc
CFLAGS=-Wall -std=c99  
CPPFLAGS =-O2
LDLIBS=


SRC = caesar.c Tools.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

release: main
	${CC} ${OBJ} -lcsfml-graphics -lcsfml-window -o main

main: ${OBJ}

debug: CPPFLAGS = -g -fsanitize=address
debug: LDLIBS = -lasan
debug: main
	${CC} ${CPPFLAGS} ${OBJ} ${LDLIBS} -lcsfml-graphics -lcsfml-window -o main

clean:
	rm -f main
	${RM} ${OBJ}
	${RM} ${DEP}

-include ${DEP}
