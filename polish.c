#include "graph.h"

void polish_notation(struct stack *operations, char *input_str, char *output_str) {
    int point = 0;
    for (int i = 0; input_str[i] != '\0'; i++) {
        if (input_str[i] == ')') {
            while ((operations->ch) != '(') output_str[point++] = trash(&operations);
            trash(&operations);  // remove the bracket
        }
        if ((input_str[i] >= '0' && input_str[i] <= '9') || input_str[i] == 'x')
            output_str[point++] = input_str[i];  // transfer numbers and variable "x" to Polish notation

        if (input_str[i] == 's' && input_str[i + 1] == 'i' && input_str[i + 2] == 'n') {
            if (operations == NULL) {
                operations = funcs(operations, 's');
            } else if (priority(operations->ch) < priority('s'))
                operations = funcs(operations, 's');
            else {
                while ((operations != NULL) && (priority(operations->ch) >= priority('s')))
                    output_str[point++] = trash(&operations);
                operations = funcs(operations, 's');
            }
            i += 3;
        }
        if (input_str[i] == 'c' && input_str[i + 1] == 'o' && input_str[i + 2] == 's') {
            if (operations == NULL)
                operations = funcs(operations, 'c');
            else if (priority(operations->ch) < priority('c'))
                operations = funcs(operations, 'c');
            else {
                while ((operations != NULL) && (priority(operations->ch) >= priority('c')))
                    output_str[point++] = trash(&operations);
                operations = funcs(operations, 'c');
            }
            i += 3;
        }
        if (input_str[i] == 't' && input_str[i + 1] == 'a' && input_str[i + 2] == 'n') {
            if (operations == NULL)
                operations = funcs(operations, 't');
            else if (priority(operations->ch) < priority('t'))
                operations = funcs(operations, 't');
            else {
                while ((operations != NULL) && (priority(operations->ch) >= priority('t')))
                    output_str[point++] = trash(&operations);
                operations = funcs(operations, 't');
            }
            i += 3;
        }
        if (input_str[i] == 'c' && input_str[i + 1] == 't' && input_str[i + 2] == 'g') {
            if (operations == NULL)
                operations = funcs(operations, 'g');
            else if (priority(operations->ch) < priority('g'))
                operations = funcs(operations, 'g');
            else {
                while ((operations != NULL) && (priority(operations->ch) >= priority('g')))
                    output_str[point++] = trash(&operations);
                operations = funcs(operations, 'g');
            }
            i += 3;
        }
        if (input_str[i] == 's' && input_str[i + 1] == 'q' && input_str[i + 2] == 'r' &&
            input_str[i + 3] == 't') {
            if (operations == NULL)
                operations = funcs(operations, 'q');
            else if (priority(operations->ch) < priority('q'))
                operations = funcs(operations, 'q');
            else {
                while ((operations != NULL) && (priority(operations->ch) >= priority('q')))
                    output_str[point++] = trash(&operations);
                operations = funcs(operations, 'q');
            }
            i += 4;
        }
        if (input_str[i] == 'l' && input_str[i + 1] == 'n') {
            if (operations == NULL)
                operations = funcs(operations, 'l');
            else if (priority(operations->ch) < priority('l'))
                operations = funcs(operations, 'l');
            else {
                while ((operations != NULL) && (priority(operations->ch) >= priority('l')))
                    output_str[point++] = trash(&operations);
                operations = funcs(operations, 'l');
            }
            i += 2;
        }
        if (input_str[i] == '(') operations = funcs(operations, '(');
        if (input_str[i] == '+' || input_str[i] == '-' || input_str[i] == '/' || input_str[i] == '*') {
            if (operations == NULL)
                operations = funcs(operations, input_str[i]);
            else if (priority(operations->ch) < priority(input_str[i]))
                operations = funcs(operations, input_str[i]);
            else {
                while ((operations != NULL) && (priority(operations->ch) >= priority(input_str[i])))
                    output_str[point++] = trash(&operations);  // priority check
                operations = funcs(operations, input_str[i]);
            }
        }
    }

    while (operations != NULL) output_str[point++] = trash(&operations);  // all output here
    output_str[point] = '\0';
}

char trash(struct stack **head) {
    struct stack *upper;
    char symbol;
    if (*head == NULL) return '\0';
    upper = *head;       // assign a pointer to the beginning of the stack
    symbol = upper->ch;  // add input symbol to variable
    *head = upper->next;
    free(upper);
    return symbol;
}

struct stack *funcs(struct stack *head, char symbol) {
    struct stack *pt;
    if ((pt = malloc(sizeof(struct stack))) == NULL) {
        puts("Unable to allocate memory");
        exit(-1);
    }
    pt->ch = symbol;
    pt->next = head;
    return pt;
}

int priority(char symbol) {
    int priority_flag = 0;
    switch (symbol) {
        case 'c':
        case 's':
        case 't':
        case 'g':
        case 'q':
        case 'l':
            priority_flag = 4;
            break;
        case '*':
        case '/':
            priority_flag = 3;
            break;
        case '-':
        case '+':
            priority_flag = 2;
            break;
        case '(':
            priority_flag = 1;
            break;
    }
    return priority_flag;
}

int check_input(char *input_string) {
    char *p = input_string;
    int i = 0;
    while (p[i]) {
        char oper;
        int count;

        if (p[i] == '(') {
            oper = '(';
            count = 1;
        } else if (p[i] == ')') {
            oper = ')';
            count = 1;
        } else if (p[i] == 's' && p[i + 1] == 'i' && p[i + 2] == 'n') {
            oper = 'S';
            count = 3;
        } else if (p[i] == 'c' && p[i + 1] == 'o' && p[i + 2] == 's') {
            oper = 'C';
            count = 3;
        } else if (p[i] == 't' && p[i + 1] == 'a' && p[i + 2] == 'n') {
            oper = 'T';
            count = 3;
        } else if (p[i] == 'c' && p[i + 1] == 't' && p[i + 2] == 'g') {
            oper = 'Z';
            count = 3;
        } else if (p[i] == 's' && p[i + 1] == 'q' && p[i + 2] == 'r' && p[i + 3] == 't') {
            oper = 'Q';
            count = 4;
        } else if (p[i] == 'l' && p[i + 1] == 'n') {
            oper = 'L';
            count = 2;
        } else if (p[i] == '*') {
            oper = '*';
            count = 1;
        } else if (p[i] == '/') {
            oper = '/';
            count = 1;
        } else if (p[i] == '+') {
            oper = '+';
            count = 1;
        } else if (p[i] == '-') {
            oper = '-';
            count = 1;
        } else if (p[i] == 'x') {
            oper = 'x';
            count = 1;
        } else {
            oper = '0';
        }

        if (oper != '0') {
            i += count;
        } else {
            if (p[i] < '0' || p[i] > '9') return 0;
            i++;
        }
    }
    return 1;
}