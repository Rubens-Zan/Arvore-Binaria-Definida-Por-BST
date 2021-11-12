#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca.h"
#include "estruturas.h"
#include "arvoreBinariaBusca.h"

void testaArvoreBinaria(){
    tNo *arvoresB[30];
    tNo *arvoreA = NULL; 
    int index = 0; 
    while (proximaExpressao()){
        int chave = 0;
        char *comando = comandoAtual(); 
        char *expressao = expressaoAtual();
        arvoresB[index] = NULL; 

        if (strcmp(comando, "i") == 0 ){
            arvoresB[index] = montaarvore(expressao, &chave);
            printf("Incluindo %s\n",expressao);
            arvoreA = inclui(arvoreA, chave); 
            arvoreResultante(arvoreA); 
            printf("\n\n"); 

            index++;
        }
        else if (strcmp(comando,"r") == 0){
            printf("REMOVA, '%s'\n", expressao);
            arvoresB[index] = montaarvore(expressao, &chave);
            // TODOOO
            // arvoreA = exclui(busca(arvoreA, chave), arvoreA);
            arvoreResultante(arvoreA); 
        }
        else if (!strcmp(comando, "b")){
            // printf("BUSCAR, '%s' \n", expressao);
        }
    }
}

int main(void){
    carregarExpressoes(); 
    printf("Expressões carregadas... \n");

    testaArvoreBinaria(); 


    return 0;    
}