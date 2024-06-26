#include "graph.h"

int main() {
    graph_loop();
    return 0;
}

void graph_loop() {
    char **graph = malloc_matrix(HEIGHT, WIDTH + 1);
    struct stack *operations = NULL;
    char input_formula[100], polish_formula[100];
    do {
        system("clear");
        printf("Enter the formula: ");
        for (int i = 0; i < 100; i++) {
            char symbol = getchar();
            if (symbol == '\n') {
                input_formula[i] = '\0';
                break;
            }
            if (symbol != ' ')
                input_formula[i] = symbol;
            else
                i--;
        }
    } while (!check_input(input_formula));
    polish_notation(operations, input_formula, polish_formula);
    printf("Formula in Polish notation: %s\n", polish_formula);

    init_graph(graph, HEIGHT, WIDTH);
    if (add_func_for_graph(graph, HEIGHT, WIDTH, polish_formula)) {
        draw_graph(graph, HEIGHT);  // put stars to graph
    } else {
        printf("ERROR");
    }
    free_matrix(graph, HEIGHT);
}