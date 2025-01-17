#ifndef _scorebord_h
#define _scorebord_h

#define NAME_LEN 11
#define BORD_LEN 5
#define SAVE_FILE "scorebord.txt"

#include<stdio.h>

typedef struct{
    int* wynik;
    // lista znakow skladajaca sie na slowa 
    //tylko jeda gwiastka aby wszystko trzymac w jednym miejscu jako ze imie jest ograniczone do NAME_LEN
    char* gracz;
    // ilosc graczy w plik plus 1 na nowego gracza
    int n;
} scorebord;

scorebord* scorebord_load();

void scorebord_free(scorebord* link);

void scorebord_add(scorebord* link, int new_score, char player_name[NAME_LEN]);

// ! nie wywoluwac bez dodania nowego wyniku
void scorebord_save(scorebord* link);

// ! nie wywoluwac bez dodania nowego wyniku
void scorebord_print(scorebord* link);

int load_name(FILE * stream, char* retVal);

#endif