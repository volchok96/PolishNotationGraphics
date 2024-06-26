#include "graph.h"

char **malloc_matrix(int height, int width) {
    char **matrix;
    matrix = (char **)malloc(height * sizeof(char *));
    for (int y = 0; y < height; y++) matrix[y] = (char *)malloc(width * sizeof(char));
    return matrix;
}

void init_graph(char **matrix, int height, int width) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            matrix[y][x] = POINT;
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        matrix[y][width + 1] = '\0';
    }
}

void draw_graph(char **matrix, int height) {
    for (int y = 0; y < height; y++) {
        printf("%s\n", matrix[y]);
    }
}

void free_matrix(char **matrix, int height) {
    for (int y = 0; y < height; y++) free(matrix[y]);
    free(matrix);
}