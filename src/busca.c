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
            printf("INCLUA %s\n",expressao);
            int teste = somarChave(expressao);
            printf("TESTE:: :: %d\n\n", teste); 
            arvoreA = inclui(arvoreA, chave); 

            emordem(arvoreA);  
            // TODO
            // emordem(arvoresB[index]);
            index ++;
        }
        else if (strcmp(comando,"r") == 0){
            
            printf("REMOVA, '%s'\n", expressao);
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