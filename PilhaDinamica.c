#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoPilha *PtrNoPilha;

typedef struct NoPilha {
    Objeto topo;
    PtrNoPilha prox;
} NoPilha;

typedef struct {
    PtrNoPilha topo;
    int tamanho;
} PilhaDinamica;

void inicia(PilhaDinamica *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

bool estaVazia(PilhaDinamica *p) {
    if (p->tamanho == 0) {
        return true;
    } else {
        return false;
    }
}

void push(PilhaDinamica *p, Objeto X) {
    PtrNoPilha aux;
    aux = (PtrNoPilha) malloc(sizeof (NoPilha));
    aux->topo.chave = X.chave;
    aux->prox = p->topo;
    p->topo = aux;
    p->tamanho++;
}

void pop(PilhaDinamica *p, Objeto *obj) {
  if(estaVazia(p) == false) {     
    *obj = p->topo->topo;
    PtrNoPilha aux;
    aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    p->tamanho--;
  }
}

int topo(PilhaDinamica *p) {
    int X;
    X = p->topo->topo.chave;
    return (X);
}

int tamanho(PilhaDinamica *p) {
    return (p->tamanho);
}

void imprimePilha(PilhaDinamica *p) {
    PtrNoPilha aux;
    printf("Pilha: \n");
    for (aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("|%d| \n", aux->topo.chave);
    }
}

int main(int argc, char** argv) {
    PilhaDinamica Pilha;
    Objeto obj;
    inicia(&Pilha);

    obj.chave = 1;
    push(&Pilha, obj);
    obj.chave = 2;
    push(&Pilha, obj);
    obj.chave = 3;
    push(&Pilha, obj);
    obj.chave = 4;
    push(&Pilha, obj);
    obj.chave = 5;
    push(&Pilha, obj);
    obj.chave = 6;
    push(&Pilha, obj);
    obj.chave = 7;
    push(&Pilha, obj);
    imprimePilha(&Pilha);
    printf("Tamanho: %d\n", tamanho(&Pilha));
    printf("Topo: %d\n", topo(&Pilha));
    pop(&Pilha, &obj);
    imprimePilha(&Pilha);
    printf("Tamanho: %d\n", tamanho(&Pilha));
    printf("Topo: %d\n", topo(&Pilha));


    return (EXIT_SUCCESS);
}

