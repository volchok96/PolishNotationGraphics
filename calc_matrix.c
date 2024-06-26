#include "graph.h"

double calc_value(char *output_str, double x) {
    int n = strlen(output_str);
    double num1;
    double num2;
    double operations[50] = {};
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        if (output_str[i] == 'x') {
            operations[ptr] = x;
            ptr++;
        } else if (output_str[i] >= '0' && output_str[i] <= '9') {
            operations[ptr] = output_str[i] - '0';
            ptr++;
        } else if (output_str[i] == '+') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 + num2;
            ptr++;
        } else if (output_str[i] == '-') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 - num2;
            ptr++;
        } else if (output_str[i] == '*') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            ptr -= 2;
            operations[ptr] = num1 * num2;
            ptr++;
        } else if (output_str[i] == '/') {
            num2 = operations[ptr - 1];
            num1 = operations[ptr - 2];
            if (num2 != 0) {
                ptr -= 2;
                operations[ptr] = num1 / num2;
                ptr++;
            } else {
                operations[ptr] = 22222;
                return operations[ptr];
            }
        } else if (output_str[i] == 's') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = sin(num1);
        } else if (output_str[i] == 'c') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = cos(num1);
        } else if (output_str[i] == 't') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = tan(num1);
        } else if (output_str[i] == 'g') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = 1 / tan(num1);
        } else if (output_str[i] == 'q') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = sqrt(num1);
        } else if (output_str[i] == 'l') {
            num1 = operations[ptr - 1];
            operations[ptr - 1] = log(num1);
        }
    }
    ptr--;
    return operations[ptr];
}

int add_func_for_graph(char **graph, int height, int width, char *polish) {
    double y_s, x_s;
    y_s = 2.0 / (height - 1);
    x_s = 4.0 * M_PI / (width - 1);
    for (int x = 0; x < width; x++) {
        if (calc_value(polish, x_s * x) != 22222) {
            double y_res = calc_value(polish, x_s * x);
            int y = round(y_res / y_s) + 12;
            if (y > -1 && y < height) graph[y][x] = STAR;
        } else {
            return 0;
        }
    }
    return 1;
}