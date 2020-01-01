#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include "menu.h"
#include "game.h"

char url[]="ranking.txt";
FILE *ranking;

char url2[]="id.txt";
FILE *id;

struct player
{
    char name[15];
    int pontuacao;
} jogador[10];

int pos =4500, posicao=0; // posicoes

int ID = 0; // ID de cada jogador

int m,n, r; // i e j, o r eh p resetar o vetor

int lin = 3; // linha para organizar na tabela

int rank[10] = {0}; // rank ordenado

void set_ranking()
{
    for (r=0; r<10; r++) // reseta o vetor do ranking
    {
        gotoxy(4,lin);
        printf("Jogador %2d",posicao+1);
        gotoxy(35,lin);
        printf("%3d", pos);
        rank[r] = pos;
        pos-=500;
        posicao++;
        lin+=2;
    }
    pos=4500;
    posicao=0;
    lin=3;
}

void last_player()
{
    ranking = fopen(url, "r");
    if(ranking == NULL)
        printf("");
    else
    {
        while (fread(&jogador[ID], sizeof(struct player), 1, ranking) == 1)
        {
            {
                gotoxy(73,18);
                printf("              ");
                gotoxy(73,21);
                printf("              ");

                gotoxy(73,17);
                printf("Ultimo a jogar:");
                gotoxy(73,18);
                printf("%s\n", jogador[ID].name);
                gotoxy(73,20);
                printf("Pontuacao:");
                gotoxy(73,21);
                printf("%03d\n",jogador[ID].pontuacao);
            }
        }
    }
    fclose(ranking);
    for (r=0; r<10; r++) // reseta o vetor
    {
        rank[r] = 0;
    }
}

void view_player() // arquivo jogadores
{
    id = fopen(url2,"r");
    if(id == NULL)
        printf(" ");
    else
    {
        fscanf(id,"%d",&ID);
    }
    fclose(id);


    ranking = fopen(url, "r");
    if(ranking == NULL)
        printf("");
    else
    {
        while (fread(&jogador[ID], sizeof(struct player), 1, ranking) == 1)
        {


            if (jogador[ID].pontuacao>=rank[0])
            {
                gotoxy(4,3);
                printf("               ");
                gotoxy(35,3);
                printf("    ");


                rank[0] = jogador[ID].pontuacao;
                gotoxy(4,3);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,3);
                printf("%03d\n",rank[0]);
            }
            if (jogador[ID].pontuacao>=rank[1] && jogador[ID].pontuacao < rank[0])
            {
                gotoxy(4,5);
                printf("               ");
                gotoxy(35,5);
                printf("    ");

                rank[1] = jogador[ID].pontuacao;
                gotoxy(4,5);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,5);
                printf("%03d\n",rank[1]);
            }
            if (jogador[ID].pontuacao>=rank[2] && jogador[ID].pontuacao < rank[1])
            {
                gotoxy(4,7);
                printf("               ");
                gotoxy(35,7);
                printf("    ");

                rank[2] = jogador[ID].pontuacao;
                gotoxy(4,7);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,7);
                printf("%03d\n",rank[2]);
            }
            if (jogador[ID].pontuacao>=rank[3] && jogador[ID].pontuacao < rank[2])
            {
                gotoxy(4,9);
                printf("               ");
                gotoxy(35,9);
                printf("    ");

                rank[3] = jogador[ID].pontuacao;
                gotoxy(4,9);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,9);
                printf("%03d\n",rank[3]);
            }
            if (jogador[ID].pontuacao>=rank[4] && jogador[ID].pontuacao < rank[3])
            {
                gotoxy(4,11);
                printf("               ");
                gotoxy(35,11);
                printf("    ");

                rank[4] = jogador[ID].pontuacao;
                gotoxy(4,11);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,11);
                printf("%03d\n",rank[4]);
            }
            if (jogador[ID].pontuacao>=rank[5] && jogador[ID].pontuacao < rank[4])
            {
                gotoxy(4,13);
                printf("               ");
                gotoxy(35,13);
                printf("    ");

                rank[5] = jogador[ID].pontuacao;
                gotoxy(4,13);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,13);
                printf("%03d\n",rank[5]);
            }
            if (jogador[ID].pontuacao>=rank[6] && jogador[ID].pontuacao < rank[5])
            {
                gotoxy(4,15);
                printf("               ");
                gotoxy(35,15);
                printf("    ");

                rank[6] = jogador[ID].pontuacao;
                gotoxy(4,15);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,15);
                printf("%03d\n",rank[6]);
            }
            if (jogador[ID].pontuacao>=rank[7] && jogador[ID].pontuacao < rank[6])
            {
                gotoxy(4,17);
                printf("               ");
                gotoxy(35,17);
                printf("    ");

                rank[7] = jogador[ID].pontuacao;
                gotoxy(4,17);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,17);
                printf("%03d\n",rank[7]);
            }
            if (jogador[ID].pontuacao>=rank[8] && jogador[ID].pontuacao < rank[7])
            {
                gotoxy(4,19);
                printf("               ");
                gotoxy(35,19);
                printf("    ");

                rank[8] = jogador[ID].pontuacao;
                gotoxy(4,19);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,19);
                printf("%03d\n",rank[8]);
            }
            if (jogador[ID].pontuacao>=rank[9] && jogador[ID].pontuacao < rank[8])
            {
                gotoxy(4,21);
                printf("               ");
                gotoxy(35,21);
                printf("    ");

                rank[9] = jogador[ID].pontuacao;
                gotoxy(4,21);
                printf("%s\n", jogador[ID].name);
                gotoxy(35,21);
                printf("%03d\n",rank[9]);
            }

        }
    }
    fclose(ranking);
    for (r=0; r<10; r++) // reseta o vetor
    {
        rank[r] = 0;
    }
}

