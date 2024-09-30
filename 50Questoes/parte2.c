#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada * prox;
} *LInt;

// 1 - Comprimento de uma lista ligada
int length (LInt l) {
    int count = 0;

    while (l != NULL) {
        count++;
        l = l->prox;
    }

    return count;
}

// 2 - Liberta o espaço ocupado por uma lista
void freeL (LInt l) {
    LInt list;

    while (l != NULL) {
        list = l->prox;
        free(l);
        l = list;
    }
}

// 3 - Imprime os elementos de uma lista
void imprimeL (LInt l) {

    while (l != NULL) {
        printf ("%d\n", l->valor);
        l = l->prox;
    }
}

// 4 - Inverte uma lista
LInt reverseL(LInt l){
	LInt front, back = NULL;

	while(l) {
		front = l->prox;
		l->prox = back;
		back = l;
		l = front;
	}

	return back;
}

// 5 - Insere um elemento numa lista ordenada
void insertOrd (LInt *l, int x){
    LInt nova;

    nova = malloc(sizeof(struct lligada));
    nova->valor = x;
    nova->prox = NULL;

    while ((*l) != NULL && (*l)->valor < x)
        l = &((*l)->prox);

    nova->prox = (*l);
    (*l) = nova;
}

// 6 - Remove um elemento da lista ordenada
int removeOneOrd (LInt *l, int x) {
    int r = 1; // Erro

    LInt ant;

    for (; (*l) != NULL && (*l)->valor < x; l = &((*l)->prox)) {
        ant = (*l);
    }

        if ((*l) != NULL && (*l)->valor == x) {
            r = 0;
            LInt temp = *l;
            *l = (*l)->prox;
            free(temp);
            ant->prox = *l;
        }

    return r;
}

// 7 - Junta duas listas
void merge (LInt *r, LInt a, LInt b) {

    while (a != NULL || b != NULL) {
        if ((a != NULL && b != NULL && a->valor < b->valor) || b == NULL) {
            *r = a;
            a = a->prox;
        } else {
            *r = b;
            b = b->prox;
        }
        r = &((*r)->prox);
    }
    *r = NULL;
}

// 8 - Parte a lista em dois
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {

    while (l != NULL) {
        if (l->valor < x) {
            *mx = l;
            mx = &((*mx)->prox);
        } else {
            *Mx = l;
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }

    *mx = NULL;
    *Mx = NULL;
}

// 9 - Parte a lista em dois
LInt parteAmeio (LInt *l) {
    int meio = length(*l)/2;
    int i;

    if (meio == 0)
        return NULL;

    LInt y = (*l);
    LInt prev = NULL;

    for (i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;

    return y;
}

// 10 - Remove todas as ocorrencias de um elemento numa lista
int verifica(LInt *l, int x){
	int r = 1;

	while ((*l)->prox != NULL) {
		if ((*l)->valor == x) {
			r = 0;
			break;
		}
	}

	return r;
}

int removeAll (LInt *l, int x){
	LInt aux = *l;
	int count = 0;

	while (verifica(l, x) == 1 ) {
		removeOneOrd(l, x);
		count++;
	}

	return count;
}

// 11 - Remove os valores repetidos de uma lista
int removeDups (LInt *l) {
	int count = 0;

	for (; *l ; l = (&(*l)->prox)) {
		LInt anterior = (*l);
		LInt seguinte = (*l)->prox;
		for (; seguinte ; seguinte = anterior->prox) {
			if (seguinte->valor == (*l)->valor) {
				count += 1;
				anterior->prox = seguinte->prox;
				free(seguinte);
			} else
				anterior = seguinte;
		}
	}

	return count;
}

// 12 - Remove a primeira ocorrencia do maior elemento de uma lista
int maximo_12 (LInt *l) {
    int maior = 0;

    while (*l) {
        if ((*l)->valor > maior)
            maior = (*l)->valor;
        l = &((*l)->prox);
    }

    return maior;
}

int removeMaiorL (LInt *l) {
    int maior = maximo_12(l);

    while ((*l)->valor != maior)
        l = &((*l)->prox);

    LInt temp = (*l)->prox;
    free(*l);
    *l = temp;

    return maior;
}

// 13 - Remove o ultimo elemento de uma lista
void init (LInt *l) {

    while ((*l)->prox != NULL)
        l = &((*l)->prox);

    free(*l);
    *l = NULL;
}

// 14 - Acrescenta um elemnto no fim da lista
void appendL (LInt *l, int x) {
    LInt nova;
    nova = malloc(sizeof(struct lligada));
    nova->valor = x;
    nova->prox = NULL;

    while ((*l) != NULL)
        l = &((*l)->prox);

    (*l) = nova;
}

// 15 - Acrescenta a lista b à lista a
void concatL (LInt *a, LInt b) {

    while (*a)
        a = &((*a)->prox);

    (*a) = b;
}

// 16 - Cria uma nova lista com os mesmos elementos da lista passada como argumento
LInt cloneL (LInt l) {
    LInt new_list;
    LInt *sitio;

    sitio = &new_list;

    while (l) {
        *sitio = malloc(sizeof(struct lligada));
        (*sitio)->valor = l->valor;
        l = l->prox;
        sitio = &((*sitio)->prox);
    }

    *sitio = NULL;

    return new_list;
}

// 17 - Cria uma nova lista com os mesmos elementos da lista passada como argumento por ordem reversa
LInt cloneRev (LInt l) {
    LInt new = NULL, list = NULL;

    for (; l; l = l->prox) {
        new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
    }

    return list;
}

// 18 - Calcula o maior elemento de uma lista
int maximo (LInt l) {
    int maior = 0;

    while (l) {
        if (l->valor > maior)
            maior = l->valor;
        l = l->prox;
    }

    return maior;
}


// 19 - Apaga os elementos de uma lista a partir do n-esimo elemento
int take (int n, LInt *l) {
    int i = 0;

    while (*l && i < n) {
        l = &((*l)->prox);
        i++;
    }

    while (*l) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }

    return i;
}

// 20 - Apaga os n primiros elementos de uma lista
int drop (int n, LInt *l) {
    int i;

    while (*l && i < n) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
        i++;
    }

    return i;
}

