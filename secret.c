#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "secret.h"
#include "game.h"

char usuario[6], senha[3];

int tentativa = 0;

void acesso() // Acessa o conteudo secreto
{
    tentativa = 2;
    system("cls");
    printf("OPA! VOCE ACHOU O MENU SECRETO \n\n");
    printf("Para acessar o conteudo secreto, faca o login: \n\n");

    do
    {
        fflush(stdin);
        printf("Usuario: \n");
        gets(usuario);

        printf("Senha: \n");
        gets(senha);

        if ((strcmp (usuario, "JOABE") != 0) || (strcmp (senha, "10") != 0)) // <- USUARIO (NOME DO PROFESSOR) / SENHA (NOSSA NOTA NO PROJETO)
        {
            if (tentativa == 0)
            {
                system("cls");
                printf("Dica: \n\n1) Primeiro nome (MAIUSCULO) do professor da cadeira de LPI (UPE - 2017) \n\n2) Nota do nosso projeto (2 DIGITOS)\n\n");
                printf("Pressione qualquer tecla: ");
                system("PAUSE>>null");
                break;
            }
            else
            {
            system("cls");
            tentativa--;
            printf("Usuario ou senha Incorretos. \n\n");
            printf("Tentativas restantes: %d \n\n",tentativa+1);
            }

        }
    }
    while(strcmp (usuario, "JOABE") != 0 || strcmp (senha, "10") != 0);

    if (strcmp (usuario, "JOABE") == 0 && strcmp (senha, "10") == 0)
    {
        reprovout();
    }
}


