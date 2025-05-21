#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_bf_char(unsigned char c) {
    printf("[-]");
    for (int i = 0; i < c; i++) printf("+");
    printf(".");
}

void print_bf_string(const char *str) {
    while (*str) {
        unsigned char c = *str;
        if ((c & 0xC0) == 0xC0) {
            unsigned char c1 = *str++;
            unsigned char c2 = *str++;
            print_bf_char(c1);
            print_bf_char(c2);
        } else {
            print_bf_char(*str++);
        }
    }
}

int eval_expr(const char *expr) {
    int result = 0, current = 0;
    char op = 0;

    while (*expr) {
        if (isdigit(*expr)) {
            current = current * 10 + (*expr - '0');
        } else if (strchr("+-*/", *expr)) {
            if (!op)
                result = current;
            else {
                switch (op) {
                    case '+': result += current; break;
                    case '-': result -= current; break;
                    case '*': result *= current; break;
                    case '/': result /= current; break;
                }
            }
            op = *expr;
            current = 0;
        }
        expr++;
    }

    if (op) {
        switch (op) {
            case '+': result += current; break;
            case '-': result -= current; break;
            case '*': result *= current; break;
            case '/': result /= current; break;
        }
    } else {
        result = current;
    }

    return result;
}

void print_bf_number(int num) {
    char buf[20];
    sprintf(buf, "%d", num);
    for (int i = 0; buf[i]; i++) {
        print_bf_char(buf[i]);
    }
}

int main() {
    char input[1024];
    fgets(input, sizeof(input), stdin);

    // encontra o '='
    char *eq = strchr(input, '=');
    if (!eq) return 1;

    *eq = '\0';
    char *prefix = input;
    char *expr = eq + 1;

    char *nl = strchr(expr, '\n');
    if (nl) *nl = '\0';

    print_bf_string(prefix);
    print_bf_char('=');
    int value = eval_expr(expr);
    print_bf_number(value);

    return 0;
}