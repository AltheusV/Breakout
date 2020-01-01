#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#endif // GAME_H_INCLUDED


void gotoxy(int x, int y); // funcao para mudar as coordenadas
void bar(); // define os limites iniciais da barra e sua posicao.
void disp_bar(); // mostra a barra na tela
void disp_matrix(); // mostra o tabuleiro na tela
void disp_block(); // mostra os blocos na tela
void move_bar(char move); /*faz o usuário mover a barra */
void ball(); // funcao do movimento da bola e checa colisao
void check_colisao_block(int inic_block,int final_block,int coord_y,int i);
void user_info(); // mostra as informacoes do usuario
void random_ball(); // funcao para definir uma posicao randomica da bola
void redefinir(); // redefine as variaveis (pontos, vida etc)
void game(); // funcao do jogo

// nao sei oq eh isso

void reprovout();
void secret_block();
void secret_info();

