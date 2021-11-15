#include "estruturas.h"

tArvoreB *criaNo(int chave);
tArvoreB *inclui(tArvoreB *no, int c);
int token_to_num(const char *str, int *indice);
tArvoreB *montaarvore(const char *str);
tArvoreB *montaArvorePrincipal(tArvoreB *arvoreB, int chave);

void emordem(tArvoreB *no);
void preordem(tArvoreB *no); 
tArvoreB *exclui(tArvoreB *no, tArvoreB *raiz);
tArvoreB *sucessor(tArvoreB *no);
void ajustaNoPai(tArvoreB *no, tArvoreB *novo);
tArvoreB *busca(tArvoreB *no, int chave); 
tArvoreB *min(tArvoreB *no); 

// void arvoreResultante(tArvoreB *no); 