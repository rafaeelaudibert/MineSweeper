/* PROGRAMA-BASE PARA O TRABALHO FINAL DA CADEIRA DE ALGORITMOS E PROGRAMAÇÃO

    O jogo a ser implementado é uma adaptação do jogo MineSweeper (Campo Minado), para C, utilizando
    caracteres ASCII e funções padrões do C, além da possível utilização de bibliotecas especiais como
    conio.h (Windows) ou ncurses.h (Linux)

*/


#include "constantes.h"
#include "theGame.h"

int main()
{

    COORD selecao;
    selecao.X = 8;
    selecao.Y = 4;

    //Pré-setting
    cursorType(0);
    srand(time(NULL)); //Seta a seed do aleatorio como o tempo;

    //Popula o mapa com as bombas
    populateMap();

    //Printa ele na tela
    revelaMapa();

    do{
        controller(&selecao);
    }while(1);



    return 0;
}

