#ifndef _scorebord_h
#define _scorebord_h

#define NAME_LEN 11
#define BORD_LEN 5

typedef struct{
    int wynik[BORD_LEN+1];
    char gracz[BORD_LEN+1][NAME_LEN];
} scorebord;


#endif