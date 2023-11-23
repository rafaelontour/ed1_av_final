#include <stdio.h>
#include "biblioteca.h"

int main() {
    T_Lista lista;
    T_Item item;
    // T_No *no;

    iniciarLista(&lista);

    item.campo = 10;
    inserir(&lista, item);
    item.campo = 20;
    inserir(&lista, item);
    item.campo = 30;
    inserir(&lista, item);
    item.campo = 40;
    inserir(&lista, item);

    // no = (T_No *)malloc(sizeof(T_No));
    // item.campo = 10; 
    // no -> item = item;
    // no -> prox = NULL;

    // lista.primeiro = no;

    // no = (T_No *)malloc(sizeof(T_No));
    // item.campo = 20;
    // no -> item = item;
    // no -> prox = NULL;

    // lista.primeiro -> prox = no;

    // printf("\nItem 1: %i\n", lista.primeiro -> item.campo);
    // printf("\nItem 2: %d\n", lista.primeiro -> prox -> item.campo);


    // no = (T_No *)malloc(sizeof(T_No));
    // item.campo = 30;
    // no -> item = item;
    // no -> prox = NULL;

    // lista.primeiro -> prox -> prox = no;

    // printf("\nItem 3: %i\n\n", lista.primeiro -> prox -> prox -> item.campo);

    // T_No *aux;
    // aux = lista.primeiro;

    // while (aux != NULL) {
    //     printf(" -> %d", aux -> item.campo);
    //     aux = aux -> prox;
    // }

    // printf("\n\n");

    // lista.ultimo = no;

    // no = (T_No *)malloc(sizeof(T_No));
    // item.campo = 40;
    // no -> item = item;
    // no -> prox = NULL;

    // lista.ultimo -> prox = no;
    
    exibir(&lista);

    return 0;
}