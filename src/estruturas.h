// typedef struct tArvorePrincipal arvorePrincipal;
// struct arvorePrincipal 
// {
//     tArvorePrincipal *esq, *dir, *pai;
// };

// typedef struct arvoreB tArvoreB;
// struct arvoreB
// {
//     int chave; 
//     tArvoreB *esq, *dir;
// }; 


typedef struct tNo tNo;
struct tNo
{
    int chave; // pode ser modificado para qualquer tipo de dado
    tNo *esq, *dir, *pai;
};
