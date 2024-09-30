#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// 1 - Maior elemento da sequência
void one () {
    int n = 1, n_max = 0;

    while(1) {
        printf("Introduza um numero (0 para terminar): ");
        scanf("%d", &n);

        if (n == 0)
            break;

        if(n > n_max)
            n_max = n;
    }

    printf("O maior numero = %d\n", n_max);
}

// 2 - Media da sequência
void two () {
    int n, i = 0;
    float soma = 0.0, media;

    while(1) {
        printf("Introduza um numero (0 para terminar): ");
        scanf("%d", &n);

        if (n == 0)
            break;

        soma += n;
        i++;
    }

    media = soma / i;

    printf("A media = %.2f\n", media);
}

// 3 - Segundo maior elemento de uma sequência
void three () {
    int n, n_max1 = 0, n_max2 = 0;

    while (1) {
        printf("Introduza um numero (0 para terminar): ");
        scanf("%d", &n);

        if (n == 0)
            break;

        if (n > n_max1) {
            n_max2 = n_max1;
            n_max1 = n;
        } else if (n > n_max2) {
            n_max2 = n;
        }
    }

    printf("O segundo maior valor = %d\n", n_max2);
}

// 4 - Calcula o numero de bits iguais a 1 de um numero
int bitsUm (unsigned int n) {
    int uns;

    uns = 0;

    while(n > 0) {
        if (n % 2 == 1)
            uns++;
        n /= 2;
    }

    return uns;
}

//  5 - Calcula o numero de bits iguais a 0 de um numero
int trailingZ (unsigned int n) {
    int zeros;

    zeros = 0;

    while(n > 0) {
        if (n % 2 == 0)
            zeros++;
        n /= 2;
    }

    return zeros;
}

// 6 - Retorna o numero de digitos que um numero tem
int qDig (unsigned int n) {
    int digitos = 0;

    while (n > 1) {
        n = n / 10;
        digitos++;
    }

    return digitos;
}

// 7 - Concatena duas strings
char *mystrcat (char s1[], char s2[]){
    char newstr[strlen(s1) + strlen(s2)];
    int i, j;

    for (i = 0; i < strlen(s1); i++){
        newstr[i] = s1[i];
    }

    for (j = 0; j < strlen(s2); j++){
        newstr[i + j] = s2[j];
    }

    newstr[strlen(s1) + strlen(s2)] = '\0';

    printf("%s\n", newstr);

    return s1;
}

// 8 - Copia uma string para outra
char *mystrcpy (char s1[], const char s2[]) {
    int i;

    for(i = 0; s2[i]; i++)
        s1[i] = s2[i];

    s1[i] = '\0';

    return s1;
}

// 9 -
int mystrcmp(char s1[], char s2[]) {
    int i = 0, p, q;

    while(s1[i] == s2[i] && s1[i])
        i++;

    p = s1[i];
    q = s2[i];

    return p - q;
}

// 10 -
char *mystrstr (char s1[], char s2[]) {
    if (*s1 == '\0' && *s2 == '\0')
        return s1;

    if (*s1 == '\n' && *s2 == '\n')
        return s1;

    for (; *s1; *s1++) {
        if (*s1 == *s2) {
            char *r = s1;
            char *p = s2;
            while (*s1 == *p && *s1) {
                p++;
                s1++;
            }

            if (*p == '\0')
                return r;
        }
    }

    return NULL;
}

// 11 - Inverter uma string
void mystrrev(char s[]) {
    int i, j = strlen(s) - 1;
    char newstr[strlen(s)];

    for (i = 0; i < strlen(s); i++) {
        newstr[i] = s[j];
        j--;
    }

    newstr[i] = '\0';

    printf("%s\n", newstr);
}

