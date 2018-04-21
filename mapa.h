#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "constantes.h"
#include "auxiliars.h"
#include "movement.h"

#ifndef STRUCTS
#define STRUCTS a //PLACEHOLDER

struct bomba
{
    int x;
    int y;
    int bomba;
    int status;
    int vizinhos;
    int marcado;
} typedef Posicao;

Posicao map[MAP_SIZE][MAP_SIZE]; //Array que guarda o mapa do jogo

#endif // STRUCTS


// FUNCTIONS
void populateMap(); //Fun��o que povoa o mapa
void contaVizinhos();
void printaContorno();
void acheiBomba();
int hasBomb(Posicao); //Fun��o que retorna se tem uma bomba no local
int revelaPosicao(Posicao*, int); //Revela o mapa, na posi��o clicada. Retorna 1 se havia uma bomba no local.
//@TODO: ^ Se necessario, fazer expandir a area revelada


//Fun��es para debug
void revelaMapa();


//Fun��es da conio
void textcolor(int newcolor);
