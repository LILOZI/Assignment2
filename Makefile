CC = gcc
AR = ar

OBJ_KNAPSACK = my_Knapsack.o
OBJ_GRAPH = my_graph.o
OBJ_MAT = my_mat.o

FLAGS = -Wall -g

all: my_graph my_Knapsack

my_mat.a: $(OBJ_MAT)
	$(AR) -rcs $@ $<

my_graph: $(OBJ_GRAPH) my_mat.a
	$(CC) $(FLAGS) -o $@ $^

my_Knapsack: $(OBJ_KNAPSACK) my_mat.a
	$(CC) $(FLAGS) -o $@ $^

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c $<

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c $< 

my_Knapsack.o: my_Knapsack.c my_mat.h
	$(CC) $(FLAGS) -c $<

clean:
	rm *.o *.a my_graph my_Knapsack

PHONY: clean all
