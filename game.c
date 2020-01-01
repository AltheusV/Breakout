#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "menu.h"
#include "ranking.h"


#define linhas 25
#define colunas 90

char movimento, pausar; // movimento do usuario para mudar a posicao da barra, pausa caso o usuario queira

char matrix [linhas][colunas]; // matriz do jogo

char barra [21][69]; // matriz da barra

char nome[13] = {0}; // nome do usuario

char bloco[24] = {0}; // matriz dos blocos

int count; // preenche os blocos com valor 0 (para caso o usuario queira jogar uma nova partida)

int limdir = 0, limesq = 0; // limites da barra (pontas)

int i,j,z; // Variaveis para criar a matriz e um z

int x,y, horizontal = 0, vertical = 0; // direcao e sentido da bola

int pontos = 0, total = 0, multiplicador = 0; // quantidade de pontos

int life, qtd_blocos; // vidas e a quantidade de blocos


void gotoxy(int x, int y) // funcao para mudar as coordenadas do cursor
{
    COORD c;

    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void bar() // define os limites iniciais da barra e sua posicao.
{
    limesq = 27;
    limdir = 41;
}

void disp_bar() // mostra a barra na tela
{
    for (i=0; i<=21; i++)
    {
        for(j=0; j<=69; j++)
        {
            if (j< limesq || j>limdir)
                barra[i][j] = ' ';
            if (i==21 && j==0)
                barra[i][j] = 186;
            if (i == 21)
            {
                textcolor(15);
                printf("%c", barra[i][j]);
            }
        }
        printf("\n");
    }
}

void disp_matrix() // mostra o tabuleiro na tela
{
    for (i=0; i<linhas; i++)
    {
        for (j=0; j<colunas; j++)
        {
            if(i==0 && j==0) // borda superior esquerda
            {
                matrix[i][j] = 201;
            }
            else if (i==0 && j==89) // borda superior direita
            {
                matrix[i][j] = 187;
            }
            else if (i==24 && j==0) // borda inferior esquerda
            {
                matrix[i][j] = 200;
            }
            else if (i==24 && j==89) // borda inferior direita
            {
                matrix[i][j] = 188;
            }
            else if (i==0 && j==70) // borda do meio superior
            {
                matrix[i][j] = 203;
            }
            else if (i==24 && j==70) // borda do meio inferior
            {
                matrix [i][j] = 202;
            }
            else if (i==0 || i==24) //delimitacoes horizontais
            {
                matrix [i][j] = 205;
            }
            else if (j==0 || j==89 || j==70 ) // delimitacoes verticais
            {
                matrix [i][j] = 186;
            }
            printf("%c",matrix[i][j]);
        }
        printf("\n");
    }
    gotoxy(0,0);
}

void move_bar(char move) /*faz o usuário mover a barra */
{

    if ((move == 'a' || move == 'A') && limesq>1 ) /*mover para esquerda */
    {
        barra[21][limdir] = ' ';
        limesq--;
        limdir--;
        barra[21][limesq] = 205;
    }
    else if ((move == 'd' || move == 'D') && limdir < 69) /*mover para direita */
    {
        barra[21][limesq] = ' ';
        limesq++;
        limdir++;
        barra[21][limdir] = 205;
    }
    else if (move == 13) // pausa o jogo
    {
        printf("\a");
        system("PAUSE>>null");
    }

    if (z==0) // Joabe?
    {
        gotoxy(limesq+2,22);
        putchar(' ');
        gotoxy(limesq+3,22);
        printf("J O A B E ");
    }

    gotoxy(0,0);
}

void user_info() // Mostra as informacoes do usuario
{
    gotoxy(76,2);
    printf("BREAKOUT");

    gotoxy(73,5);
    printf("Jogador:");

    gotoxy(73,6);
    printf("%s", nome);

    gotoxy(73,8);
    textcolor(14);
    printf("Pontuacao:");

    gotoxy(73,9);
    if (life==3)
        printf("%d pts",multiplicador=(pontos*life));
    else
        printf("%d pts", total+multiplicador);

    gotoxy(73,11);
    textcolor(10);
    printf("Vidas:");

    gotoxy(73,12);
    printf("%d", life);

    gotoxy(73,14);
    textcolor(12);
    printf("Multiplicador: ");

    gotoxy(73,15);
    printf("%d x %d = %d", life, pontos, multiplicador=(pontos*life));

    textcolor(11);
    last_player();

    textcolor(15);
}

void secret_info() // informacoes secretas?
{


    gotoxy(75,1);
    printf("REPR0V0UT");

    gotoxy(72,2);
    textcolor(12);
    printf("Reprovados: ");

    bloco[0] == 1 ? gotoxy(72,3),printf("Abner"): printf(" ");

    bloco[1] == 1 ? gotoxy(72,4),printf("Alex "): printf(" ");

    bloco[2] == 1 ? gotoxy(72,5),printf("Andre(s)"): printf(" ");

    bloco[3] == 1 ? gotoxy(72,6),printf("Bia"): printf(" ");

    bloco[4] == 1 ? gotoxy(72,7),printf("Clara"): printf(" ");

    bloco[5] == 1 ? gotoxy(72,8),printf("Charles"):printf(" ");

    bloco[6] == 1 ? gotoxy(72,9),printf("Daniel (s)"): printf(" ");

    bloco[7] == 1 ? gotoxy(72,10),printf("Davi"): printf(" ");

    bloco[8] == 1 ? gotoxy(72,11),printf("Dennys"): printf(" ");

    bloco[9] == 1 ? gotoxy(72,12),printf("Diego"): printf(" ");

    bloco[10] == 1 ? gotoxy(72,13),printf("Hiago"): printf(" ");

    bloco[11] == 1 ? gotoxy(72,14),printf("Julia"): printf(" ");

    bloco[12] == 1 ? gotoxy(72,15),printf("Joao(s)"): printf(" ");

    bloco[13] == 1 ? gotoxy(72,16),printf("Kildare"): printf(" ");

    bloco[14] == 1 ? gotoxy(72,17),printf("Lucas"): printf(" ");

    bloco[15] == 1 ? gotoxy(72,18),printf("Luiz"): printf(" ");

    bloco[17] == 1 ? gotoxy(72,19),printf("Nilton"): printf(" ");

    bloco[18] == 1 ? gotoxy(72,20),printf("Paulo"): printf(" ");

    bloco[19] == 1 ? gotoxy(72,21),printf("Pedro(s)"): printf(" ");

    bloco[22] == 1 ? gotoxy(72,22),printf("Vitor"): printf(" ");

    bloco[23] == 1 ? gotoxy(72,23),printf("Zenio"): printf(" ");

    textcolor(15);

    gotoxy(89,2);
    putchar(186);
    gotoxy(89,4);
    putchar(186);
    gotoxy(89,5);
    putchar(186);
    gotoxy(89,6);
    putchar(186);
    gotoxy(89,7);
    putchar(186);
    gotoxy(89,8);
    putchar(186);
    gotoxy(89,9);
    putchar(186);
}


void disp_block() // mostra os blocos na tela
{
    for (count=0; count<24; count++) // reinicia os blocos para caso o usuario jogue de novo
    {
        bloco[count] = 0;
    }

    count = 1;

    for (i=0; i<=24; i++)
        if (bloco[i]==0)
        {
            for(x=9; x<=54; x+=9)

            {
                for (y=3; y<=9; y+=2)
                {
                    gotoxy(x,y);
                    textcolor(count);
                    printf("%c%c%c%c%c",219,219,219,219,219);
                    count++;

                    if (count == 16)
                        count = 1;
                }
            }
        }

}

void secret_block() // mostra o blocos secretos na tela
{
    for (count=0; count<24; count++)
    {
        bloco[count] = 0;
    }

    if (bloco[0]== 0)
    {
        gotoxy(9,9);
        textcolor(49);
        printf("Abner");
    }

    if (bloco[1]== 0)
    {
        gotoxy(18,9);
        textcolor(20);
        printf("AlexE");
    }

    if (bloco[2]== 0)
    {
        gotoxy(27,9);
        textcolor(32);
        printf("Andre");
    }

    if (bloco[3]== 0)
    {
        gotoxy(36,9);
        textcolor(24);
        printf("BiaGi");
    }

    if (bloco[4]== 0)
    {
        gotoxy(45,9);
        textcolor(90);
        printf("Clara");
    }

    if (bloco[5]== 0)
    {
        gotoxy(54,9);
        textcolor(74);
        printf("Charl");
    }

    if (bloco[6]== 0)
    {
        gotoxy(9,3);
        textcolor(65);
        printf("DaniS");
    }

    if (bloco[7]== 0)
    {
        gotoxy(9,5);
        textcolor(44);
        printf("DaviM");
    }

    if (bloco[8]== 0)
    {
        gotoxy(9,7);
        textcolor(76);
        printf("Denys");
    }

    if (bloco[9]== 0)
    {
        gotoxy(18,3);
        textcolor(19);
        printf("Diego");
    }

    if (bloco[10]== 0)
    {
        gotoxy(18,5);
        textcolor(116);
        printf("Hiago");
    }

    if (bloco[11]== 0)
    {
        gotoxy(18,7);
        textcolor(58);
        printf("Julia");
    }

    if (bloco[12]== 0)
    {
        gotoxy(27,3);
        textcolor(52);
        printf("Joaos");
    }

    if (bloco[13]== 0)
    {
        gotoxy(27,5);
        textcolor(36);
        printf("Kilda");
    }

    if (bloco[14]== 0)
    {
        gotoxy(27,7);
        textcolor(143);
        printf("Lucas");
    }

    if (bloco[15]== 0)
    {
        gotoxy(36,3);
        textcolor(43);
        printf("LuizN");
    }

    if (bloco[16]== 0)
    {
        gotoxy(36,5);
        textcolor(656);
        printf("Mathe");
    }

    if (bloco[17]== 0)
    {
        gotoxy(36,7);
        textcolor(152);
        printf("Nilto");
    }

    if (bloco[18]== 0)
    {
        gotoxy(45,3);
        textcolor(125);
        printf("Paulo");
    }

    if (bloco[19]== 0)
    {
        gotoxy(45,5);
        textcolor(96);
        printf("Pedro");
    }

    if (bloco[20]== 0)
    {
        gotoxy(45,7);
        textcolor(76);
        printf("RafaL");
    }

    if (bloco[21]== 0)
    {
        gotoxy(54,3);
        textcolor(47);
        printf("Ramos");
    }

    if (bloco[22]== 0)
    {
        gotoxy(54,5);
        textcolor(151);
        printf("Vitor");
    }

    if (bloco[23]== 0)
    {
        gotoxy(54,7);
        textcolor(156);
        printf("Zenio");
    }
    textcolor(15);
}



void random_ball() // funcao para definir uma posicao randomica da bola
{
    srand( (unsigned)time(NULL) );
    x = 20 + ( rand() % 15 );
    y = 11;

}

void check_colisao_block(int inic_block,int final_block,int coord_y,int i)
{
    if ((x>=inic_block && x<=final_block)  && y==coord_y && bloco[i] ==0) //checa colisao
    {
        gotoxy(inic_block,coord_y);
        printf("     ");
        bloco[i] = 1;
        horizontal++;
        pontos+=100;
        qtd_blocos--;
    }
}

void ball() // funcao do movimento da bola e checa colisao
{

    gotoxy(x,y);
    putchar(' ');

    check_colisao_block( 9, 13, 9, 0);
    check_colisao_block( 18, 22, 9, 1);
    check_colisao_block( 27, 31, 9, 2);
    check_colisao_block( 36, 40, 9, 3);
    check_colisao_block( 45, 49, 9, 4);
    check_colisao_block( 54, 58, 9, 5);
    check_colisao_block( 9, 13, 3, 6);
    check_colisao_block( 9, 13, 5, 7);
    check_colisao_block( 9, 13, 7, 8);
    check_colisao_block( 18, 22, 3, 9);
    check_colisao_block( 18, 22, 5, 10);
    check_colisao_block( 18, 22, 7, 11);
    check_colisao_block( 27, 31, 3, 12);
    check_colisao_block( 27, 31, 5, 13);
    check_colisao_block( 27, 31, 7, 14);
    check_colisao_block( 36, 40, 3, 15);
    check_colisao_block( 36, 40, 5, 16);
    check_colisao_block( 36, 40, 7, 17);
    check_colisao_block( 45, 49, 3, 18);
    check_colisao_block( 45, 49, 5, 19);
    check_colisao_block( 45, 49, 7, 20);
    check_colisao_block( 54, 58, 3, 21);
    check_colisao_block( 54, 58, 5, 22);
    check_colisao_block( 54, 58, 7, 23);

    if (y==1 || ( y ==20 && x>=limesq && x <=limdir)) // rebate a bola
        horizontal++;

    if (y==23) // se a bola cair
    {
        life--;

        if (z==1)
        {
            gotoxy(73,15);
            printf("               ");
        }

        total+=multiplicador;
        pontos = 0;
        multiplicador = 0;

        vertical = 0;
        horizontal = 0;

        x = limesq+1;
        y = 11;

        gotoxy(x,y);
        z==1 ? putchar('O'): putchar('0');

        pausar = getch();

        gotoxy(x,y);
        putchar(' ');
    }

    if (x==1||x==69) // rebate a bola
    {
        vertical++;
    }

    if (horizontal%2==0)
        y++;
    else
        y--;

    if(vertical%2==0)
        x++;
    else
        x--;

    gotoxy(x,y);
    z==1 ? putchar('O'): putchar('0');
}

void redefinir() // redefine as variaveis para um novo jogo.
{
    total = 0;
    multiplicador = 0; // redefine o multiplicador
    pontos = 0; // redefine a pontuacao
    life = 3; // define vidas iniciais
    qtd_blocos = 24; // define blocos iniciais
    horizontal = 0; // variavel para o movimento da bola
    vertical = 0; // variavel para o movimento da bola
}

void game() // funcao do jogo
{
    z=1;
    redefinir();

    printf("Digite seu apelido: ");
    fgets(nome, 13, stdin);
    system("cls");


    bar();
    disp_matrix();
    disp_bar();
    disp_block();
    user_info();
    random_ball();
    do
    {
        user_info();
        if (kbhit())
        {
            movimento = getch();
            move_bar(movimento);
            disp_bar();
        }
        ball();
        Sleep(70);
    }
    while(life!=0 && qtd_blocos !=0);

    system("PAUSE>>null");

    if (life==0)
    {
        save_player(nome,total); // funcao do ranking que pega o nome e os pontos
        system("cls");
        textcolor(12);
        printf("FIM DO JOGO \n");
        system("pause");
        main_menu();
    }

    if (qtd_blocos == 0)
    {
        if (total==0 && qtd_blocos==0) // pontuacao maxima
        {
            total=7200;
        }

        save_player(nome,total);// colocar a funcao do ranking aqui, que pegue o nome e os pontos
        system("cls");
        textcolor(10);
        printf("VOCE VENCEU! \n");
        system("pause");
        main_menu();
    }

}

void reprovout() // o que seria isso?
{
    system("cls");
    z=0;
    redefinir();
    bar();
    disp_matrix();
    disp_bar();
    secret_block();
    secret_info();
    random_ball();
    do
    {
        secret_info();
        if (kbhit())
        {
            movimento = getch();
            move_bar(movimento);
            disp_bar();
        }
        ball();
        Sleep(70);
    }
    while(life!=0 && qtd_blocos !=0);

    system("PAUSE>>null");

    if (qtd_blocos == 0)
    {
        system("cls");

        textcolor(10);
        printf("Se seu nome nao estava aqui, nao se preocupe... \n\n");

        system("PAUSE>>null");

        textcolor(12);
        printf("VOCE TAMBEM IRA REPROVAR HAHAHAHAHA!\a \n");

        system("PAUSE>>null");
        main_menu();
    }

}
