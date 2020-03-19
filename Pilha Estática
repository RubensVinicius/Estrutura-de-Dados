#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

typedef struct {
    int chave;
} Objeto;

typedef struct {
    Objeto vetor[N];
    int topo;
} PilhaEstatica;

void inicia(PilhaEstatica *p) {
    p->topo = 0;
}

bool estaVazia(PilhaEstatica *p) {
    if (p->topo == 0) {
        return true;
    } else {
        return false;
    }
}

bool estaCheia(PilhaEstatica *p) {
    if (p->topo == N) {
        return true;
    } else {
        return false;
    }
}

void push(PilhaEstatica *p, Objeto X) {
    if(estaCheia(p) == false){
    p->vetor[p->topo].chave = X.chave;
    p->topo++;}
}

int pop(PilhaEstatica *p) {
    if(estaVazia(p) == false){
    Objeto X;
    X.chave = p->vetor[p->topo - 1].chave;
    p->topo--;
    return (X.chave);
}
}

int topo(PilhaEstatica *p) {
    int X;
    X = p->vetor[p->topo - 1].chave;
    return (X);
}

int tamanho(PilhaEstatica *p) {
    return (p->topo);
}

void imprimePilha(PilhaEstatica *p) {
    printf("Pilha:\n");
    for (int i = p->topo - 1; i >= 0; i--) {
        printf("|%d| ", p->vetor[i].chave);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    PilhaEstatica Pilha;
    Objeto objet;
    inicia(&Pilha);
    objet.chave = 2;
    push(&Pilha, objet);
    objet.chave = 3;
    push(&Pilha, objet);
    objet.chave = 4;
    push(&Pilha, objet);
    objet.chave = 5;
    push(&Pilha, objet);
    objet.chave = 6;
    push(&Pilha, objet);
    objet.chave = 7;
    push(&Pilha, objet);
    imprimePilha(&Pilha);
    printf("Tamanho: %d\n", tamanho(&Pilha));
    printf("Topo: %d\n", topo(&Pilha));
    pop(&Pilha);
    imprimePilha(&Pilha);


    return (EXIT_SUCCESS);
}

