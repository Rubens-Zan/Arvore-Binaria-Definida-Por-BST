#ifndef _ESTRUTURAS_H_
#define _ESTRUTURAS_H_


typedef struct tArvoreB tArvoreB;
struct tArvoreB
{
    int chave; // pode ser modificado para qualquer tipo de dado
    tArvoreB *esq, *dir, *pai;
};

typedef struct tArvoreA tArvoreA; 
struct tArvoreA
{
    tArvoreA *esq, *dir, *pai;
    tArvoreB *chave; 
};


#endif
