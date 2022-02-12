CC=gcc
CPPFLAGS=
CFLAGS=-Wall -Wextra -pedantic -std=c99 -g
LDFLAGS=
LDLIBS=
EXEC= prog

SRC= base/graph.c queue/queue.c dfs/dfs.c bfs/bfs.c main.c
SRC2= 
OBJ= ${SRC:.c=.o}
OBJ2= ${SRC2:.c=.o}

all: ${EXEC}

${EXEC}: ${OBJ}

prog:${OBJ}
	${CC} $^ -o prog


clean:
	${RM} prog
	${RM} *.o
	${RM} bfs/*.o
	${RM} dfs/*.o
	${RM} queue/*.o
	${RM} base/*.o
