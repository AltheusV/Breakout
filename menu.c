#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // Para funcao hideCursor();
#include "game.h"
#include "secret.h"
#include "ranking.h"


char selecionar; // variavel para selecionar opcao do usuario

int count = 0; // contador

void main_menu(); // funcao do menu
void select_menu(); // Faz com que o usuario selecione uma opcao

// funcao para colocar cor
void textcolor(int cor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cor);
}

//Esconde o cursor
void hideCursor()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO i;
    i.dwSize = 100;
    i.bVisible = FALSE;
    SetConsoleCursorInfo(console, &i);
}

void disp_menu() // mostra o menu na tela //
{
    printf("\n\n");

    textcolor(9);
    printf("\t\t _|_|_|    _|_|_|    _|_|_|_|    _|_|    _|    _|    _|_|    _|    _|  _|_|_|_|_|\n");
    textcolor(10);
    printf("\t\t _|    _|  _|    _|  _|        _|    _|  _|  _|    _|    _|  _|    _|      _|\n");
    textcolor(9);
    printf("\t\t _|_|_|    _|_|_|    _|_|_|    _|_|_|_|  _|_|      _|    _|  _|    _|      _|\n");
    textcolor(10);
    printf("\t\t _|    _|  _|    _|  _|        _|    _|  _|  _|    _|    _|  _|    _|      _|\n");
    textcolor(9);
    printf("\t\t _|_|_|    _|    _|  _|_|_|_|  _|    _|  _|    _|    _|_|      _|_|        _|\n\n\n");

    textcolor(15);
    printf("\t\t\t             _____________________________________\n");
    printf("\t\t\t            |                                     |\n");
    printf("\t\t\t            |- - - - - - - BREAKOUT - - - - - - - |\n");
    printf("\t\t\t            |_____________________________________|\n\n\n");
    printf("\t\t\t             _____________________________________\n");
    printf("\t\t\t            |                                     |\n");
    count == 0 ? printf("\t\t\t            |         >>    JOGAR                 |\n") : printf("\t\t\t            |               JOGAR                 |\n");
    count == 1 ? printf("\t\t\t            |         >>    INSTRUCOES            |\n") : printf("\t\t\t            |               INSTRUCOES            |\n");
    count == 2 ? printf("\t\t\t            |         >>    CREDITOS              |\n") : printf("\t\t\t            |               CREDITOS              |\n");
    count == 3 ? printf("\t\t\t            |         >>    RANKING               |\n") : printf("\t\t\t            |               RANKING               |\n");
    count == 4 ? printf("\t\t\t            |         >>    SAIR                  |\n") : printf("\t\t\t            |               SAIR                  |\n");
    printf("\t\t\t            |_____________________________________|\n\n");
}

void instrucoes() // instrucoes do jogo
{

    system("cls");

    printf("\n\n\n\n\n\t\tO objetivo do jogo eh destruir todos os blocos e nao deixar a bola cair. \n\n");
    printf("\t\tPressione a tecla 'A' para mover para esquerda e a tecla 'D' para mover para direita. \n\n");
    printf("\t\tPara pausar durante o jogo, pressione a tecla enter. \n\n");
    printf("\t\tDica: Tente sempre acompanhar a bola, segurando as teclas. \n\n");

    printf("\n\t\tPressione enter para retornar ao menu. \n\n");

    do
    {
        selecionar = getch();
    }
    while(selecionar != 13);

    main_menu();

}

void creditos() // Creditos
{
    system("cls");

    printf("\n\t Projeto de LPI - BREAKOUT \n");
    printf(" \t Professor: Joabe Jesus\n\n");
    printf(" \t Grupo: \n\n");
    printf(" \t Matheus Albert \n");
    printf(" \t Patrick Ramos \n");
    printf(" \t Rafael Lucena \n\n\n");

    printf(" \t Pressione enter para retornar ao menu. \n\n\n");

    printf("\t S ?");

    do
    {
        selecionar = getch();
    }
    while(selecionar != 13 && selecionar != 'S' && selecionar !='s');

    if (selecionar == 's' || selecionar == 'S')
    acesso();
    else
    main_menu();
}

void main_menu() // funcao do menu
{
    disp_menu();
    select_menu();
}

void select_menu() // Seleciona a opcao do usuario //
{
    count = 0;
    hideCursor();
    do
    {
        system("cls");
        disp_menu();
        selecionar = getch(); // espera o usuario digitar o comando //
        switch (selecionar)
        {
        case 72: // caso seja a seta para baixo
            count--;
            break;
        case 80: // caso seja a seta para cima
            count++;
            break;
        case 13: // caso seja enter
            if (count==0) // comeca o jogo
            {
                system("cls");
                game();
            }

            if (count==1) // acessa as instrucoes
            {
                instrucoes();
            }
            if (count==2) // Creditos
            {
                creditos();
            }
            if (count==3) // ranking
            {
                disp_ranking();
            }
            if (count==4) // sair
            {
                system("cls");
                textcolor(12);
                printf("Por que saiu?");
            }
            break;
        }
        if (count < 0)
            count = 4;
        else if (count > 4)
            count = 0;

    }
    while (selecionar !=13 ); // Repete até o usuario pressionar enter.
}

