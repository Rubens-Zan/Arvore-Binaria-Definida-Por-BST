# Implementação de árvore binária de busca A, com chave definida por uma árvore binária de busca B
Projeto 02- Disciplina CI1057   
Autor: Rubens Zandomenighi Laszlo - GRR20206147
Data: 24/11/2021

## Compilação 
Compila a partir do C, utilizando comandos make.  
Para efetuar a compilação, basta digitar make,  
Para excluir todos os arquivos temporários digite make clean,   
e para excluir temporários e o executável digite make purge.  
Ao compilar criará um arquivo executável com o nome busca.

## Execução
O programa le as expressõoes de entrada de um arquivo, armazenando os comandos e as expressões.

Foram incluídos as entradas para testar o programa na pasta casos_teste, para efetuar a execução, basta digitar por exemplo 
./busca < ../casos_teste/1teste.in 

## Entrada
A entrada deve conter comandos. Os comandos são i (inserção), b, (busca) e r, (remoção). Todos os comando tem um parâmetro, que aparece separado do comando por um espaço. Os comandos aparecem um por linha, seguidos por um espaço e uma subárvore passada. Essa subárvore é no formato de parênteses aninhados, representando a árvore secundária B.
Por exemplo, _i (10(8)(30))_ 

## Saída
Para comando em que ocorrem mudanças na árvore binária (inserção e remoção), a saída é a árvore resultante porteriormente ao comando, já para o comando de busca, caso o valor de indexação da subárvore buscada a saída é o nó, cujo valor de indexação é igual ao da subárvore buscada, senão imprimi-se que a subárvore não foi encontrada. 
A impressão das subárvores da árvore principal é feita em ordem, sendo cada nó separado por () seguido por : _valor de indexação_  por exemplo para um nó com o seguinte formato em pré ordem *(25(10(5)())())* é impresso *(5)(10)(25): 40*. 
A saída dos comandos são separadas por uma linha  vazia. 