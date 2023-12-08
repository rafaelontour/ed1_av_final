#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "biblioteca.h"
#define MAX_CAIXAS 5

bool clienteChegou();
int gerarOperacao();
void decCaixas(int *caixas);
void listarCaixas(int caixas[]);

int main(void) {
    srand(time(NULL));

    T_Lista lista;
    T_Item pessoa;
    iniciarLista(&lista);

    int caixas[MAX_CAIXAS] = {0};
    int tempo_Total_Espera = 0;
    int total_Clientes = 0;
    int tempo_Atendimento = 100;
    float tempo_Medio_Espera = 0.0;
    int c = 0;
    int contCaixa = 0;

    while (c < tempo_Atendimento) {

        printf("******************\n");
        printf("TEMPO: %i\n", c);

        bool chegou = clienteChegou();

        if (chegou) { // Se chegou...

            pessoa.campo = c;
            int ok = inserir(&lista, pessoa); // Inserimos na fila
            total_Clientes++;

        } 

        printf("Fila: ");
        exibir(&lista);
        printf("\n\n");

        
        for (int caixa = 0;caixa < MAX_CAIXAS;caixa++) { // Aqui os caixas são verificados. Se tiver algum vazio...
            if (caixas[caixa] == 0 && lista.qtdeAtual > 0) {
                caixas[caixa] = excluirInicio(&lista);  // Pessoa sai da fila e vai pro caixa
                // excluirInicio(&lista); // Remove a pessoa da fila para ir pro caixa
                tempo_Total_Espera += (c - caixas[caixa]);
                caixas[caixa] = gerarOperacao(); // Operação é gerada e colocada logo no vator de caixas na posição vazia achada
            }
        }


        printf("       CAIXAS\n");
        listarCaixas(caixas);

        for (int caixa = 0;caixa < MAX_CAIXAS;caixa++) { // Decrementando o cronômetro e calculando o tempo total de espera;
            if (caixas[caixa] != 0) { caixas[caixa]--; }
        }

        c++;
    }

    printf("\n\n************** RELATÓRIO ***************\n\n");

    tempo_Medio_Espera = (float)tempo_Total_Espera / (float)total_Clientes;
    printf("Tempo de funcionamento: %i\n", c);
    printf("Total de clientes: %d\n", total_Clientes);
    printf("Tempo total de espera: %d\n", tempo_Total_Espera);
    printf("Tempo médio de espera: %.2f segundos\n\n", tempo_Medio_Espera);


    return 0;
}

void listarCaixas(int caixas[]) {
    for (int c = 0;c < 5;c++) { printf("%d   ", caixas[c]); }
    printf("\n");
}

bool clienteChegou() {
    int aleatorio = rand() % 5;
    return aleatorio == 3;
}

void decCaixas(int *caixas) {
    int tempo_Total_Espera = 0;
    for (int c = 0;c < MAX_CAIXAS;c++) {
        if (caixas[c] != 0) {
            caixas[c]--;
        }
    }
}

int gerarOperacao() {
    int aleatorio = rand() % 5;
    switch(aleatorio) {
        case 0: return 10;
        case 1: return 20;
        case 2: return 30;
        case 3: return 40;
        case 4: return 50;
    }
}