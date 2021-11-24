#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

#define MAX_RESULTADOS 100
static char comandos[MAX_RESULTADOS][50];       /* matriz com os comandos a serem testados   */
static char expressoes[MAX_RESULTADOS][50];     /* matriz com expressoes de arvores em parenteses aninhados */

static unsigned int nComandos = 0;              /* quantidade de comandos do arquivo recebido */
static unsigned int comAtual = -1;              /* qual o comando atual */
/* -------------------------------------------------------------------------- */
unsigned int proximoComando(void) {
  comAtual++;
  return(comAtual < nComandos);
}
/* -------------------------------------------------------------------------- */
void carregarComandos(){
    char * line = NULL;
    size_t len = 0;
    size_t read;
    
    while ((read = getline(&line, &len, stdin)) != -1) {
        tratarExpressoes(line); 
        nComandos++;
    }
}
/* -------------------------------------------------------------------------- */
void tratarExpressoes(char *line){
    line[strlen(line)-1] = '\0';
    char delim[] = " \t\r\n\v\f";
    strcpy(comandos[nComandos], strtok(line, delim)); 
    strcpy(expressoes[nComandos], strtok(NULL, delim));  
    comandos[nComandos][strlen(comandos[nComandos])] = '\0';
    expressoes[nComandos][strlen(expressoes[nComandos])] = '\0';
    
}
/* -------------------------------------------------------------------------- */
// Soma a chave de uma expressao recebida no formato de parenteses aninhados
int calculaChaveExpressao(const char * expressao){
    int i = 0; 
    int chave = 0; 

    while (expressao[i] != '\0' && expressao[i] != ' '){
        if (expressao[i] == '('){
            i++; 
            if (ehNumero(expressao[i])){ 

                if(!ehNumero(expressao[i+1])){
                    chave+= expressao[i] - '0'; 
                }
                else {
                    char novoValor[50]; 
                    for (int j = 0;(ehNumero(expressao[i])); j++){
                        novoValor[j] = expressao[i]; 
                        i++;  
                    }    
                    chave+= atoi(novoValor); 
                } 
            }            
        }else{
        i++; 
        }
    }
    return chave; 
}
/* -------------------------------------------------------------------------- */
char *expressaoAtual(void){
    return expressoes[comAtual];
}
/* -------------------------------------------------------------------------- */
char *comandoAtual(void){
    return comandos[comAtual];
}
/* -------------------------------------------------------------------------- */
int ehNumero (char c){
    return (c >= 48 && c <= 57); 
}
/* -------------------------------------------------------------------------- */
