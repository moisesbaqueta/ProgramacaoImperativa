#include <stdio.h>
#include <stdlib.h>

// Exercicio 1

// Exercício 1.1
// x = 12 e y = 16
// Output:
// 12 16


// Exercício 1.2
// Vai dar erro, pois y nao tem valor e estamos a tentar imprimi-lo.


// Exercício 1.3
// Output:
// A 65
// B 66 2 50
// 98


// Exercício 1.4
// x = 200 -> y = 100 -> x = 300 -> y = 200 -> x = 100
// Output:
// 100 200


// Exercício 2

// a)
// Output:
// 3 5


// b)
/*
x = 1 e y = 1
x = 2 e y = 3
x = 3 e y = 6
x = 4 e y = 10
x = 5 e y = 15
x = 6 e y = 21
x = 7 e y = 28
x = 8 e y = 36
x = 9 e y = 45
x = 10 e y = 55
x = 11 e y = 66
*/
// Output:
// 11 66


// c)
// Output:
// _#_#_#_#_#_#_#_#_#_#


// d)
// Output:
//
// 1
// 01
// 11
// 001
// 101
// 001
// 111
// 0001
// 1001
// 0101
// 1101
// 0011
// 1011
// 0111
// 1111


// Exercício 3

// Exercício 1

void quadrado (int n) {
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            putchar('#');
        }
    printf("\n");
    }
}


// Exercício 2

void xadrez (int n) {
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if (((i + j) % 2) == 0)
                putchar('#');
            else
                putchar('_');
        }
    printf("\n");
    }
}


// Exercício 3

void trianguloVertical (int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < i + 1; j++) {
            putchar('#');
        }
        printf("\n");
    }

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            putchar('#');
        }
        printf("\n");
    }
}

// Exercício 4
void trianguloHorizontal (int n) {
    int i, j, k;

    for (i = 0; i < n; i++) {

        for (j = n - 1; j > i ; j--) {
            putchar(' ');
        }

        for (k = 1; k < 2 * (i + 1); k++) {
            putchar('#');
        }

        putchar('\n');

    }
}
