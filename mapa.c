#include "mapa.h"
#include "constantes.h"

void populateMap()
{

    int i, j, x, y, countBombas = 0;

    // Zera os valores importantes
    for(i=0; i < MAP_SIZE; i++)
    {
        for (j=0; j < MAP_SIZE; j++)
        {
            map[i][j].x = i;
            map[i][j].y = j;
            map[i][j].bomba = 0;
            map[i][j].status = 0;
            map[i][j].marcado = 0;
        }
    }

    // Insere as bombas
    do
    {
        //Gera posicoes x e y aleatorias para a bomba
        x = rand() % MAP_SIZE;
        y = rand() % MAP_SIZE;

        //Caso não tenha uma bomba lá, coloca uma
        if (!hasBomb(map[x][y]))
        {
            map[x][y].bomba = 1; //Coloca uma bomba no lugar
            countBombas++; //Aumenta a quantidade de bombas
        }
    }
    while(countBombas < MAP_SIZE * MULTIPLICADOR_BOMBAS);

    // Calcula os vizinhos
    contaVizinhos();

    return;
}

void contaVizinhos()
{

    int i, j;

    //Cantos
    map[0][0].vizinhos        = map[0][1].bomba + map[1][1].bomba + map[1][0].bomba;
    map[0][MAP_SIZE-1].vizinhos = map[0][MAP_SIZE-2].bomba + map[1][MAP_SIZE-2].bomba + map[1][MAP_SIZE-1].bomba;
    map[MAP_SIZE-1][0].vizinhos = map[MAP_SIZE-2][0].bomba + map[MAP_SIZE-2][1].bomba + map[MAP_SIZE-1][1].bomba;
    map[MAP_SIZE-1][MAP_SIZE-1].vizinhos = map[MAP_SIZE-2][MAP_SIZE-1].bomba + map[MAP_SIZE-2][MAP_SIZE-2].bomba + map[MAP_SIZE-1][MAP_SIZE-2].bomba;

    //Bordas, sem os cantos
    for(i=1; i<MAP_SIZE-1; i++)  //Borda superior
    {
        map[0][i].vizinhos = map[0][i-1].bomba + map[1][i-1].bomba + map[1][i].bomba + map[1][i+1].bomba + map[0][i+1].bomba;
    }
    for(i=1; i<MAP_SIZE-1; i++)  //Borda inferior
    {
        map[MAP_SIZE-1][i].vizinhos = map[MAP_SIZE-1][i-1].bomba + map[MAP_SIZE-2][i-1].bomba + map[MAP_SIZE-2][i].bomba + map[MAP_SIZE-2][i+1].bomba + map[MAP_SIZE-1][i+1].bomba;
    }
    for(i=1; i<MAP_SIZE-1; i++)  //Borda esquerda
    {
        map[i][0].vizinhos = map[i-1][0].bomba + map[i-1][1].bomba + map[i][1].bomba + map[i+1][1].bomba + map[i+1][0].bomba;
    }
    for(i=1; i<MAP_SIZE-1; i++)  //Borda direita
    {
        map[i][MAP_SIZE-1].vizinhos = map[i-1][MAP_SIZE-1].bomba + map[i-1][MAP_SIZE-2].bomba + map[i][MAP_SIZE-2].bomba + map[i+1][MAP_SIZE-2].bomba + map[i+1][MAP_SIZE-1].bomba;
    }

    //Resto do mapa
    for (i=1; i < MAP_SIZE - 1; i++)
    {
        for (j=1; j < MAP_SIZE - 1; j++)
        {
            map[i][j].vizinhos = map[i-1][j-1].bomba + map[i-1][j].bomba + map[i-1][j+1].bomba +
                                 map[i][j-1].bomba   + map[i][j+1].bomba +
                                 map[i+1][j-1].bomba + map[i+1][j].bomba + map[i+1][j+1].bomba;
        }
    }

    return;
}

int hasBomb(Posicao atual)
{
    return atual.bomba;
}

