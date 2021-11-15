#include "stdio.h"
#include "stdlib.h"

#include "arvorePrincipal.h"
#include "arvoreSecundaria.h"
#include "biblioteca.h"
#include "estruturas.h"

/* -------------------------------------------------------------------------- */
tArvoreA *arvorePrincipalCriaNo(tArvoreB *arvoreB)
{
    tArvoreA *n = (tArvoreA *)malloc(sizeof(tArvoreA));
    n->chave = arvoreB; 
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
};
/* -------------------------------------------------------------------------- */
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
/* -------------------------------------------------------------------------- */
void imprimeNosArvorePrincipal (tArvoreB *arvoreB){
    if (arvoreB != NULL){
        printf("(%d",arvoreB->chave);
        if (arvoreB->dir != NULL || arvoreB->esq != NULL){
            printf("("); 
            imprimeNosArvorePrincipal(arvoreB->esq);
            printf("(");
            imprimeNosArvorePrincipal(arvoreB->dir);
            
        }
    }else{
        printf(" "); 
    }
    printf(")"); 
}
/* -------------------------------------------------------------------------- */
void calculaChaveArvore(tArvoreB *no, int *chave){
    if (no != NULL)
    {
        calculaChaveArvore(no->esq, chave);
        (*chave) += no->chave; 
        calculaChaveArvore(no->dir, chave);
    }
}
/* -------------------------------------------------------------------------- */
void arvoreResultante(tArvoreA *arvoreA){
    printf("[");
    if (arvoreA != NULL){
        int chaveArvore = 0;
        imprimeNosArvorePrincipal(arvoreA->chave);
        calculaChaveArvore(arvoreA->chave, &chaveArvore);
        printf(": %d\n", chaveArvore); 

        if (arvoreA->dir != NULL || arvoreA->esq != NULL){
            arvoreResultante(arvoreA->esq);
            arvoreResultante(arvoreA->dir); 
        }
    }else{
        printf("\n"); 
    }
    printf("]\n"); 
}
/* -------------------------------------------------------------------------- */
tArvoreB *buscaArvoreB(tArvoreA *arvoreA, int chave)
{
    if (arvoreA == NULL)
        return 0;
    else{
        imprimeNosArvorePrincipal(arvoreA->chave); 
        printf("\n"); 
        int chaveArvore = 0;
        calculaChaveArvore(arvoreA->chave, &chaveArvore); 

        if ( chaveArvore == chave)
            return arvoreA->chave;
        if (chave < chaveArvore)
            return buscaArvoreB(arvoreA->esq, chave);
        else
            return buscaArvoreB(arvoreA->dir, chave);
    }
};
/* -------------------------------------------------------------------------- */
void ajustaNoPai(tArvoreA *no, tArvoreA *novo){
    if (no->pai != NULL){
        if (no->pai->esq == no){

        }
    }
}
/* -------------------------------------------------------------------------- */

tArvoreA *excluiNoArvoreA(tArvoreB *arvoreB, tArvoreA *arvoreA){
    tArvoreA *s,*novaArvore = arvoreA; 
    if (arvoreB->esq == NULL){

    }
    else{
        if (arvoreB->dir == NULL){

        }else{
            
        }
    }
    return novaArvore; 
}