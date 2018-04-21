#include "theGame.h"
#include "mapa.h"

void controller(COORD *posicao){

    char key;

    //Printagem inicial do quadradinho de selecao
    gotoXY(posicao->X, posicao->Y);
    textcolor(BRANCO);
    printf("%c", SELECAO);

    if(getch()) //When a key is stroked
        {
            // Apaga a posicao anterior
            gotoXY(posicao->X, posicao->Y);
            printf(" ");
            revelaPosicao(&map[posicao->Y - 4][(posicao->X - 8)/2], 0);

            key = toupper(detectKey()); //Detects pressed key
            switch(key){
            case 'W':
                posicao->Y--;
                break;
            case 'S':
                posicao->Y++;
                break;
            case 'A':
                posicao->X-=2;
                break;
            case 'D':
                posicao->X+=2;
                break;
            }

            if(key=='W' || key=='S' || key=='A' || key=='D'){
                // Verifica as bordas do mapa
                if(posicao->X > MAP_SIZE*2 + 6){
                    posicao->X-=2;
                } else if (posicao->X < 8){
                    posicao->X+=2;
                } else if (posicao->Y > MAP_SIZE + 3){
                    posicao->Y--;
                } else if (posicao->Y < 4){
                    posicao->Y++;
                }
                gotoXY(posicao->X, posicao->Y);
                textcolor(BRANCO);
                printf("%c", SELECAO);
            } else if(key==' '){
                revelaPosicao(&map[posicao->Y - 4][(posicao->X - 8)/2], 1);
            } else if (key=='E'){
                map[posicao->Y - 4][(posicao->X - 8)/2].marcado = 1;
                revelaPosicao(&map[posicao->Y - 4][(posicao->X - 8)/2], 0);
            }


        }

    return;
}
