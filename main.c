#include <stdio.h>
#include <stdlib.h>

/*
    VENDING MACHINE
*/

#include "definicoes_sistema.h"
#include "contador.h"
#include "ihm.h"
#include "atuadores.h"
#include "estoque.h"
#include "dispenser_troco.h"
#include "sensor_chave.h"

/***********************************************************************
 Estaticos
 ***********************************************************************/
  int codigoEvento;
  int codigoAcao;
  int estado;
  int acao_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
  int proximo_estado_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];

/************************************************************************
 executarAcao
 Executa uma acao
 Parametros de entrada:
    (int) codigo da acao a ser executada
 Retorno: (int) codigo do evento interno ou NENHUM_EVENTO
*************************************************************************/
int executarAcao(int codigoAcao)
{
    int retval;
    char dinheiro[5];
    retval = NENHUM_EVENTO;
    if (codigoAcao == NENHUMA_ACAO)
        return retval;

    char mensagem[100];

    switch(codigoAcao)
    {
    case A01:
        sprintf(mensagem, "Dinheiro inserido: %d\n", ctd_verificaPagamento());
        ihm_exibirMsg(mensagem);
        break;
    case A02:
        sprintf(mensagem, "Produto selecionado:\nProduto: %d\nPreco: %d\nQuantidade disponivel: %d\n", stq_idProduto() + 1, stq_precoProduto(), stq_qteProduto());
        ihm_exibirMsg(mensagem);
        if (stq_qteProduto() > 0)
        {
          return PRODUTO_DISPONIVEL;
        }
        return PRODUTO_INDISPONIVEL;
    case A03:
        ihm_exibirMsg("Pagamento insuficiente! Insira mais dinheiro ou aperte c para cancelar a compra\n");
        break;
    case A04:
        ihm_exibirMsg("Compra cancelada!\n");
        ctd_devolverMoedas();
        return DINHEIRO_DEVOLVIDO;
    case A05:
        ihm_exibirMsg("Produto indisponivel! Selecione outro produto ou aperte c para cancelar a compra\n");
        break;
    case A06:
        ihm_exibirMsg("Troco indisponivel para esse produto! Selecione outro produto ou aperte c para cancelar a compra\n");
        break;
    case A07:
        atd_ativar(stq_idProduto());
        stq_retirarProduto();
        ihm_exibirMsg("Insira moedas para comecar\n");
        return LIBERA_TROCO;
    case A08: // libera troco e armazena pagamento
        sprintf(mensagem, "Troco: %d\n", dis_verificarTroco());
        dis_dispensarTroco();
        ctd_armazenaDinheiro();
        ihm_exibirMsg(mensagem);
        break;
    case A09:
        return LIBERA_PRODUTO;
    case A10: // verifica se tem troco
        if (dis_calculaTroco(ctd_verificaPagamento(), stq_precoProduto()))
          return TROCO_DISPONIVEL;
        return TROCO_INDISPONIVEL;
    case A11: // verifica pagamento
        
        if (ctd_verificaPagamento() >= stq_precoProduto())
        {
          return PAGAMENTO_SUFICIENTE;
        }
        return PAGAMENTO_INSUFICIENTE;
    case A12:
        ihm_exibirMsg("Aperte p para cadastrar um produto novo ou t para informar o troco na maquina\n");
        break;
    case A13:
        ihm_exibirMsg("Digite a localizacao do produto novo\n");
        break;
    case A14:
        stq_definirPosicao();
        ihm_exibirMsg("Digite a quantidade disponivel do produto novo\n");
        break;
    case A15:
        stq_definirQuantidade();
        ihm_exibirMsg("Digite o preco desejado para o produto novo\n");
        break;
    case A16:
        stq_definirPreco();
        ihm_exibirMsg("Produto cadastrado!\n");
        break;
    case A17:
        ihm_exibirMsg("Digite a quantidade de moedas de 10 centavos disponiveis para troco\n");
        break;
    case A18:
        dis_definirTroco10();
        ihm_exibirMsg("Digite a quantidade de moedas de 25 centavos disponiveis para troco\n");
        break;
    case A19:
        dis_definirTroco25();
        ihm_exibirMsg("Digite a quantidade de moedas de 50 centavos disponiveis para troco\n");
        break;
    case A20:
        dis_definirTroco50();
        ihm_exibirMsg("Digite a quantidade de moedas de 1 real disponiveis para troco\n");
        break;
    case A21:
        dis_definirTroco100();
        ihm_exibirMsg("Troco cadastrado!\n");
        break;
    case A22:
        ihm_exibirMsg("Insira moedas para comecar\n");
        break;
    } // switch
    return retval;
} // executarAcao

