#include "stdio.h"
#include "stdlib.h"
#include "arvoreBinariaBusca.h"
#include "biblioteca.h"
#include "estruturas.h"

tArvoreA *arvorePrincipalCriaNo(tArvoreB *arvoreB)
{
    tArvoreA *n = (tArvoreA *)malloc(sizeof(tArvoreA));
    n->chave = arvoreB; 
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
};

tArvoreA *arvorePrincipalInclui(tArvoreA *arvoreA,tArvoreB *arvoreB, int valor){
    if (arvoreA == NULL)
        return arvorePrincipalCriaNo(arvoreB); 
    int index = 0;
    calculaChaveArvore(arvoreA->chave, &index); 
    if (valor < index){
        arvoreA->esq = arvorePrincipalInclui(arvoreA->esq, arvoreB, valor);
        arvoreA->esq->pai = arvoreA; 
    }
    else
    {
        arvoreA->dir = arvorePrincipalInclui(arvoreA->dir, arvoreB, valor);
        arvoreA->dir->pai = arvoreA;
    }
    return arvoreA;
}

