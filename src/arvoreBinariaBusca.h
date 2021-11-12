#include "estruturas.h"

tNo *criaNo(int chave);
tNo *inclui(tNo *no, int c);
int token_to_num(const char *str, int *indice, int * chave);
tNo *montaarvore(const char *str, int * chave);
tNo *montaArvorePrincipal(int chave);
void emordem(tNo *no);
tNo *exclui(tNo *no, tNo *raiz);
tNo *sucessor(tNo *no);
void ajustaNoPai(tNo *no, tNo *novo);
tNo *busca(tNo *no, int chave); 
tNo *min(tNo *no); 

void arvoreResultante(tNo *no); 