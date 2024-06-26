CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
BUILD=../build/graph

objFile = graph.o polish.o matrix.o calc_matrix.o -o

all: graph

graph: graph.o polish.o matrix.o calc_matrix.o
	$(CC) $(FLAGS) graph.o polish.o matrix.o calc_matrix.o -o $(BUILD)
	$(CC) $(objFile) $(BUILD)

graph.o: graph.c
	$(CC) $(CFLAGS) -c graph.c -o graph.o

polish.o: polish.c
	$(CC) $(CFLAGS) -c polish.c -o polish.o

matrix.o: matrix.c
	$(CC) $(CFLAGS) -c matrix.c -o matrix.o

calc_matrix.o: calc_matrix.c
	$(CC) $(CFLAGS) -c calc_matrix.c -o calc_matrix.o

# main.o: main.c
# 	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f *.o $(BUILD)

rebuild: clean graph