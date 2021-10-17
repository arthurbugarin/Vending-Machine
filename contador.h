#ifndef CONTADOR_H_INCLUDED
#define CONTADOR_H_INCLUDED

/************************
 ctd_inserirPagamento
 Soma o valor de uma moeda nova inserida pelo comprador ao montante de pagamento atual
 entradas
   moedas : valor da moeda inserida pelo comprador
 saidas
   nenhuma
*************************/
extern void ctd_inserirPagamento(int moedas);

/************************
 ctd_verificaPagamento
 Retorna o pagamento inserido ate o momento armazenado no contador de moedas
 entradas
   nenhuma
 saidas
   dinheiro armazenado no contador
*************************/
extern int ctd_verificaPagamento();

/************************
 ctd_devolverMoedas
 Devolve o dinheiro inserido na maquina para o comprador
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void ctd_devolverMoedas();

/************************
 ctd_armazenaDinheiro
 Guarda o dinheiro inserido na maquina no cofre
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void ctd_armazenaDinheiro();

#endif // CONTADOR_H_INCLUDED
