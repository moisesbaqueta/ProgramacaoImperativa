#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof (struct nodo));
    if (a != NULL) {
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = N/2;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;
}

// Numero de nodos de uma arvore
int nNodos (ABin a) {
    int r = 0;

    if (a) {
        int nEsq = nNodos (a->esq);
        int nDir = nNodos (a->dir);
        r = 1 + nEsq + nDir;
    }
    return r;
}

// Exercício 1

// a) Altura de uma arvore
int altura (ABin a) {
    int r = 0;

    if (a) {
        int aEsq = altura(a->esq);
        int aDir = altura(a->dir);
        int max = aEsq;

        if (aDir > max)
            max = aDir;

        r = 1 + max;
    }
    return r;
}

// b) Numero de folhas
int nFolhas (ABin a) {
    int r = 0;

    if (a) {
        if (!(a->esq) && !(a->dir)) { // É uma folha
            r = 1;
        } else {
            int nEsq = nFolhas (a->esq);
            int nDir = nFolhas (a->dir);
            r = nEsq + nDir;
        }
    }
    return r;
}

// c) Elemento mais a esquerda (Versão Recursiva)
ABin maisEsquerda (ABin a) {
    ABin r = NULL;

    if (a) {
        if (!(a->esq)) r = a;
        else r = maisEsquerda (a->esq);
    }
    return r;
}

// Elemento mais a esquerda (Versão Iterativa)
ABin maisEsquerda_it (ABin a) {
    ABin r = NULL;

    if (a) {
        ABin aux = a;
        for (; aux->esq; aux = aux->esq);
        r = aux;
    }
    return r;
}

// d) Imprime o nivel l da arvore
void imprimeNivel (ABin a, int l) {
    if (a) {
        if (l == 0)
            printf ("%d ", a->valor);
        else {
            imprimeNivel (a->esq, l-1);
            imprimeNivel (a->dir, l-1);
        }
    }
}

// e) Testa se o elemento x se encontra na arvore
int procuraE (ABin a, int x) {
    int r = 0; // falso, x nao ocorre em a

    if (a) {
        if (x == a->valor)
            r = 1; // verdadeiro
        else
            r = procuraE (a->esq, x) || procuraE (a->dir, x); // se encontrar no primeiro nao faz no segundo
    }
    return r;
}

// Exercício 2

// f) Procura o elemento x na arvore de PROCURA (ordenada)
struct nodo *procura (ABin a, int x) {
    struct nodo *r = NULL;

    if (a) {
        if (x == a->valor)
            r = a;
        else if (x < a->valor)
            r = procura (a->esq, x);
        else // x > a->valor
            r = procura (a->dir, x);
    }
    return r;
}

// g) Procura o nivel que o elemento x se encontra na arvore
int nivel (ABin a, int x) {
    int r = -1; // x nao ocorre
    int nivelSub; // nivel da sub-arvore

    if (a) {
        if (x == a->valor)
            r = 0;
        else if (x < a->valor)
            nivelSub = nivel (a->esq, x);
        else
            nivelSub = nivel (a->dir , x);

        if (nivelSub != -1)
            r = nivelSub + 1; // devido a começar -1
    }
    return r;
}

// h) Imprime a arvore ate ao elemento x
void imprimeAte (ABin a, int x) {
    if (a) {
        imprimeAte (a->esq, x);
        if (x > a->valor) {
            printf ("%d ", a->valor);
            imprimeAte (a->dir, x);
        }
    }
}
