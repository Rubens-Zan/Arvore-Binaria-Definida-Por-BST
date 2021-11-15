#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca.h"
#include "estruturas.h"
#include "arvorePrincipal.h"
#include "arvoreSecundaria.h"

void testaArvoreBinaria(){
    tArvoreB *arvoresB[30];
    tArvoreA *arvoreA = NULL; 
    int index = 0; 
    
    while (proximaExpressao()){
        int chaveArvore = 0; 
        char *comando = comandoAtual(); 
        char *expressao = expressaoAtual();
        arvoresB[index] = NULL; 

        if (strcmp(comando, "i") == 0 ){
            printf(" INCLUA   %s\n",expressao);
            arvoresB[index] = montaarvore(expressao);
            calculaChaveArvore(arvoresB[index], &chaveArvore); 
            arvoreA = arvorePrincipalInclui(arvoreA, arvoresB[index], chaveArvore); 
            printf("[");
            arvoreResultante(arvoreA);
            printf("]\n\n\n");
            index++;
        }
        else if (strcmp(comando,"r") == 0){
            printf("REMOVA, '%s'\n", expressao);
            // arvoresB[index] = montaarvore(expressao);
            // arvoreA = exclui(busca(arvoreA, chave), arvoreA);
            // arvoreResultante(arvoreA); 
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