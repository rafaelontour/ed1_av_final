#include <stdio.h>
#include <stdlib.h>

struct T_Item {
    int campo;
    
};

struct T_No {
    T_Item item;
    T_No *prox;
};

typedef T_No *TipoPonteiroNo;

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

void inserir(T_Lista *lista, T_Item item) {

    T_No *novo;
    novo = (T_No *)malloc(sizeof(T_No));
    novo -> item = item;
    novo -> prox = NULL;

    lista -> ultimo -> prox = novo;
    lista -> ultimo = novo;

    lista -> qtdeAtual++;

}

T_No *localizar(T_Lista *lista) {
    
    T_No *aux = lista -> primeiro;

    while (aux != NULL) {

        aux = aux -> prox;
        if (lista -> qtdeAtual > 1) {
            if (aux -> prox -> prox == NULL) {
                return aux;
            }
        } else {
            if (aux -> prox == NULL) {
                return lista -> primeiro;
            }
        }

        
    }

    return aux;

}

void excluirInicio(T_Lista *lista) {
    
    T_No *aux;
    aux = lista -> primeiro -> prox;
    free(lista -> primeiro);
    lista -> primeiro = aux;
    lista -> qtdeAtual--;
    
}

void excluirFinal(T_Lista *lista) {
    if (checkListaVazia(lista)) {
        printf("Lista vazia\n");
        return;
    }

    T_No *noLocalizado = localizar(lista);


    free(noLocalizado -> prox);
    noLocalizado -> prox = NULL;
    
    if (lista -> qtdeAtual > 1) {
        lista -> ultimo = noLocalizado;
        
    } else {
        lista -> ultimo = (T_No *)malloc(sizeof(T_No));
        lista -> primeiro = lista -> ultimo;
    }
    lista -> qtdeAtual--;

    
}

void inserirMeio(T_Lista *lista, int pos, T_Item item) {
    T_No *aux = lista -> primeiro;
    T_No *aux2;

    int cont = 0;    

    while (true) {

        cont++;

        if (pos == 1) {
            
            T_No *aux3;
            aux3 = lista -> primeiro -> prox;

            T_No *novo;
            novo = (T_No *)malloc(sizeof(T_No));

            lista -> primeiro -> prox = novo;

            novo -> item = item;
            novo -> prox = aux3;

            lista -> qtdeAtual++;

            return;
        }

        aux = aux -> prox;

        if (cont == pos - 1) {

            aux2 = aux -> prox;
            aux -> prox = NULL;

            T_No *novo;
            novo = (T_No *)malloc(sizeof(T_No));
            novo -> item = item;

            aux -> prox = novo;
            novo -> prox = aux2;

            lista -> qtdeAtual++;            
            break;
        }

        
    }
}

void exibir(T_Lista *lista) {

    if (checkListaVazia(lista)) {
        printf("Lista vazia\n");
        return;
    }

    printf("Lista: ");

    T_No *aux;
    aux = lista -> primeiro -> prox;

    while (aux != NULL) {
        printf(" - %d", aux -> item.campo);
        aux = aux -> prox;
    }

    printf("\n\n");
}

