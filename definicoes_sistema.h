#ifndef DEFINICOES_SISTEMA_H_INCLUDED
#define DEFINICOES_SISTEMA_H_INCLUDED

#define true  1
#define false 0


#define NUM_ESTADOS 17
#define NUM_EVENTOS 16

// ESTADOS
#define ESPERANDO                           0
#define ESPERANDO_DINHEIRO                  1
#define VERIFICA_DISPONIBILIDADE_PRODUTO    2
#define VERIFICA_PAGAMENTO                  3
#define VERIFICA_DISPONIBILIDADE_TROCO      4
#define LIBERACAO_PRODUTO                   5
#define LIBERACAO_TROCO                     6
#define ESPERANDO_ESCOLHA                   8
#define ESPERANDO_POSICAO_CADASTRO          9
#define ESPERANDO_PRECO_CADASTRO            10
#define ESPERANDO_QUANTIDADE_CADASTRO       11
#define ESPERANDO_TROCO_10                  12
#define ESPERANDO_TROCO_25                  13
#define ESPERANDO_TROCO_50                  14
#define ESPERANDO_TROCO_100                 15
#define DEVOLVENDO_DINHEIRO                 16


// EVENTOS
#define NENHUM_EVENTO           -1
#define INSERE_DINHEIRO         0
#define SELECIONA_PRODUTO       1
#define PAGAMENTO_INSUFICIENTE  2
#define PAGAMENTO_SUFICIENTE    3
#define CANCELA_COMPRA          4
#define PRODUTO_DISPONIVEL      5
#define PRODUTO_INDISPONIVEL    6
#define TROCO_DISPONIVEL        7
#define TROCO_INDISPONIVEL      8
#define LIBERA_PRODUTO          9
#define LIBERA_TROCO            10
#define DINHEIRO_DEVOLVIDO      11
#define ALTERA_CHAVE            12
#define ALTERACAO_REPOSITOR     13
#define ESCOLHE_CADASTRO        14
#define ESCOLHE_TROCO           15

// ACOES
#define NENHUMA_ACAO -1
#define A01  0
#define A02  1
#define A03  2
#define A04  3
#define A05  4
#define A06  5
#define A07  6
#define A08  7
#define A09  8
#define A10  9
#define A11  10
#define A12  11
#define A13  12
#define A14  13
#define A15  14
#define A16  15
#define A17  16
#define A18  17
#define A19  18
#define A20  19
#define A21  20
#define A22  21

#endif // DEFINICOES_SISTEMA_H_INCLUDED