// 21 -
LInt NForward (LInt l, int N) {

    while (l && N > 0) {
        l = l->prox;
        N--;
    }

    return l;
}

// 22 - Preenche um array com elementos da lista
int listToArray (LInt l, int v[], int N) {
    int i;

    for (i = 0; i < N && l; i++, l = l->prox) {
        v[i] = l->valor;
    }

    return i;
}

// 23 - Preenche uma lista com elementos de um array
LInt arrayToList (int v[], int N) {
    LInt l;
    LInt *r = &l;
    int i;

    for (i = 0; i < N; i++) {
        *r = malloc(sizeof(struct lligada));
        (*r)->valor = v[i];
        r = &((*r)->prox);
    }

    *r = NULL;

    return l;
}

// 24 - Constroi uma nova lista com as somas acumuladas em cada posição da lista original
LInt somasAcL (LInt l) {
    LInt new_list;
    LInt *r = &new_list;
    int acc = 0;

    for (; l; l = l->prox) {
        acc += l->valor;
        *r = malloc(sizeof(struct lligada));
        (*r)->valor = acc;
        r = &(*r)->prox;
    }

    *r = NULL;

    return new_list;
}

// 25 - Remove de uma lista os valores repetidos
void remreps (LInt l) {

    for (; l; l = l->prox) {
        LInt *c = &(l->prox);

        while (*c && (*c)->valor == l->valor) {
            LInt temp = (*c)->prox;
            free(*c);
            *c = temp;
        }
    }
}

// 26 - Coloca o primeiro elemento de uma lista no fim da lista
LInt rotateL (LInt l) {

    if (l == NULL || l->prox == NULL)
        return l;

    LInt aux = l;
    LInt head = l->prox;

    while (aux->prox)
        aux = aux->prox;

    aux->prox = l;
    l->prox = NULL;

    return head;
}

// 27
LInt parte (LInt l) {
    LInt new_list;
    LInt *r = &new_list;
    LInt *h = &l;

    int i;

    for (i = 1; *h; i++) {
        if (i % 2 == 0) {
            *r = malloc(sizeof(struct lligada));
            (*r)->valor = (*h)->valor;
            r = &((*r)->prox);
            LInt temp = (*h)->prox;
            free(*h);
            (*h) = temp;
        } else {
            h = &((*h)->prox);
        }
    }

    *r = NULL;
    return new_list;
}



typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;


// 28 - Calcula a altura de uma arvore binaria
int maximo (int a, int b) {
    int r;

    if (a > b)
        r = a;
    else
        r = b;

    return r;
}

int altura (ABin a) {
    int r = 0;

    if (!a)
        r = 0;
    else
        if (altura(a->esq) > altura(a->dir))
            r = 1 + altura(a->esq);
        else
            r = 1 + altura(a->dir);

        //r = 1 + maximo(altura(a->esq), altura(a->dir));

    return r;
}



