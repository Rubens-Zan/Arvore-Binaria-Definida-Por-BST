#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

#define MAX_RESULTADOS 100
static char comandos[MAX_RESULTADOS][50];     /* matriz com expressões testadas   */
static char expressoes[MAX_RESULTADOS][50];     /* matriz com resultados das expressões testadas   */

static unsigned int nResultados = 0;            /* quantidade de resultados do arquivo */
static unsigned int resultadoAtual = -1;        /* qual o resultado atual */
/* -------------------------------------------------------------------------- */
unsigned int proximaExpressao(void) {
  resultadoAtual++;
  return(resultadoAtual < nResultados);
}
/* -------------------------------------------------------------------------- */
void carregarExpressoes(){
    char * line = NULL;
    size_t len = 0;
    size_t read;
    
    while ((read = getline(&line, &len, stdin)) != -1) {
        tratarExpressoes(line); 
        nResultados++;
    }
}
/* -------------------------------------------------------------------------- */
void tratarExpressoes(char *line){
    line[strlen(line)-1] = '\0';
    char delim[] = " \t\r\n\v\f";
    strcpy(comandos[nResultados], strtok(line, delim)); 
    strcpy(expressoes[nResultados], strtok(NULL, delim));  
    comandos[nResultados][strlen(comandos[nResultados])] = '\0';
    expressoes[nResultados][strlen(expressoes[nResultados])] = '\0';
    
}
/* -------------------------------------------------------------------------- */
int somarChave(const char * expressao){
    int i = 0; 
    int res = 0; 

    while (expressao[i] != '\0' && expressao[i] != ' '){
        if (expressao[i] == '('){
            i++; 
            if(!(expressao[i+1] >= 48 && expressao[i+1] <= 57)){
                res+= expressao[i] - '0'; 
            }
            else {
                int k = 0;
                char novoValor[50]; 
                for (int j = i;(expressao[j] >= 48 && expressao[j] <= 57);j++){
                    k++;  
                } 
                strncpy(novoValor, &expressao[i], k);
                i += k;   
                res+= atoi(novoValor); 
            } 

        }
        i++; 
    }
    return res; 
}
/* -------------------------------------------------------------------------- */
char *expressaoAtual(void){
    return expressoes[resultadoAtual];
}
/* -------------------------------------------------------------------------- */
char *comandoAtual(void){
    return comandos[resultadoAtual];
}
/* -------------------------------------------------------------------------- */
int ehNumero (char c){
    return (c >= 48 && c <= 57); 
}
/* -------------------------------------------------------------------------- */
