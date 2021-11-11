#include "estruturas.h"

tNo *criaNo(int chave);
tNo *inclui(tNo *no, int c);
int token_to_num(const char *str, int *indice, int * chave);
tNo *montaarvore(const char *str, int * chave);
tNo *montaArvorePrincipal(int chave);
void emordem(tNo *no); 
