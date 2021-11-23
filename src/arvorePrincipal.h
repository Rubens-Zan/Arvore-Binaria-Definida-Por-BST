#include "estruturas.h"

tArvoreA *arvorePrincipalCriaNo(tArvoreB *arvoreB);
tArvoreA *arvorePrincipalInclui(tArvoreA *arvoreA,tArvoreB *arvoreB, int valor);
void arvoreResultante(tArvoreA *arvoreA);
void calculaChaveArvore(tArvoreB *no, int *chave); 
tArvoreA *buscaArvoreB(tArvoreA *arvoreA, int chave);
tArvoreA *min(tArvoreA *arvoreB); 
void imprimeNosArvorePrincipal (tArvoreB *arvoreB);
tArvoreA *excluiNoArvoreA(tArvoreA *no, int chaveNo); 