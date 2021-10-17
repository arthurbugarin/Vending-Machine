#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "sensor_chave.h"

int snr = false;

/*******************************
 snr_alterarSinal
 Alterna entre modo de manutencao ou de utilizacao (compra)
 entradas
   nenhuma
 saidas
   nenhuma
********************************/
void snr_alterarSinal()
{
   snr = !(snr);
}

/*******************************
 snr_estaAtivo
 Retorna se o sensor da chave esta ativo
 entradas
   nenhuma
 saidas
   TRUE: se o sensor esta ativo FALSE: caso contrario
********************************/
int snr_estaAtivo()
{
   return snr;
}
