#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "contador.h"

int pagamento = 0;
int cofre = 0;

/************************
 ctd_inserirPagamento
 Soma o valor de uma moeda nova inserida pelo comprador ao montante de pagamento atual
 entradas
   moedas : valor da moeda inserida pelo comprador
 saidas
   nenhuma
*************************/
void ctd_inserirPagamento(int moedas)
{
  pagamento += moedas;
}

/************************
 ctd_verificaPagamento
 Retorna o pagamento inserido ate o momento armazenado no contador de moedas
 entradas
   nenhuma
 saidas
   dinheiro armazenado no contador
*************************/
int ctd_verificaPagamento()
{
  return pagamento;
}

/************************
 ctd_devolverMoedas
 Devolve o dinheiro inserido na maquina para o comprador
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void ctd_devolverMoedas()
{
  pagamento = 0;
}

/************************
 ctd_armazenaDinheiro
 Guarda o dinheiro inserido na maquina no cofre
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void ctd_armazenaDinheiro()
{
  cofre += pagamento;
  pagamento = 0;
  printf("Dinheiro armazenado no cofre: %d\n", cofre);
}