int revelaPosicao(Posicao *atual, int revelar)
{
    //Vai pra posicao desejada
    gotoXY((atual->y*2) + 8, atual->x + 4);
    if (revelar)
        Sleep(200);

    if(atual->status)
    {
        if(atual->bomba)  //Se for uma bomba, printa a bomba
        {
            textcolor(BOMB_COLOR);
            printf("%c", BOMB_CHAR);
            acheiBomba();
        }
        else if(atual->marcado == 1)
        {
            printf("%c", 245);
        }
        else
        {
            switch(atual->vizinhos)
            {
            case 1:
                textcolor(UM_COLOR);
                break;
            case 2:
                textcolor(DOIS_COLOR);
                break;
            case 3:
                textcolor(TRES_COLOR);
                break;
            case 4:
                textcolor(QUATRO_COLOR);
                break;
            case 5:
                textcolor(CINCO_COLOR);
                break;
            default:
                textcolor(SEIS_COLOR);
                break;

            }
            printf("%d", atual->vizinhos); //Se tiver vizinhos, printa o numero
        }
    }
    else if(revelar)
    {
        switch(atual->vizinhos)
        {
        case 1:
            textcolor(UM_COLOR);
            break;
        case 2:
            textcolor(DOIS_COLOR);
            break;
        case 3:
            textcolor(TRES_COLOR);
            break;
        case 4:
            textcolor(QUATRO_COLOR);
            break;
        case 5:
            textcolor(CINCO_COLOR);
            break;
        default:
            textcolor(SEIS_COLOR);
            break;

        }
        atual->status = 1;
        printf("%d", atual->vizinhos); //Se tiver vizinhos, printa o numero

        if(atual->x > 0 && atual->vizinhos == 0)  //Se eu não estiver na fileira mais em cima
        {
            revelaPosicao(&map[atual->x-1][atual->y], 1); //Superior
            if(atual->y > 0)
                revelaPosicao(&map[atual->x-1][atual->y-1], 1); //Superior Esquerdo

            if(atual->y < MAP_SIZE-1)
                revelaPosicao(&map[atual->x-1][atual->y+1], 1); //Superior Direito
        }

        if(atual->x < MAP_SIZE-1 && atual->vizinhos == 0)  //Se eu não estiver na fileira mais em baixo
        {
            revelaPosicao(&map[atual->x+1][atual->y], 1); //Inferior

            if(atual->y > 0)
                revelaPosicao(&map[atual->x+1][atual->y-1], 1); //Inferior Esquerdo

            if(atual->y < MAP_SIZE-1)
                revelaPosicao(&map[atual->x+1][atual->y+1], 1); //Inferior Direito
        }

        if(atual->y > 0 && atual->vizinhos == 0)  //Revela para a direita
        {
            revelaPosicao(&map[atual->x][atual->y-1], 1);
        }
        if(atual->y < MAP_SIZE-1 && atual->vizinhos == 0)  //Revela para a esquerda
        {
            revelaPosicao(&map[atual->x][atual->y+1], 1);
        }
    }

    return atual->bomba;
}

void printaContorno()
{

    int i;
    textcolor(BRANCO);

    //Printa a borda superior
    gotoXY(5, 2);
    printf("%c", SUP_ESQ); //Canto superior esquerdo
    for(i=1; i<MAP_SIZE * 2 + 4; i++)
    {
        printf("%c", HOR_BAR); //Barra superior
    }
    printf("%c", SUP_DIR); //Canto superior direito

    //Printa as bordas verticais
    for(i=3; i<MAP_SIZE + 5; i++)
    {
        gotoXY(5,i);
        printf("%c", VER_BAR); //Barra de pé
        gotoXY(MAP_SIZE * 2 + 9,i);
        printf("%c", VER_BAR); //Barra de pé
    }

    //Printa a borda inferior
    gotoXY(5, MAP_SIZE + 5);
    printf("%c", INF_ESQ); //Canto inferior esquerdo
    for(i=1; i<MAP_SIZE * 2 + 4; i++)
    {
        printf("%c", HOR_BAR); //Barra inferior
    }
    printf("%c", INF_DIR); //Canto inferior direito
}

//DEBUG FUNCTIONS

// Função que printa a quantidade de vizinhos
void revelaMapa()
{

    int i, j;

    printaContorno();
    for(i=0; i < MAP_SIZE; i++)
    {
        for (j=0; j < MAP_SIZE; j++)
        {
            revelaPosicao(&map[i][j], 0);
        }
    }
}

void acheiBomba()
{

    gotoXY(70, 20);
    printf("BOMBA! BOMBA! BOMBA!");

    return;
}
