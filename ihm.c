#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "ihm.h"

/************************
 ihm_exibirMsg
 Exibe mensagem no display
 entradas
   texto : texto para exibir no display
 saidas
   nenhuma
*************************/
void ihm_exibirMsg(char* texto)
{
    printf("Mensagem para display: %s", texto);
}


/************************
 ihm_obterTecla
 Obtem tecla do teclado
 entradas
   nenhuma
 saidas
   teclas lidas do teclado
*************************/
char buf[10];
char* ihm_obterTeclas()
{
    printf("obter teclas:");
    scanf("%s", buf);
    return buf;
}
