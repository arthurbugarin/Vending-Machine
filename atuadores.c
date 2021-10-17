#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "atuadores.h"

/************************
 atd_ativar
 Ativa o atuador de um produto para liberar ele ao comprador
 entradas
   produto : numero do produto que se deseja liberar
 saidas
   nenhuma
*************************/
void atd_ativar(int produto)
{
  printf("Ativado atuador do produto %d\n", produto + 1);
}
