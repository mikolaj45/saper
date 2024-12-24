#ifndef _scorebord_h
#define _scorebord_h

#define NAME_LEN 11
#define BORD_LEN 5
#define SAVE_FILE "scorebord.txt"

#include<stdio.h>

typedef struct{
    int wynik[BORD_LEN+1];
    char gracz[BORD_LEN+1][NAME_LEN];
    int n;
} scorebord;

scorebord* scorebord_load();

void scorebord_free(scorebord* link);

void scorebord_add(scorebord* link, int new_score, char player_name[NAME_LEN]);

void scorebord_save(scorebord* link);

void scorebord_print(scorebord* link);

int load_name(FILE * stream, char retVal[NAME_LEN]);

#endif