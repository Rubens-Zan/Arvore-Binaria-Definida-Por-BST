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
    
    // Enquanto existir um proximo comando, executa essa funcao
    while (proximoComando()){
        int chaveArvore = 0; 
        char *comando = comandoAtual(); 
        char *expressao = expressaoAtual();
        arvoresB[index] = NULL; 

        // Busca expressao
        if ((*comando) == 'b'){
            calculaChaveArvore(montaarvore(expressao), &chaveArvore);

            tArvoreA *arvoreAux = buscaArvoreB(arvoreA,chaveArvore);
            if (arvoreAux != NULL)
            {
                imprimeNosEmOrdem(arvoreAux->chave); 
                printf(": %d\n\n", chaveArvore);
                
            }else {
                printf("Nao achou!\n\n"); 
            }
        }
        else {
        
            // Inserir expressao 
            if ((*comando) == 'i' ){
                arvoresB[index] = montaarvore(expressao);
                calculaChaveArvore(arvoresB[index], &chaveArvore); 
                arvoreA = arvorePrincipalInclui(arvoreA, arvoresB[index], chaveArvore); 
                
                index++;
            }

            // Remover expressao 
            else if ((*comando) == 'r'){
                calculaChaveArvore(montaarvore(expressao), &chaveArvore);    
                tArvoreA *arvoreAux = buscaArvoreB(arvoreA, chaveArvore);

                // Checagem se a subarvore passada (valor de indexacao dela) existe na arvore principal
                if (arvoreAux != NULL){
                    arvoreA = excluiNoArvoreA(arvoreA, chaveArvore);  
                }
            }

           
            printf("\n[");
                arvoreResultante(arvoreA);
            
            printf("]\n\n");
        }
        
    }
}

int main(void){
    carregarComandos(); 
    testaArvoreBinaria(); 

    return 0;    
}