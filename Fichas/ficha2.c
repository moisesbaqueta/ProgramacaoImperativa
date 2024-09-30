#include <stdio.h>
#include <stdlib.h>

// Exercício 1
float multInt (int n, float m) {
    int r;

    r = 0;

    while(n > 0){
        r += m;
        n--;
    }

    return r;
}

// Exercício 2
float multInt2 (int n, float m) {
    float r;

    r = 0;

    while(n >= 1){
        if (n % 2 == 0){
            n /= 2;
            m *= 2;
        }else{
            r += m;
            n /= 2;
            m *= 2;
        }
    }
    return r;
}
