#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "estruturas.h"

tNo *inicia(const char *valor)
{
    tNo *n = (tNo *)malloc(sizeof(tNo));
    n->chave = atoi(valor);
    n->dir = NULL;
    n->esq = NULL;

    printf("CHAVE :: %d \n", n->chave); 

    return n;
}

tNo *montaarvore(const char *str, int *i)
{
    tNo *no = NULL;
    if (str[*i] == '(')
    {   
        (*i)++; 
        // Se o proximo nao eh um numero
        printf("STRING TOTAL  %s", str); 
        printf("AQUI:::: '%c'", str[*i] );
        if (!((str[*i+1] >= 48) && (str[*i+1] <= 57))) {
            printf("estoy aqui... "); 
            no = inicia(&str[*i]);
            (*i)++;
        }
        else {
            printf("cheguei aqui;;;; ");

            int k = 0;
            char novoValor[50]; 
            for (int j = (*i);(str[j] >= 48 && str[j] <= 57);j++){

        
                k++;  
            } 
            strncpy(novoValor, &str[*i], k);
            (*i) += k;
            printf("NOVO VALO :: %s \n",novoValor);   
            no = inicia(novoValor); 
        }
        no->esq = montaarvore(str, i);
        no->dir = montaarvore(str, i);
        (*i)++;
    }

    return no;
}

void testaArvoreBinaria(){
    int i = 0;
    tNo *arvoresB;

    while (proximaExpressao()){
       char *comando = comandoAtual(); 
       char *expressao = expressaoAtual(); 

        if (!strcmp(comando, "i")){
            printf("INSERIR, '%s' \n", expressao);
            arvoresB = montaarvore(expressao, &i); 
        }
        else if (!strcmp(comando,"r")){
            printf("REMOVER, '%s'\n", expressao);
        }
        else if (!strcmp(comando, "b")){
            printf("BUSCAR, '%s' \n", expressao);
        }
    }
}

int main(void){
    carregarExpressoes(); 
    testaArvoreBinaria(); 

    return 0;    
}