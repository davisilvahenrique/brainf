# Brainfuck Compiler & Executor (bfc + bfe)

Este projeto consiste em dois programas em C:

- `bfc`: um compilador Brainfuck que transforma uma expressão com texto e uma conta matemática simples em código Brainfuck.
- `bfe`: um interpretador Brainfuck que executa o código gerado e imprime o resultado.

## Exemplo de uso

```bash
echo "CRÉDITO=2*5+10" | ./bfc | ./bfe
```

## Compilação

```bash
make
```

## Requisitos

- Compilador C (ex: gcc)
- Ambiente Linux (ou compatível com POSIX)