#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

typedef struct {
    int chave;
} Objeto;

typedef struct {
    Objeto vetor[N];
    int inicio;
    int fim;
    int tamanho;
} FilaEstatica;

void inicia(FilaEstatica *fila) {
    fila->fim = -1;
    fila->tamanho = 0;
    fila->inicio = -1;
}

bool estaVazia(FilaEstatica *fila) {
    if (fila->tamanho == 0) {
        return true;
    } else {
        return false;
    }
}

bool estaCheia(FilaEstatica *fila) {
    if (fila->tamanho == N) {
        return true;
    } else {
        return false;
    }
}

void enqueue(FilaEstatica *fila, Objeto X) {
    if (estaCheia(fila) == false) {
        fila->fim++;
        fila->vetor[fila->fim] = X;
        fila->tamanho++;
    }
}

Objeto dequeue(FilaEstatica *fila) {
    if (estaVazia(fila) == false) {
        Objeto aux;
        aux = fila->vetor[fila->inicio];
        fila->inicio++;
        fila->tamanho--;
        return (aux);
    }
}

Objeto inicio(FilaEstatica *fila) {
    Objeto X;
    X = fila->vetor[fila->inicio];
    return (X);
}

Objeto fim(FilaEstatica *fila) {
    Objeto X;
    X = fila->vetor[fila->fim];
    return (X);
}

int tamanho(FilaEstatica *fila) {
    return (fila->tamanho);
}

void imprimeFila(FilaEstatica *fila) {
    printf("Fila: ");
    for (int i = 0; i < fila->tamanho; i++) {
        printf("|%d| ", fila->vetor[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    FilaEstatica Fila;
    Objeto obj;
    inicia(&Fila);

    obj.chave = 27;
    enqueue(&Fila, obj);
    obj.chave = 45;
    enqueue(&Fila, obj);
    obj.chave = 3;
    enqueue(&Fila, obj);
    obj.chave = 82;
    enqueue(&Fila, obj);
    obj.chave = 5;
    enqueue(&Fila, obj);
    obj.chave = 196;
    enqueue(&Fila, obj);
    obj.chave = 38;
    enqueue(&Fila, obj);
    imprimeFila(&Fila);
    printf("Início: %d\n", inicio(&Fila));
    printf("Fim: %d\n", fim(&Fila));
    printf("Tamanho: %d\n", tamanho(&Fila));
    dequeue(&Fila);
    imprimeFila(&Fila);
    printf("Início: %d\n", inicio(&Fila));
    printf("Fim: %d\n", fim(&Fila));
    printf("Tamanho: %d\n", tamanho(&Fila));

    return (EXIT_SUCCESS);
}
