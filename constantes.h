#ifndef MAP_SIZE

#define MAP_SIZE 20
#define MULTIPLICADOR_BOMBAS 2

#endif //End DEF MAP_SIZE


#ifndef ENUMS_H_
#define ENUMS_H_

enum colors
{
    PRETO=0,
    CINZA_CLARO=7,
    CINZA, //7+1
    AZUL,
    VERDE,
    VERDE_AGUA,
    VERMELHO,
    LILAS,
    AMARELO,
    BRANCO //15
};

enum gameColors
{
    BOMB_COLOR = BRANCO,
    MAYBOMB_COLOR = VERMELHO,
    UM_COLOR = BRANCO,
    DOIS_COLOR = AZUL,
    TRES_COLOR = LILAS,
    QUATRO_COLOR = AMARELO,
    CINCO_COLOR = VERMELHO,
    SEIS_COLOR = CINZA
};

#endif // ENUMS_H_

#ifndef BOMB_CHAR
    #define BOMB_CHAR '*'
    #define MAYBOMB 245
    #define BLANK_SPACE ' '
#endif // BOMB_CHAR

#ifndef CONTORNO
    #define SUP_ESQ 201
    #define SUP_DIR 187
    #define INF_ESQ 200
    #define INF_DIR 188
    #define HOR_BAR 205
    #define VER_BAR 186
#endif // CONTORNO

#ifndef CARACTERES
    #define SELECAO 254
    #define MARCADO 245
#endif // CARACTERES