/************************************************************************
 iniciaMaquina de Estados
 Carrega a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
void iniciaMaquinaEstados()
{
  int i;
  int j;

  for (i=0; i < NUM_ESTADOS; i++) {
    for (j=0; j < NUM_EVENTOS; j++) {
       acao_matrizTransicaoEstados[i][j] = NENHUMA_ACAO;
       proximo_estado_matrizTransicaoEstados[i][j] = i;
    }
  }
  proximo_estado_matrizTransicaoEstados[ESPERANDO][INSERE_DINHEIRO] = ESPERANDO_DINHEIRO;
  acao_matrizTransicaoEstados[ESPERANDO][INSERE_DINHEIRO] = A01;

  proximo_estado_matrizTransicaoEstados[ESPERANDO][ALTERA_CHAVE] = ESPERANDO_ESCOLHA;
  acao_matrizTransicaoEstados[ESPERANDO][ALTERA_CHAVE] = A12;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_DINHEIRO][INSERE_DINHEIRO] = ESPERANDO_DINHEIRO;
  acao_matrizTransicaoEstados[ESPERANDO_DINHEIRO][INSERE_DINHEIRO] = A01;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_DINHEIRO][SELECIONA_PRODUTO] = VERIFICA_DISPONIBILIDADE_PRODUTO;
  acao_matrizTransicaoEstados[ESPERANDO_DINHEIRO][SELECIONA_PRODUTO] = A02;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_DINHEIRO][CANCELA_COMPRA] = DEVOLVENDO_DINHEIRO;
  acao_matrizTransicaoEstados[ESPERANDO_DINHEIRO][CANCELA_COMPRA] = A04;

  proximo_estado_matrizTransicaoEstados[DEVOLVENDO_DINHEIRO][DINHEIRO_DEVOLVIDO] = ESPERANDO;
  acao_matrizTransicaoEstados[DEVOLVENDO_DINHEIRO][DINHEIRO_DEVOLVIDO] = A22;

  proximo_estado_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_PRODUTO][PRODUTO_INDISPONIVEL] = ESPERANDO_DINHEIRO;
  acao_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_PRODUTO][PRODUTO_INDISPONIVEL] = A05;

  proximo_estado_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_PRODUTO][PRODUTO_DISPONIVEL] = VERIFICA_PAGAMENTO;
  acao_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_PRODUTO][PRODUTO_DISPONIVEL] = A11;

  proximo_estado_matrizTransicaoEstados[VERIFICA_PAGAMENTO][PAGAMENTO_INSUFICIENTE] = ESPERANDO_DINHEIRO;
  acao_matrizTransicaoEstados[VERIFICA_PAGAMENTO][PAGAMENTO_INSUFICIENTE] = A03;

  proximo_estado_matrizTransicaoEstados[VERIFICA_PAGAMENTO][PAGAMENTO_SUFICIENTE] = VERIFICA_DISPONIBILIDADE_TROCO;
  acao_matrizTransicaoEstados[VERIFICA_PAGAMENTO][PAGAMENTO_SUFICIENTE] = A10;

  proximo_estado_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_TROCO][TROCO_INDISPONIVEL] = ESPERANDO_DINHEIRO;
  acao_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_TROCO][TROCO_INDISPONIVEL] = A06;

  proximo_estado_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_TROCO][TROCO_DISPONIVEL] = LIBERACAO_PRODUTO;
  acao_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_TROCO][TROCO_DISPONIVEL] = A09;
  
  proximo_estado_matrizTransicaoEstados[LIBERACAO_PRODUTO][LIBERA_PRODUTO] = LIBERACAO_TROCO;
  acao_matrizTransicaoEstados[LIBERACAO_PRODUTO][LIBERA_PRODUTO] = A07;
  
  proximo_estado_matrizTransicaoEstados[LIBERACAO_TROCO][LIBERA_TROCO] = ESPERANDO;
  acao_matrizTransicaoEstados[LIBERACAO_TROCO][LIBERA_TROCO] = A08;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_ESCOLHA][ESCOLHE_CADASTRO] = ESPERANDO_POSICAO_CADASTRO;
  acao_matrizTransicaoEstados[ESPERANDO_ESCOLHA][ESCOLHE_CADASTRO] = A13;
  
  proximo_estado_matrizTransicaoEstados[ESPERANDO_ESCOLHA][ESCOLHE_TROCO] = ESPERANDO_TROCO_10;
  acao_matrizTransicaoEstados[ESPERANDO_ESCOLHA][ESCOLHE_TROCO] = A17;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_ESCOLHA][ALTERA_CHAVE] = ESPERANDO;
  acao_matrizTransicaoEstados[ESPERANDO_ESCOLHA][ALTERA_CHAVE] = A22;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_POSICAO_CADASTRO][ALTERACAO_REPOSITOR] = ESPERANDO_QUANTIDADE_CADASTRO;
  acao_matrizTransicaoEstados[ESPERANDO_POSICAO_CADASTRO][ALTERACAO_REPOSITOR] = A14;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_POSICAO_CADASTRO][ALTERA_CHAVE] = ESPERANDO;
  acao_matrizTransicaoEstados[ESPERANDO_POSICAO_CADASTRO][ALTERA_CHAVE] = A22;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_QUANTIDADE_CADASTRO][ALTERACAO_REPOSITOR] = ESPERANDO_PRECO_CADASTRO;
  acao_matrizTransicaoEstados[ESPERANDO_QUANTIDADE_CADASTRO][ALTERACAO_REPOSITOR] = A15;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_QUANTIDADE_CADASTRO][ALTERA_CHAVE] = ESPERANDO;
  acao_matrizTransicaoEstados[ESPERANDO_QUANTIDADE_CADASTRO][ALTERA_CHAVE] = A22;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_PRECO_CADASTRO][ALTERACAO_REPOSITOR] = ESPERANDO_ESCOLHA;
  acao_matrizTransicaoEstados[ESPERANDO_PRECO_CADASTRO][ALTERACAO_REPOSITOR] = A16;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_PRECO_CADASTRO][ALTERA_CHAVE] = ESPERANDO;
  acao_matrizTransicaoEstados[ESPERANDO_PRECO_CADASTRO][ALTERA_CHAVE] = A22;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_TROCO_10][ALTERACAO_REPOSITOR] = ESPERANDO_TROCO_25;
  acao_matrizTransicaoEstados[ESPERANDO_TROCO_10][ALTERACAO_REPOSITOR] = A18;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_TROCO_10][ALTERA_CHAVE] = ESPERANDO;
  acao_matrizTransicaoEstados[ESPERANDO_TROCO_10][ALTERA_CHAVE] = A22;
  
  proximo_estado_matrizTransicaoEstados[ESPERANDO_TROCO_25][ALTERACAO_REPOSITOR] = ESPERANDO_TROCO_50;
  acao_matrizTransicaoEstados[ESPERANDO_TROCO_25][ALTERACAO_REPOSITOR] = A19;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_TROCO_25][ALTERA_CHAVE] = ESPERANDO;
  acao_matrizTransicaoEstados[ESPERANDO_TROCO_25][ALTERA_CHAVE] = A22;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_TROCO_50][ALTERACAO_REPOSITOR] = ESPERANDO_TROCO_100;
  acao_matrizTransicaoEstados[ESPERANDO_TROCO_50][ALTERACAO_REPOSITOR] = A20;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_TROCO_50][ALTERA_CHAVE] = ESPERANDO;
  acao_matrizTransicaoEstados[ESPERANDO_TROCO_50][ALTERA_CHAVE] = A22;
  
  proximo_estado_matrizTransicaoEstados[ESPERANDO_TROCO_100][ALTERACAO_REPOSITOR] = ESPERANDO_ESCOLHA;
  acao_matrizTransicaoEstados[ESPERANDO_TROCO_100][ALTERACAO_REPOSITOR] = A21;

  proximo_estado_matrizTransicaoEstados[ESPERANDO_TROCO_50][ALTERA_CHAVE] = ESPERANDO;
  acao_matrizTransicaoEstados[ESPERANDO_TROCO_50][ALTERA_CHAVE] = A22;
} // initStateMachine

/************************************************************************
 iniciaSistema
 Inicia o sistema ...
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
void iniciaSistema()
{
   iniciaMaquinaEstados();
   stq_inicializarProdutos();
   dis_inicializaTroco(100);
} // initSystem


/************************************************************************
 obterEvento
 Obtem um evento, que pode ser da IHM ou da vending machine
 Parametros de entrada: nenhum
 Retorno: codigo do evento
*************************************************************************/
char* teclas;

