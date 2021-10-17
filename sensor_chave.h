#ifndef SENSOR_CHAVE_H_INCLUDED
#define SENSOR_CHAVE_H_INCLUDED

/*******************************
 snr_alterarSinal
 Alterna entre modo de manutencao ou de utilizacao (compra)
 entradas
   nenhuma
 saidas
   nenhuma
********************************/
extern void snr_alterarSinal();

/*******************************
 snr_estaAtivo
 Retorna se o sensor da chave esta ativo
 entradas
   nenhuma
 saidas
   TRUE: se o sensor esta ativo FALSE: caso contrario
********************************/
extern int snr_estaAtivo();

#endif // SENSOR_CHAVE_H_INCLUDED