// 29 - Cria uma copia de uma arvore
ABin cloneAB (ABin a) {
    ABin r;

    if (!a) {
        r = NULL;
    } else {
        r = malloc(sizeof(struct nodo));
        r->valor = a->valor;
        r->esq = cloneAB(a->esq);
        r->dir = cloneAB(a->dir);
    }

    return r;
}

// 30 - Inverte uma arvore
void mirror (ABin *a) {
    if (*a) {
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&(*a)->esq);
        mirror(&(*a)->dir);
    }
}

// 31 - Cria uma lista atraves de uma travessia INORDER de uma arvore binaria
void inorder (ABin a, LInt *l) {
    if (!a) {
        *l = NULL;
    } else {
        inorder(a->esq, l);

        while (*l)
            l = &(*l)->prox;

        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        inorder(a->dir, &(*l)->prox);
    }
}

// 32 - Cria uma lista atraves de uma travessia PREORDER de uma arvore binaria
void preorder (ABin a, LInt *l) {
    if (!a) {
        *l = NULL;
    } else {
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;

        preorder(a->esq, &((*l)->prox));

        while (*l)
            l = &(*l)->prox;

        preorder(a->dir, l);
    }
}

// 33 - Cria uma lista atraves de uma travessia POSORDER de uma arvore binaria
void posorder (ABin a, LInt *l) {
	if(a){
		posorder(a->esq, l);
		while(*l)
			l = &(*l)->prox;

		posorder(a->dir, l);
		while(*l)
			l = &(*l)->prox;

		*l = malloc(sizeof(struct nodo));
		(*l)->valor = a->valor;

		(*l)->prox = NULL;
	} else
		*l = NULL;
}

// 34
int min(int a, int b){
	int r = a;

	if (a < b)
		r = a;
	else
		r = b;

	return r;
}

int depth(ABin a, int x){
	int e, d;

	if (a == NULL)
		return -1;

	if (a->valor == x)
		return 1;

	e = depth(a->esq, x);
	d = depth(a->dir, x);

	if (e == -1 && d == -1)
		return -1;

	if (e == -1)
		return (1 + d);

	if (d == -1)
		return (1 + e);

	return (1 + min(e,d));
}

// 35 - Liberta o espaço ocupado por uma arvore
int freeAB(ABin a) {
    int r;

    if (a) {
        r = 1 + freeAB(a->esq) + freeAB(a->dir);
        free(a);
    } else {
        r = 0;
    }

    return r;
}

// 36 - Remove todos os elementos da arvore a partir da profundidade l
int pruneAB (ABin *a, int l) {
    int r = 0;

    if (*a == NULL) {
        return r;
    } else {
        if (l == 0) {
            r += 1 + pruneAB(&(*a)->esq, l) + pruneAB(&(*a)->dir, l);
            free(*a);
            *a = NULL;
        } else {
            r += pruneAB(&(*a)->esq, l-1);
            r += pruneAB(&(*a)->dir, l-1);
        }
    }

    return r;
}

// 37 - Testa se duas arvores são iguais
int iguaisAB (ABin a, ABin b) {
    if (!a && b || a && !b)
        return 0; // Falso

    if (!a && !b || a == b)
        return 1; // Verdade

    return a->valor == b->valor && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
}

// 38 - Constroi uma lista com os elementos que estão no nivel n da arvore
LInt concat (LInt a, LInt b) {
    if (!a)
        return b;

    LInt temp = a;
    while (temp->prox)
        temp = temp->prox;

    temp->prox = b;

    return a;
}

LInt nivelL (ABin a, int n) {
    LInt list;

    if (!a || n < 1) {
        return NULL;
    } else {
        if (n == 1) {
            list = malloc(sizeof(struct lligada));
            list->valor = a->valor;
            list->prox = NULL;
            return list;
        } else {
            return concat(nivelL(a->esq, n-1), nivelL(a->dir, n-1));
        }
    }
}

// 39 - Preenche um array com os elementos que estão no nivel n da arvore
int nivelV (ABin a, int n, int v[]) {
    int e, d;

    if (!a || n < 1)
        return 0;

    if (n == 1) {
        *v = a->valor;
        return 1;
    }  else {
        e = nivelV(a->esq, n-1, v);
        d = nivelV(a->dir, n-1, v+e);
        return e + d;
    }
}

// 40 - Preenche um array com os elementos da arvore atraves de uma travessia INORDER
int dumpAbin (ABin a, int v[], int N) {

    if (!a || N < 0)
        return 0;

    int e = dumoAbin(a->esq, v, N);

    if (e < N) {
        *(v+e) = a->valor;
        return e + dumpAbin(a->dir, v + e + 1, N - e - 1) + 1;
    } else {
        return N;
    }
}

