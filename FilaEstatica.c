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
    fila->inicio = 0;
    fila->tamanho = 0;
    fila->fim = -1;
}

bool estaVazia(FilaEstatica *fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia.\n");
        return true;
    } else {
        return false;
    }
}

bool estaCheia(FilaEstatica *fila) {
    if (fila->tamanho == N) {
        printf("Fila cheia.\n");
        return true;
    } else {
        return false;
    }
}

void enqueue(FilaEstatica *fila, Objeto obj) {
    if (estaCheia(fila) == true) {
        printf("Fila cheia! Remova para inserir.\n");}
    else{
        fila->fim++;
        fila->vetor[fila->fim] = obj;
        fila->tamanho++;
        printf("Empilha: %d\n", obj.chave);
    }
}

Objeto dequeue(FilaEstatica *fila) {
     Objeto aux;
    if (estaVazia(fila) == true) {
        printf("Fila vazia! Insira para remover.\n");}
    else{
        aux = fila->vetor[fila->inicio];
        fila->inicio++;
        fila->tamanho--;
        printf("Desempilha: %d\n", aux.chave);
    }
    return (aux);
}

Objeto inicioFila(FilaEstatica *fila) {
    return (fila->vetor[fila->inicio]);
}

Objeto fimFila(FilaEstatica *fila) {
    return (fila->vetor[fila->fim]);
}

int tamanhoFila(FilaEstatica *fila) {
    return (fila->tamanho);
}

void estadoFila(FilaEstatica *fila){
    printf("Início:%d Fim:%d Tamanho:%d\n", inicioFila(fila).chave, fimFila(fila).chave, tamanhoFila(fila) );
}

void imprimeFila(FilaEstatica *fila) {
    printf("Fila: {");
    int n = tamanhoFila(fila);
    for (int i = 0; i < n; i++) {
        int index = (fila->inicio + i) % N;
        printf("|%d| ", fila->vetor[index].chave);
    }
    printf("}\n");
}

int main(int argc, char** argv) {
    FilaEstatica Fila;
    Objeto obj;
    inicia(&Fila);

    obj.chave = 27;
    enqueue(&Fila, obj);
    obj.chave = 45;
    enqueue(&Fila, obj);
    obj.chave = 8;
    enqueue(&Fila, obj);
    obj.chave = 99;
    enqueue(&Fila, obj);
    obj.chave = 35;
    enqueue(&Fila, obj);
    imprimeFila(&Fila);
    estadoFila(&Fila);
    dequeue(&Fila);
    imprimeFila(&Fila);
    estadoFila(&Fila);
    dequeue(&Fila);
    imprimeFila(&Fila);
    estadoFila(&Fila);
    dequeue(&Fila);
    imprimeFila(&Fila);
    estadoFila(&Fila);
    dequeue(&Fila);
    imprimeFila(&Fila);
    estadoFila(&Fila);
    dequeue(&Fila);
    imprimeFila(&Fila);
    return (EXIT_SUCCESS);
}
