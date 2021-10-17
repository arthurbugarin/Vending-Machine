#ifndef DISPENSER_TROCO_H_INCLUDED
#define DISPENSER_TROCO_H_INCLUDED

/************************
 dis_calculaTroco
 Calcula o troco considerando o pagamento e o preco informados e armazena na memoria
 entradas
   pagamento : dinheiro inserido na maquina pelo comprador
   preco : preco do produto escolhido pelo comprador
 saidas
   TRUE: se ha troco disponivel para a compra na maquina FALSE: caso contrario
*************************/
extern int dis_calculaTroco(int pagamento, int preco);

/************************
 dis_inicializaTroco
 Inicializa a maquina com quantidade pre-determinada de moedas para troco
 entradas
   quantidade : quantidade desejada de cada tipo de moeda
 saidas
   nenhuma
*************************/
extern void dis_inicializaTroco(int quantidade);

/************************
 dis_dispensarTroco
 Libera o troco para o comprador, reduz o troco disponivel e limpa o troco calculado armazenado na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void dis_dispensarTroco();

/************************
 dis_verificarTroco
 Retorna o valor calculado do troco (soma de qte de moeda*valor da moeda)
 entradas
   nenhuma
 saidas
   troco calculado
*************************/
extern int dis_verificarTroco();

/************************
 dis_armazenarAlteracao
 Armazena a entrada do repositor na memoria ate a definicao de alguma alteracao
 entradas
   alteracao : entrada do repositor a ser armazenada na memoria
 saidas
   nenhuma
*************************/
extern void dis_armazenarAlteracao(int alteracao);

/************************
 dis_definirTroco10
 Define a quantidade de moedas de 10 centavos disponiveis para troco como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void dis_definirTroco10();

/************************
 dis_definirTroco25
 Define a quantidade de moedas de 25 centavos disponiveis para troco como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void dis_definirTroco25();

/************************
 dis_definirTroco50
 Define a quantidade de moedas de 50 centavos disponiveis para troco como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void dis_definirTroco50();

/************************
 dis_definirTroco100
 Define a quantidade de moedas de 1 real disponiveis para troco como a informacao digitada pelo repositor armazenada na memoria
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
extern void dis_definirTroco100();


#endif // DISPENSER_TROCO_H_INCLUDED
