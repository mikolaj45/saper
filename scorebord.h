#ifndef _scorebord_h
#define _scorebord_h

#define NAME_LEN 11
#define BORD_LEN 5
#define save_file "scorebord.txt"

typedef struct{
    int wynik[BORD_LEN+1];
    char gracz[BORD_LEN+1][NAME_LEN];
} scorebord;

scorebord* scorebord_load();

void scorebord_free();

void scorebord_add(scorebord* link, int new_score, char player_name[NAME_LEN]);

void scorebord_save(scorebord* link);

void scorebord_print(scorebord* link);

#endif