// 12 - Retirar todas as vogais de uma string
void strnoV (char s[]) {
    int i = 0, j = 0;
    char newstr[strlen(s)];

    while (s[i]) {
        if (s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U')
            i++;
        else {
            newstr[j] = s[i];
            i++;
            j++;
        }
    }

    newstr[j] = '\0';

    printf("%s\n", newstr);
}

// 13 - Delimita o numero de caracteres de cada palavra
void truncW (char t[], int n) {
    int i = 0,
        j = 0,
        contador = 0;

    for (i = 0; t[i]; i++) {
        if  (t[i] == " ") {
            contador = 0;
            t[j] = t[i];
            j++;
        } else {
            if (contador < n) {
                t[j] = t[i];
                j++;
                contador++;
            }
        }
    }
    t[j] = '\0';

    printf("%s\n", t);
}

// 14 - Conta o caracter mais frequente
char charMaisfreq (char s[]) {
    int i, j, count, maior = 0;
    char maisFreq = s[i];

    for (i = 0; s[i]; i++) {
        count = 1;
        for (j = 0; s[j]; j++) {
            if (s[i] == s[j])
                count++;
        }
        if (count > maior) {
            maior = count;
            maisFreq = s[i];
        }
    }
    printf("%c", maisFreq);

    return maisFreq;
}

// 15 - Conta a maior sequencia de caracteres iguais consecutivos
int iguaisConsecutivos (char s[]) {
    int i = 0, count = 1, maior = 0;

    while (s[i]) {
        while (s[i] == s[i + 1]){
            count++;
            i++;
        }
        if(count >= maior)
            maior = count;
        count = 1;
        i++;
    }
    return maior;
}

// 16 - Conta a maior sequencia de caracteres diferentes
int difConsecutivos (char s[]) {
    int i = 0, count = 1, maior = 0;

    while (s[i]) {
        count = 1;
        while (s[i] != s[i + 1]){
            count++;
            i++;
        }
        if(count > maior)
            maior = count;
        i++;
    }
    return maior;
}

// 17 - Calcula o comprimento do maior prefixo em comum entre duas strings
int maiorPrefixo (char s1[], char s2[]) {
    int i, count = 0;

    for(i=0; s1[i]; i++){
        if(s1[i] == s2[i])
            count++;
        else
            return count;
    }

    return count;
}

// 18 - Calcula o comprimento do maior sufixo em comum entre duas strings
int maiorSufixo (char s1[], char s2[]) {
    int i = strlen(s1) - 1,
        j = strlen(s2) - 1,
        count = 0;

    for (; i >= 0; i--, j--) {
        if (s1[i] == s2[j])
            count++;
        else
            return count;
    }
    return count;
}

// 19 - Calcula o tamanho do maior sufixo de s1 que é um prefixo de s2.
int sufPref(char s1[], char s2[]){
    int count = 0, j = 0, i;

    for(i = 0; s1[i]; i++){
        if(s1[i] == s2[j]){
            count++;
            j++;
        } else {
            count = 0;
            j = 0;
        }
    }
    return count;
}

// 20 - Conta as palavras de uma string
int contaPal(char s[]){
    int count = 0, i = 0;

    while(i<strlen(s)){
        if(!(isspace(s[i])) && s[i] != '\0'){
            count++;
            i++;
        }
        while(!(isspace(s[i]))){
            i++;
        }
        while(isspace(s[i])){
            i++;
        }
    }
    return count;
}

// 21 - Conta as vogais de uma string
int contaVogais (char s[]) {
    int i = 0, count = 0;

    while (s[i]) {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
            count++;
            i++;
    }
    return count;
}

// 22 - Testa se todos os caracteres da primeira string estão contidos na segunda
// FUNÇÃO AUXILIAR
int verificaSePertence (char x, char s[]){
    int i, r = 0;

    for(i=0; s[i]; i++){
        if(x == s[i])
            r = 1;
    }

    return r; // r = 1 se pertencer e r = 0 se NAO pertencer
}

int contida (char a[], char b[]) {
    int i = 0, r = 0;

    for(i=0; a[i]; i++){
        if (verificaSePertence (a[i],b) == 0){
            r = 0;
            break;
        } else
            r = 1;
    }

    return r;
}

// 23 - Testa se uma palavra é palíndrome
int palindrome (char s[]) {
    int i = 0,
        j = strlen(s) - 1,
        r = 1;

    while (i < strlen(s)/2) {
        if (s[i] != s[j]) {
            r = 0;
            break;
        } else {
            i++;
            j--;
        }
    }

    return r;
}

// 24 - Remove os caracteres que se repetem sucessivamente
// Constroi uma nova string (MANEIRA TESTADA NO MAIN)
int remRep1 (char x[]) {
    int i = 0, j = 0, count = 0;
    char newstr[strlen(x)];

    while (x[i]) {
        if (x[i] != x[i+1]) {
            newstr[j] = x[i];
            i++;
            j++;
            count++;
        } else
            i++;
    }

    newstr[j+1] = '\0';

    printf("%s\n", newstr);

    return count;
}

// Altera no array (100% dos testes no CODEBOARD)
int remRep(char s[]){
    int i, j;

    for(i=0; s[i]; i++){
        if(s[i] == s[i+1]){
            for(j=i+1; s[j]; j++)
                s[j] = s[j+1];
            i--;
        }
    }

    return i;
}

// 25 - Remove os espaços repetidos sucessivamente (TESTADA NO MAIN) (NAO FUNCIONA NO CODEBOARD)
int limpaEspacos (char s[]) {
    int i = 0, j = 0, comp = 0;
    char newstr[strlen(s)];

    while (s[i]) {
        if (s[i] == ' ' && s[i+1] == ' ') {
            i++;
        } else {
            newstr[j] = s[i];
            i++;
            j++;
        }
    }

    newstr[j+1] = '\0';
    comp = strlen(newstr);

    printf ("%s\n", newstr);

    return comp;
}

// 26 - Insere um elemento (x) num array ordenado
void insere (int v[], int N, int x) {
    int i, j;

    for (i = 0; v[i]; i++) {
        if (v[i] > x) {
            for (j = N; j > i; j--) {
                v[j] = v[j-1];
            }
            v[i] = x;

            break;
        }
        if (i = N - 1) {
            v[N] = x;
        }
    }
}

// 27 - Preenche o array r[] com os arrays a[] e b[]
void merge (int r[], int a[], int b[], int na, int nb) {
    int ir, ia, ib;

    for (ir = 0, ia = 0, ib = 0; ia < na && ib < nb; ir++) {
        if (a[ia] <= b[ib]) {
            r[ir] = a[ia];
            ia++;
        } else {
            r[ir] = b[ib];
            ib++;
        }
    }

    for (; ia < na; ir++, ia++) // Caso (a[]) ainda tenha elementos
        r[ir] = a[ia];

    for (; ib < nb; ir++, ib++) // Caso (b[]) ainda tenha elementos
        r[ir] = b[ib];
}


// 28 - Testa se um array esta ordenado por ordem crescente
int crescente (int a[], int i, int j) {
    int r = 1; // Verdadeiro

    while (i < j) {
        if (a[i] > a[i+1])
            r = 0; // Falso
            break;
        i++;
    }
    return r;
}

// 29 - Retira o numero de numeros negativos de um array
int retiraNeg (int v[], int N) {
    int i = 0, j;

    while (i < N) {
        if (v[i] < 0) {
            for (j = i; j < N-1; j++)
                v[j] = v[j+1];
            N--;
        } else
            i++;
    }
    return N;
}

// 30 - Indica o elemento menos frequente
int contaRepetidos_30 (int numero, int v[], int N) {
    int i = 0, count = 0;

    while (i < N) {
        if (numero == v[i])
            count++;
        i++;
    }

    return count;
}

int menosFreq (int v[], int N) {
    int i = 0,
        r = v[i],
        menor = contaRepetidos_30 (v[i], v, N);

    while (i < N) {
        int x = contaRepetidos_30 (v[i], v, N);

        if (x < menor) {
            menor = x;
            r = v[i];
        }

        i ++;
    }

    return r;
}

// 31 - Indicica o elemento mais frequente
int contaRepetidos_31 (int numero, int v[], int N) {
    int i = 0, count = 0;

    while (i < N) {
        if (numero == v[i])
            count++;
        i++;
    }

    return count;
}

int maisFreq (int v[], int N) {
    int i = 0,
        r = v[0],
        maior = contaRepetidos_31 (v[0], v, N);

    while (i < N) {
        int x = contaRepetidos_31 (v[i], v, N);

        if (x > maior) {
            maior = x;
            r = v[i];
        }

        i ++;
    }

    return r;
}

// 32 - Calcula o comprimento da maior sequencia crescente de elementos consecutivos
int maxCresc (int v[], int N) {
    int i = 0, count = 1, r = 0;

    while (i < N) {
        if (v[i] <= v[i+1]) {
            count++;
        } else {
            if (count > r)
                r = count;
            count = 1;
        }
        i++;
    }

    return r;
}

// 33
int pertence(int v[], int x, int N){
    int i = 0;
    int r = -1;		// se repetir apenas 1 vez vai ficar 1, senão vai ficar > 1

    while (i < N) {
        if (v[i] == x) {
            r++;
            i++;
        } else {
            i++;
        }
    }

    if(r>=1)
        return 1;
    else
        return 0;
}

int elimRep(int v[], int N){
    int i, j;

    for (i = 0; i < N; i++) {
        while (pertence(v, v[i], N) == 1) {
            j = i + 1;
            while (j < N) {
                if (v[j] == v[i]) {
                    while (j < N){
                        v[j] = v[j+1];
                        j++;
                    }
                } else {
                    j++;
                }
            }
            N--;
        }
    }
    return N;
}

// 34 - Elimina os elementos repetidos de um array ordenado
int elimRepOrd (int v[], int n) {
    int i = 0, j;

    while (i < n-1) {
        if (v[i] == v[i+1]) {
            for (j = i; j < n; j++)
                v[j] = v[j+1];
            n--;
        } else
            i++;
    }
    return n;
}

// 35 - Calcula os elementos em comum entre dois arrays ordenados
int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0, j = 0, count = 0;

    while (i < na && j < nb) {
        if (a[i] == b[j]) {
            count++;
            i++;
            j++;
        } else {
            if (a[i] < b[j])
                i++;
            else
                j++;
        }
    }
    return count;
}

