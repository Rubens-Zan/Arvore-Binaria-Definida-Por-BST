#include "estruturas.h"
tArvoreB *montaArvoreSecundaria(const char *str);
tArvoreB *criaNo(int chave);
tArvoreB *inclui(tArvoreB *no, int c);
int numeroEntreParenteses(const char *str, int *indice); 
tArvoreB *montaarvore(const char *str);
void imprimeNosEmOrdem (tArvoreB *no);  
void imprimeNosPreOrdem (tArvoreB *no); 