void save_player(char nome_jogador[15], int total_pontos)
{
    id = fopen(url2,"r");
    if(id == NULL)
        printf(" ");
    else
    {
        fscanf(id,"%d",&ID);
    }
    fclose(id);

    ranking = fopen(url, "a");
    if(ranking == NULL)
        printf("");
    else
    {
        strcpy(jogador[ID].name,nome_jogador);
        jogador[ID].pontuacao = total_pontos;
        fwrite(&jogador[ID], sizeof(struct player), 1, ranking);
        ID++;
    }
    fclose(ranking);

    id = fopen(url2, "w");
    if(id == NULL)
        printf("");
    else
    {
        fprintf(id,"%d",ID);
    }
    fclose(id);
}

void table() // tabela de ranking

{
    system("cls");

    for(m=0; m<23; m++)
    {

        for(n=0; n<50; n++)
        {
            if(m==0 && n==0) // borda superior esquerda
            {
                putchar(201);
            }
            else if (m==0 && n==49) // borda superior direita
            {
                putchar(187);
            }
            else if (m==22 && n==0) // borda inferior esquerda
            {
                putchar(200);
            }
            else if (m==22 && n==49) // borda inferior direita
            {
                putchar(188);
            }
            else if (m%2==0 && n==0)
            {
                putchar(204);
            }
            else if (m%2==0 && n==49)
            {
                putchar(185);
            }
            else if (m==0 && n==26)
            {
                putchar(203);
            }
            else if (m==22 && n==26)
            {
                putchar(202);
            }
            else if (m%2==0 && n==26)
            {
                putchar(206);
            }
            else if (m==0 || (m%2==0 && n>=1 && n<=48)) //delimitacoes horizontais
            {
                putchar(205);
            }
            else if (n==0 || (m%2!=0 && n==9 && m>1 && m<21) || (m==21 && n==8)|| (m==1 && n==10)) // delimitacoes verticais
            {
                putchar(186);
            }
            else if (m==1 && n==1)
            {
                printf("\t  JOGADOR ");
            }
            else if (m==1 && n==18)
            {
                printf("PONTUACAO      %c",186);
            }
            else if (m%2!=0 && n==1 && m>1)
            {
                printf("%d)                ",posicao+1);
                posicao++;
            }
            else if ((m%2!=0 && n==18 && m>1 && m<21) || (m%2!=0 && n==17 && m==21))
                printf("     pts      %c",186);
            else
                printf(" ");
        }
        printf("\n");
    }
    posicao = 0;
}

void disp_ranking()

{
    table();
    set_ranking();
    view_player();
    gotoxy(0,24);
    printf("Pressione qualquer tecla para retornar");
    system("PAUSE>>null");

    system("cls");
    main_menu();
}