// 36 - Calcula os elementos em comum entre dois arrays
int verificaSeExiste (int numero, int v[], int N) {
    int i = 0, r = 0;

    while (i < N) {
        if (numero == v[i])
            r = 1;
        i++;
    }

    return r;
}

int comuns (int a[], int na, int b[], int nb) {
    int i = 0, count = 0;

    while (i < na) {
        if (verificaSeExiste(a[i], b, nb))
            count++;
        i++;
    }

    return count;
}

// 37 - Indica a posição do menor elemento do array
int minInd (int v[], int n) {
    int i, indice = 0;

    for (i = 0; i < n; i++) {
        if (v[i] <= v[indice])
            indice = i;
    }

    return indice;
}

// 38 - Preenche o array Ac com as somas ate aquela posição do array v
int somasAcAux (int v[], int indice) {
    int i, r = 0;

    for (i = 0; i <= indice; i++)
        r += v[i];

    return r;
}

void somasAc (int v[], int Ac[], int N) {
    int i;

    for (i = 0; i < N; i++)
        Ac[i] = somasAcAux(v, i);
}

// 39 - Testa se uma matriz quadrada é triangular superior
int triSup (int N, float m[N][N]) {
    int i, j, r = 1;

    for (i = 1; i < N; i++) {
        for (j = 0; j < i; j++) {
            if (m[i][j] != 0) {
                r = 0;
                break;
            }
        }
    }

    return r;
}

