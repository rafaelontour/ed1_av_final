#include <stdio.h>
#include <stdlib.h>

struct T_Item {
    int campo;
};

struct T_No {
    T_Item item;
    T_No *prox;
};

struct T_Lista {
    T_No *primeiro;
    T_No *ultimo;
    int qtdeAtual;
};

void iniciarLista(T_Lista *lista) {
    T_No *no = (T_No *)malloc(sizeof(T_No));    
    no -> prox = NULL;

    lista -> primeiro = no;
    lista -> ultimo = no;
    lista -> qtdeAtual = 0;
}

int checkListaVazia(T_Lista *lista) {
    return lista -> primeiro == lista -> ultimo;
}

int inserir(T_Lista *lista, T_Item item) {
    int flag = 0;

    T_No *novo;
    novo = (T_No *)malloc(sizeof(T_No));
    novo -> item = item;
    novo -> prox = NULL;

    lista -> ultimo -> prox = novo;
    lista -> ultimo = novo;

    lista -> qtdeAtual++;

    flag = 1;
}

void exibir(T_Lista *lista) {
    printf("Lista: ");

    T_No *aux;
    aux = lista -> primeiro -> prox;

    while (aux != NULL) {
        printf(" - %d", aux -> item.campo);
        aux = aux -> prox;
    }

    printf("\n\n");
}

typedef T_No *TipoPonteiroNo;