# Implementação de árvore binária de busca A, com chave definida por uma árvore binária de busca B
Projeto 02- Disciplina CI1057\
Autor: __Rubens Zandomenighi Laszlo - GRR20206147__\
Data: 24/11/2021

## Compilação 
Compila a partir do C, utilizando comandos make.  
Para efetuar a compilação, basta ir ao diretório src e digitar make.
Para excluir todos os arquivos temporários digite make clean,
e para excluir temporários e o executável digite make purge.  
Ao compilar criará um arquivo executável com o nome busca.

## Execução
A leitura dos comandos e das expressões em parênteses aninhados é efetuada por meio de um arquivo de entrada, armazenando os comandos e as expressões.Basta digitar : 
./busca < _nomeDoArquivo_.in 

## Entrada
A entrada deve conter comandos. Os comandos são i (inserção), b, (busca) e r, (remoção). Todos os comando tem um parâmetro, que aparece separado do comando por um espaço. Os comandos aparecem um por linha, seguidos por um espaço e uma subárvore passada. Essa subárvore é no formato de parênteses aninhados, representando a árvore secundária B.

Por exemplo, para o seguinte comando __i (10(8)(30))__, esse comando montará uma árvore secundária _(10(8)(30))_, calculará o __valor de indexação (soma dos nós da árvore)__, nesse caso, _48_, e inserirá na árvore principal na posição correta, tal que a árvore principal continue a ser uma árvore binária de busca , sendo a chave da árvore principal um ponteiro para essa subárvore B. 

## Saída
A cada comando executado é gerado uma saída, sendo separadas por linha vazia, no seguinte formato: \
Para comando em que ocorrem mudanças na árvore binária (inserção e remoção), a saída é a árvore resultante porteriormente ao comando.
A impressão dos nós da árvore principal é feita em pre ordem, seguido por : _valor de indexação_  tal como o seguinte formato: 
 _(25(10(5)())()) : 40_. 
A impressão da árvore resultante é efetuada no formato de parênteses aninhados, utilizando  [ ] como separadores. E para a impressão das chaves dos nós da árvore principal é utilizada a mesma representação, utilizando ( ) como separadores.  
No seguinte formato: \
[[(1): 1 \
[  \
]  \
[(10(8)(30)): 48  \
[(11(10)(17)): 38  \
[(15): 15  \
]  \
[(25(10(5)())()): 40  \
]  \
]  \
[  \
]  \
]  \
]  \

Já para o comando de busca, é mostrado o percurso efetuado na busca pela subárvore buscada. Após o fim da busca, caso a subárvore passada foi encontrada é impresso  : \
**No encontrado : [_chave do no em pre ordem_] : _valor de indexação_**,\
senão é impresso:  **No nao encontrado**