int decodificarMoedas()
{
    if (snr_estaAtivo())
      return false;
    
    if (teclas[0] == '1')
    {
      ctd_inserirPagamento(10); 
      return true;
    } // 1: 10 centavos

    if (teclas[0] == '2')
    {
      ctd_inserirPagamento(25);
      return true;
    } // 2: 25 centavos

    if (teclas[0] == '3')
    {
      ctd_inserirPagamento(50);
      return true;
    } // 3: 50 centavos
    
    if (teclas[0] == '4')
    {
      ctd_inserirPagamento(100);
      return true;
    } // 4: 1 real

    return false;
} // decodificarMoedas

int decodificarCancelar()
{
    if (teclas[0] == 'c')
        return true;

    return false;
} // decodificarCancelar

int decodificarProduto()
{
    if (!(snr_estaAtivo()) && teclas[0] == 'p')
    {
        stq_escolherProduto(atoi(teclas + 1) - 1);
        return true;
    }
    return false;
} // decodificarProduto

int decodificarChave()
{
    if (teclas[0] == 'k')
    {
        snr_alterarSinal();
        return true;
    }
    return false;
} // decodificarChave

int decodificaAlteracao()
{
  if (snr_estaAtivo())
  {
    dis_armazenarAlteracao(atoi(teclas));
    stq_armazenarAlteracao(atoi(teclas));
    return true;
  }
  return false;
} // decodificaAlteracao

