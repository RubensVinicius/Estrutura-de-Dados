#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoFila *PtrNoFila;

typedef struct NoFila {
    Objeto obj;
    PtrNoFila prox;
} NoFila;

typedef struct {
    PtrNoFila inicio;
    PtrNoFila fim;
    int tamanho;
} FilaDinamica;

void inicia(FilaDinamica *fila) {
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
}

bool estaVazia(FilaDinamica *fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia.\n");
        return true;
    } else {
        return false;
    }
}

int tamanhoFila(FilaDinamica *fila) {
    return (fila->tamanho);
}

void enqueue(FilaDinamica *fila, Objeto X) {
    PtrNoFila aux;
    aux = (PtrNoFila) malloc(sizeof (NoFila));
    aux->obj = X;
    if (estaVazia(fila) == true) {
        fila->inicio = fila->fim = aux;
        aux->prox = NULL;
    } else {
        aux->prox = NULL;
        fila->fim->prox = aux;
        fila->fim = fila->fim->prox;
    }
    fila->tamanho++;
    printf("Empilha: %d\n", X);
}

Objeto dequeue(FilaDinamica *fila) {
    if (estaVazia(fila) == true) {
        printf("Fila vazia! Insira para remover.\n");
    } else {
        PtrNoFila aux;
        Objeto X;
        aux = fila->inicio;
        X = aux->obj;
        fila->inicio = fila->inicio->prox;
        free(aux);
        fila->tamanho--;
        printf("Desempilha: %d\n", X);
        return (X);
    }
}

Objeto inicioFila(FilaDinamica *fila) {
    return (fila->inicio->obj);
}

Objeto fimFila(FilaDinamica *fila) {
    return (fila->fim->obj);
}

void estadoFila(FilaDinamica *fila) {
    printf("Início:%d Fim:%d Tamanho:%d\n", inicioFila(fila), fimFila(fila), tamanhoFila(fila));
}

void imprimeFila(FilaDinamica *fila) {
    PtrNoFila aux;
    printf("Fila: ");
    for (aux = fila->inicio; aux != NULL; aux = aux->prox) {
        printf("|%d| ", aux->obj.chave);
    }
    printf("\n");
}

/*void destroiFila(FilaDinamica *fila){
   PtrNoFila aux;
    for (aux = fila->inicio; aux != NULL; aux = aux->prox) {
        free(aux);
    }
}*/

int main(int argc, char** argv) {
    FilaDinamica Fila;
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
    imprimeFila(&Fila);
    estadoFila(&Fila);
    dequeue(&Fila);
    imprimeFila(&Fila);
    dequeue(&Fila);
    imprimeFila(&Fila);
  //  destroiFila(&Fila);

    
    return (EXIT_SUCCESS);
}

