#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca.h"
#include "estruturas.h"
#include "arvorePrincipal.h"
#include "arvoreSecundaria.h"

void testaArvoreBinaria(tArvoreA *arvoreA){
    
    // Enquanto existir um proximo comando, executa essa funcao
    while (proximoComando()){
        char *comando = comandoAtual(); 
        char *expressao = expressaoAtual();
        int chaveExpressao = calculaChaveExpressao(expressao); 

        // Busca expressao
        if ((*comando) == 'b'){
            tArvoreA *arvoreAux = buscaArvoreB(arvoreA, chaveExpressao);

            if (arvoreAux != NULL)
            {
                imprimeNosEmOrdem(arvoreAux->chave); 
                printf(": %d\n\n", chaveExpressao);
                
            }else {
                printf("No nao encontrado. \n\n"); 
            }
        }
        
        // Inserir expressao 
        else if ((*comando) == 'i' ){ 
            int chaveExpressao = calculaChaveExpressao(expressao); 
            arvoreA = arvorePrincipalInclui(arvoreA, montaArvoreSecundaria(expressao), chaveExpressao); 

            printf("\n[");
            arvoreResultante(arvoreA);
            printf("]\n\n");
        }

        // Remover expressao 
        else if ((*comando) == 'r'){
            tArvoreA *arvoreAux = buscaArvoreB(arvoreA, chaveExpressao);

            // Checagem se a subarvore passada (valor de indexacao dela) existe na arvore principal
            if (arvoreAux != NULL){
                arvoreA = excluiNoArvoreA(arvoreA, chaveExpressao);
            }

            printf("\n[");
            arvoreResultante(arvoreA);
            printf("]\n\n");
        }        
    }
}


int main(void){
    tArvoreA *arvoreA = NULL; 

    carregarComandos(); 
    testaArvoreBinaria(arvoreA); 

    return 0;    
}