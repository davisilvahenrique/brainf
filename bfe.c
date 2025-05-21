#include <stdio.h>
#include <stdlib.h>

#define TAPE_SIZE 30000

int main() {
    char code[65536];
    char tape[TAPE_SIZE] = {0};
    int ptr = 0;
    int pc = 0, len = 0;

    while ((code[len] = getchar()) != EOF && len < 65535) len++;
    code[len] = '\0';

    while (pc < len) {
        switch (code[pc]) {
            case '>': ptr++; break;
            case '<': ptr--; break;
            case '+': tape[ptr]++; break;
            case '-': tape[ptr]--; break;
            case '.': putchar(tape[ptr]); break;
            case ',': tape[ptr] = getchar(); break;
            case '[':
                if (!tape[ptr]) {
                    int loop = 1;
                    while (loop) {
                        pc++;
                        if (code[pc] == '[') loop++;
                        else if (code[pc] == ']') loop--;
                    }
                }
                break;
            case ']':
                if (tape[ptr]) {
                    int loop = 1;
                    while (loop) {
                        pc--;
                        if (code[pc] == '[') loop--;
                        else if (code[pc] == ']') loop++;
                    }
                }
                break;
        }
        pc++;
    }

    return 0;
}
