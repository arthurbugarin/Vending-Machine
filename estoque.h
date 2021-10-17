#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

/************************
 stq_escolherProduto
 Armazena o produto escolhido pelo comprador na memoria
 entradas
   numero_produto : numero do produto escolhido pelo comprador
 saidas
   nenhuma
*************************/
extern void stq_escolherProduto(int numero_produto);

/************************
 stq_retirarProduto
 Retira uma unidade do produto escolhido armazenado na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void stq_retirarProduto();

/************************
 stq_idProduto
 Retorna o produto escolhido armazenado na memoria
 entradas
   nenhuma
 saidas
   numero do produto escolhido
*************************/
extern int stq_idProduto();

/************************
 stq_idProduto
 Retorna o preco do produto escolhido armazenado na memoria
 entradas
   nenhuma
 saidas
   preco do produto escolhido
*************************/
extern int stq_precoProduto();

/************************
 stq_qteProduto
 Retorna a quantidade do produto escolhido armazenado na memoria
 entradas
   nenhuma
 saidas
   quantidade do produto escolhido
*************************/
extern int stq_qteProduto();

/************************
 stq_inicializarProdutos
 Inicializa produtos de exemplo na memoria durante a inicializacao da vending machine
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void stq_inicializarProdutos();

/************************
 stq_armazenarAlteracao
 Armazena a entrada do repositor na memoria ate a definicao de alguma alteracao
 entradas
   alteracao : entrada do repositor a ser armazenada na memoria
 saidas
   nenhuma
*************************/
extern void stq_armazenarAlteracao(int alteracao);

/************************
 stq_definirPosicao
 Define a posicao do produto novo na maquina como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void stq_definirPosicao();

/************************
 stq_definirQuantidade
 Define a quantidade do produto novo na maquina como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void stq_definirQuantidade();

/************************
 stq_definirPreco
 Define o preco do produto novo na maquina como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void stq_definirPreco();

#endif // ESTOQUE_H_INCLUDED