int decodificaCadastro()
{
  if (snr_estaAtivo() && teclas[0] == 'p')
    return true;

  return false;
} // decodificaCadastro

int decodificaTroco()
{
  if (snr_estaAtivo() && teclas[0] == 't')
    return true;

  return false;
} // decodificaTroco

int obterEvento()
{
  int retval = NENHUM_EVENTO;

  teclas = ihm_obterTeclas();

  if (decodificarMoedas())
    return INSERE_DINHEIRO;
  if (decodificarProduto())
    return SELECIONA_PRODUTO;
  if (decodificarCancelar())
    return CANCELA_COMPRA;
  if (decodificarChave())
    return ALTERA_CHAVE;
  if (decodificaTroco())
    return ESCOLHE_TROCO;
  if (decodificaCadastro())
    return ESCOLHE_CADASTRO;
  if (decodificaAlteracao())
    return ALTERACAO_REPOSITOR;

  return retval;

} // obterEvento

/************************************************************************
 obterAcao
 Obtem uma acao da Matriz de transicao de estados
 Parametros de entrada: estado (int)
                        evento (int)
 Retorno: codigo da acao
*************************************************************************/
int obterAcao(int estado, int codigoEvento) {
  return acao_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao


/************************************************************************
 obterProximoEstado
 Obtem o proximo estado da Matriz de transicao de estados
 Parametros de entrada: estado (int)
                        evento (int)
 Retorno: codigo do estado
*************************************************************************/
int obterProximoEstado(int estado, int codigoEvento) {
  return proximo_estado_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao


/************************************************************************
 Main
 Loop principal de controle que executa a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
int main() {

  int codigoEvento;
  int codigoAcao;
  int estado;
  int eventoInterno;

  estado = ESPERANDO;
  eventoInterno = NENHUM_EVENTO;

  iniciaSistema();
  printf ("Vending Machine iniciada\n");
  ihm_exibirMsg("Insira moedas para comecar\n");
  while (true) {
    if (eventoInterno == NENHUM_EVENTO) {
        codigoEvento = obterEvento();
    } else {
        codigoEvento = eventoInterno;
    }
    if (codigoEvento != NENHUM_EVENTO)
    {
       codigoAcao = obterAcao(estado, codigoEvento);
       estado = obterProximoEstado(estado, codigoEvento);
       eventoInterno = executarAcao(codigoAcao);
       printf("Estado: %d Evento: %d Acao:%d\n", estado, codigoEvento, codigoAcao);
    }
  } // while true
} // main