// 40 - Transforma uma matriz na sua transposta
void transposta (int N, float m[N][N]) {
    int i, j,
        m_aux[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m_aux[j][i] = m[i][j];
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = m_aux[i][j];
        }
    }
}

// 41 - Soma duas matrizes
void addTo (int N, int M, int a[N][M], int b[N][M]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}



typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

// 47
Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        switch (mov[i]) {
            case Norte:
                inicial.y++;
                break;
            case Oeste:
                inicial.x--;
                break;
            case Sul:
                inicial.y--;
                break;
            case Este:
                inicial.x++;
                break;
        }
    }

    return inicial;
}

// 48
int caminho(Posicao inicial, Posicao final, Movimento mov[], int N){
    int i, r = 0;

    for (i = 0; i < N && (inicial.x != final.x || inicial.y != final.y); i++){
        if (inicial.x > final.x) {
            mov[i] = Oeste;
            inicial.x--;
            r++;
        } else if (inicial.x < final.x) {
            mov[i] = Este;
            inicial.x++;
            r++;
        } else if (inicial.y > final.y) {
            mov[i] = Sul;
            inicial.y--;
            r++;
        } else if (inicial.y < final.y) {
            mov[i] = Norte;
            inicial.y++;
            r++;
        }
    }

    if (inicial.x != final.x || inicial.y != final.y)
        r = -1;

    return r;
}

// 49
float hipotenusa (int x, int y) {
    float hipotenusa;

    hipotenusa = sqrt(x*x + y*y);

    return hipotenusa;
}

int maiscentral(Posicao pos[], int N){
    int i=0, menor = 0;
    float hip;

    hip = hipotenusa (pos[i].x , pos[i].y);

    for (i = 1; i < N; i++) {
        if (hipotenusa(pos[i].x , pos[i].y) < hip) {
            menor = i;
            hip = hipotenusa(pos[i].x , pos[i].y);
        }
    }

    return menor;
}

// 50
int vizinhos (Posicao p, Posicao pos[], int N) {
    int i, count = 0;

    for (i=0; i<N; i++) {
        if (sqrt(pow((p.x - pos[i].x),2) + pow((p.y- pos[i].y),2)) == 1)
            count++;
    }
    return count;
}

