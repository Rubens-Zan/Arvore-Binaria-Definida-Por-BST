#include "estruturas.h"

tArvoreA *arvorePrincipalCriaNo(tArvoreB *arvoreB);
tArvoreA *arvorePrincipalInclui(tArvoreA *arvoreA,tArvoreB *arvoreB, int valor);
void arvoreResultante(tArvoreA *arvoreA);
void calculaChaveArvore(tArvoreB *no, int *chave); 