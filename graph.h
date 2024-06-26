#ifndef GRAPH_H
#define GRAPH_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define _USE_MATH_DEFINES
#define WIDTH 80
#define HEIGHT 25
#define POINT '.'
#define STAR '*'

typedef struct stack {
    char ch;
    struct stack *next;
} stack;

// BASIC STRUCTURE
void graph_loop();

// POLISH
int check_input(char *input_string);
stack *funcs(stack *, char);
char trash(stack **head);
int priority(char);
void polish_notation(stack *operations, char *input_str, char *output_str);

// CALCULATOR
double calc_value(char *output_str, double x);
int add_func_for_graph(char **graph, int height, int width, char *polish);

// DRAW
char **malloc_matrix(int height, int width);
void init_graph(char **graph, int height, int width);
void draw_graph(char **graph, int height);
void free_matrix(char **graph, int height);

#endif