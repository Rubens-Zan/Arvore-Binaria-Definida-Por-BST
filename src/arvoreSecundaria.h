#include "estruturas.h"

tArvoreB *criaNo(int chave);
tArvoreB *inclui(tArvoreB *no, int c);
int token_to_num(const char *str, int *indice);
tArvoreB *montaarvore(const char *str);
tArvoreB *montaArvorePrincipal(tArvoreB *arvoreB, int chave);
void emordem(tArvoreB *no);