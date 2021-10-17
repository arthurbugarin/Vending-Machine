#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "estoque.h"

int produto_escolhido;
typedef struct{
    int qte;
    float preco;
} Produto;
Produto Estoque[30];
int posicao_nova;
int quantidade_nova;
int preco_novo;
int informacao_nova;

/************************
 stq_escolherProduto
 Armazena o produto escolhido pelo comprador na memoria
 entradas
   numero_produto : numero do produto escolhido pelo comprador
 saidas
   nenhuma
*************************/
void stq_escolherProduto(int numero_produto)
{
  produto_escolhido = numero_produto;
}

/************************
 stq_retirarProduto
 Retira uma unidade do produto escolhido armazenado na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void stq_retirarProduto()
{
  Estoque[produto_escolhido].qte -= 1;
}

/************************
 stq_idProduto
 Retorna o produto escolhido armazenado na memoria
 entradas
   nenhuma
 saidas
   numero do produto escolhido
*************************/
int stq_idProduto()
{
  return produto_escolhido;
}

/************************
 stq_idProduto
 Retorna o preco do produto escolhido armazenado na memoria
 entradas
   nenhuma
 saidas
   preco do produto escolhido
*************************/
int stq_precoProduto()
{
  return Estoque[produto_escolhido].preco;
}

/************************
 stq_qteProduto
 Retorna a quantidade do produto escolhido armazenado na memoria
 entradas
   nenhuma
 saidas
   quantidade do produto escolhido
*************************/
int stq_qteProduto()
{
  return Estoque[produto_escolhido].qte;
}

/************************
 stq_inicializarProdutos
 Inicializa produtos de exemplo na memoria durante a inicializacao da vending machine
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void stq_inicializarProdutos()
{
    int i;
    for (i=0; i<30; i++)
    {
        int quant = 3*i/10 + 1;
        Estoque[i].qte = quant;
    }

    for (i=0; i<30; i++) 
    {
        Estoque[i].preco = 100*i/3.0;
    }
}

/************************
 stq_armazenarAlteracao
 Armazena a entrada do repositor na memoria ate a definicao de alguma alteracao
 entradas
   alteracao : entrada do repositor a ser armazenada na memoria
 saidas
   nenhuma
*************************/
void stq_armazenarAlteracao(int alteracao)
{
  informacao_nova = alteracao;
}

/************************
 stq_definirPosicao
 Define a posicao do produto novo na maquina como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void stq_definirPosicao()
{
  posicao_nova = informacao_nova - 1;
}

/************************
 stq_definirQuantidade
 Define a quantidade do produto novo na maquina como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void stq_definirQuantidade()
{
  Estoque[posicao_nova].qte = informacao_nova;
}

/************************
 stq_definirPreco
 Define o preco do produto novo na maquina como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void stq_definirPreco()
{
  Estoque[posicao_nova].preco = informacao_nova;
}