// 41 -
ABin somasAcA (ABin a) {
    ABin newABin;

    if (!a)
        return NULL;

    newABin = malloc(sizeof(struct nodo));
    newABin->esq = somasAcA(a->esq);
    newABin->dir = somasAcA(a->dir);
    newABin->valor = a->valor + (newABin->esq ? newABin->esq->valor : 0) + (newABin->dir ? newABin->dir->valor : 0);
}

// 42 - Conta o numero de nodos que são folhas (ou seja, ligados a NULL)
int contaFolhas (ABin a) {
    int r = 0;

    if (a) {
        if (a->esq == NULL && a->dir == NULL) // É uma folha
            return 1;
        else
            r = contaFolhas(a->esq) + contaFolhas(a->dir);
    }

    return r;
}

// 43 - Cria uma arvore nova que seja espelho da arvore passada
ABin cloneMirror (ABin a) {
    ABin newABin;

    if (!a)
        return NULL;

    newABin = malloc(sizeof(struct nodo));
    newABin->valor = a->valor;
    newABin->esq = cloneMirror(a->esq);
    newABin->dir = cloneMirror(a->dir);

    return newABin;
}

// 44 - Adiciona um elemento a uma arvore binaria de procura
int addOrd (ABin *a, int x) {
    int r = 0;

    while (*a && r != 1) {
        if (x < (*a)->valor)
            a = &((*a)->esq);
        else if (x > (*a)->valor)
            a = &((*a)->dir);
        else
            r = 1;
    }

    if (r != 1) {
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
    }

    return r;
}

// 45 - Testa se um elemento pertence à arvore binaria de procura
int lookupAB (ABin a, int x) {
    int r = 0; // Não pertence

    while (a && r != 1) {
        if (x < a->valor)
            a = a->esq;
        else if (x > a->valor)
            a = a->dir;
        else
            r = 1;
    }

    return r;
}

// 46 - Calcula o nivel onde um elemento se encontra na arvore binaria de procura
int depthOrd (ABin a, int x) {
    int nivel = 1;

    while (a) {
        if (x < a->valor) {
            a = a->esq;
            nivel++;
        } else if (x > a->valor) {
            a = a->dir;
            nivel++;
        } else {
            return nivel;
        }
    }

    return -1;
}

// 47 - Calcula o maior elemento de uma arvore binaria de procura
int maiorAB (ABin a) {
    int r;

    while (a) {
        r = a->valor;
        a = a->dir;
    }

    return r;
}

// 48 - Remove o maior elemento de uma arvore binaria de procura
void removeMaiorA (ABin *a) {

    while (*a && (*a)->dir)
        a = &((*a)->dir);

    ABin temp = (*a)->esq;
    free(*a);
    (*a) = temp;
}

// 49 - Calcula o numero de elementos da arvore que são maiores que x
int quantosMaiores (ABin a, int x) {
    int r = 0;

    if (a == NULL)
        return 0;

    if (a->valor > x)
        return r = 1 + quantosMaiores(a->dir, x) + quantosMaiores(a->esq, x);

    else
        return r = quantosMaiores(a->dir, x);
}

// 50 - Constroi uma arvore binaria de procura atraves de uma lista ligada ordenada
void listToBTree (LInt l, ABin *a) {
    while (l) {
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = l->valor;
        (*a)->esq = NULL;
        a = &((*a)->dir);
        l = l->prox;
    }

    *a = NULL;
}

// 51 - Testa se uma arvore é de procura
int maximo (ABin a) {
    if (!a)
        return -1;

    if ((!(a->esq) && !(a->dir)) || (!(a->dir)))
        return a->valor;

    if (!(a->esq))
        return maximo(a->dir);

    else
        return maximo(a->dir);
}

int minimo (ABin a) {
    if (!a)
        return -1;

    if ((!(a->esq) && !(a->dir)) || (!(a->esq)))
        return a->valor;

    if (!(a->dir))
        return minimo(a->esq);

    else
        return minimo(a->esq);
}

int deProcura (ABin a) {
    if (!a)
        return 1;

    if (!(a->esq) && !(a->dir))
        return 1;

    if (!(a->esq))
        return (deProcura(a->dir) && (a->valor < minimo(a->dir)));

    if (!(a->dir))
        return (deProcura(a->esq) && (a->valor > maximo(a->esq)));

    if (((a->valor) < (a->dir->valor) && (a->valor) > (a->esq->valor)) && (maximo(a->esq) < a->valor) && (minimo(a->dir) > a->valor)) {
        if (deProcura(a->esq) == 1)
            return deProcura(a->dir);
        else
            return 0;
    }

    else return 0;
}
