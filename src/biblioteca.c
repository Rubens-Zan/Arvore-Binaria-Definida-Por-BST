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
}
/* -------------------------------------------------------------------------- */
char *expressaoAtual(void){
    return expressoes[resultadoAtual];
}
/* -------------------------------------------------------------------------- */
char *comandoAtual(void){
    return comandos[resultadoAtual];
}