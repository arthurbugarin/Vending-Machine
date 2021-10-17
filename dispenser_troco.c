#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "definicoes_sistema.h"
#include "dispenser_troco.h"

int troco_disponivel[4]; // 10, 25, 50 e 100 centavos ficam nas posicoes 0,1,2,3
int troco[4] = {0,0,0,0};
int alteracao_troco;

/************************
 dis_calculaTroco
 Calcula o troco considerando o pagamento e o preco informados e armazena na memoria
 entradas
   pagamento : dinheiro inserido na maquina pelo comprador
   preco : preco do produto escolhido pelo comprador
 saidas
   TRUE: se ha troco disponivel para a compra na maquina FALSE: caso contrario
*************************/
int dis_calculaTroco(int pagamento, int preco)
{
  int i;
  int diferenca = pagamento - preco;
  while (diferenca > 0)
  {
      if (diferenca >= 100)
      {
        troco[3] += 1;
        diferenca -= 100;
      }
      else if (diferenca >= 50)
      {
        troco[2] += 1;
        diferenca -= 50;
      }
      else if (diferenca >= 25)
      {
        troco[1] += 1;
        diferenca -= 25;
      }
      else if (diferenca >= 10)
      {
        troco[0] += 1;
        diferenca -= 10;
      }

      if (diferenca > 0 && diferenca < 10)
      {
        return false;
      }//preco do produto nao permite troco, portanto o produto nao pode ser comprado
  }//while

  for (i=0; i<4; i++)
  {
    if (troco_disponivel[i] < troco[i])
      return false;
  }//for

  return true;
}

/************************
 dis_inicializaTroco
 Inicializa a maquina com quantidade pre-determinada de moedas para troco
 entradas
   quantidade : quantidade desejada de cada tipo de moeda
 saidas
   nenhuma
*************************/
void dis_inicializaTroco(int quantidade)
{
  int i;

  for (i=0; i<4; i++)
  {
    troco_disponivel[i] = quantidade;
  }
}

/************************
 dis_dispensarTroco
 Libera o troco para o comprador, reduz o troco disponivel e limpa o troco calculado armazenado na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void dis_dispensarTroco()
{
  int i;

  for (i=0; i<4; i++)
  {
    troco_disponivel[i] -= troco[i];
    troco[i] = 0;
  }
}

/************************
 dis_verificarTroco
 Retorna o valor calculado do troco (soma de qte de moeda*valor da moeda)
 entradas
   nenhuma
 saidas
   troco calculado
*************************/
int dis_verificarTroco()
{
  return troco[0]*10 + troco[1]*25 + troco[2]*50 + troco[3]*100;
}

/************************
 dis_armazenarAlteracao
 Armazena a entrada do repositor na memoria ate a definicao de alguma alteracao
 entradas
   alteracao : entrada do repositor a ser armazenada na memoria
 saidas
   nenhuma
*************************/
void dis_armazenarAlteracao(int alteracao)
{
  alteracao_troco = alteracao;
}

/************************
 dis_definirTroco10
 Define a quantidade de moedas de 10 centavos disponiveis para troco como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void dis_definirTroco10()
{
  troco_disponivel[0] = alteracao_troco;
}

/************************
 dis_definirTroco25
 Define a quantidade de moedas de 25 centavos disponiveis para troco como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void dis_definirTroco25()
{
  troco_disponivel[1] = alteracao_troco;
}

/************************
 dis_definirTroco50
 Define a quantidade de moedas de 50 centavos disponiveis para troco como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void dis_definirTroco50()
{
  troco_disponivel[2] = alteracao_troco;
}

/************************
 dis_definirTroco100
 Define a quantidade de moedas de 1 real disponiveis para troco como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void dis_definirTroco100()
{
  troco_disponivel[3] = alteracao_troco;
}
