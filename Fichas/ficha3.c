#include <stdio.h>
#include <stdlib.h>

// Exercício 1
/*
// a)
Output:
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12

// b)
Output:
13
*/

void dumpV (int v[], int N) {
    int i;
    for (i = 0; i< N; i++)
        printf("%d ", v[i]);
    putchar ('\n');
}

// Exercício 2
void swapM (int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

// Exercício 3
void swap (int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Exercício 4
int soma (int v[], int N) {
    int i, resultado = 0;

    for (i = 0; i < N; i++)
        resultado += v[i];

    return resultado;
}

// Exercício 5
void inverteArray1 (int v[], int N) {
    int i, j;

    for (i = 0, j = N-1; i < j; i++, j--) {
        swap(v,i,j);
    }
}

void inverteArray2 (int v[], int N) {
    int i, j;

    for (i = 0, j = N-1; i < j; i++, j--) {
        swapM(&v[i],&v[j]);
    }
}

// Exercício 6
int maximum (int v[], int N, int *m) {
    int i;

    if (N <= 0)
        return 1;

    else {
        *m = v[0];

        for (i = 0; i < N; i++) {
            if(v[i] > *m)
                *m = v[i];
        }

    return 0;
    }
}

// Exercício 7
void quadrados (int v[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        v[i] = i*i;
    }
}

