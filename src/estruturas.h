#ifndef _ESTRUTURAS_H_
#define _ESTRUTURAS_H_


typedef struct tNo tNo;
struct tNo
{
    int chave; // pode ser modificado para qualquer tipo de dado
    tNo *esq, *dir, *pai;
};

typedef struct tArvoreA tArvoreA; 
struct tArvoreA
{
    tArvoreA *esq, *dir, *pai;
    tNo *tNo; 
};


#endif
