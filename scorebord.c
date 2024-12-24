#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#include"scorebord.h"

scorebord* scorebord_load(){
    scorebord* retVal = calloc(1,sizeof(scorebord));
    FILE *sorse = fopen(SAVE_FILE, "r");

    if(sorse == NULL){
        return retVal;
    }

    while (
        fscanf(sorse, "%d : ", &retVal->wynik[retVal->n]) > 0 &&
        load_name(sorse, retVal->gracz[retVal->n]) != EOF
    ){
        retVal->n++;
    }
    retVal->n++;

    fclose(sorse);

    return retVal;
}

void scorebord_free();

void scorebord_add(scorebord* link, int new_score, char player_name[NAME_LEN]){
    link->wynik[link->n] = new_score;
    strcpy( link->gracz[link->n], player_name);
    link->n++;

    char cbuf[NAME_LEN];
    int ibuf;
    for(int i = link->n-1; i > 0; i--){
        if(link->wynik[i] <= link->wynik[i-1]){
            break;
        }
        strcpy(cbuf, link->gracz[i]);
        ibuf = link->wynik[i];

        strcpy(link->gracz[i], link->gracz[i-1]);
        link->wynik[i] = link->wynik[i-1];

        strcpy(link->gracz[i-1], cbuf);
        link->wynik[i-1] = ibuf;
    }
}

void scorebord_save(scorebord* link);

void scorebord_print(scorebord* link){
    for(int i=0; i<link->n; i++){
        printf("%d : %s\n", link->wynik[i], link->gracz[i]);
    }
};

// -1 -EOF ; 0 - koniec ; 1 - zostalo 
int load_name(FILE * stream, char retVal[NAME_LEN]){
    int n;
    char c;
    int end = 1;
    for(n=0; n<NAME_LEN-1; n++){
        c = fgetc(stream);
        if(c == EOF){
            retVal[n] = '\0';
            return EOF;
        }
        if(c == '\n'){
            end = 0;
            break;
        }
        retVal[n] = c;
    }
    retVal[n] = '\0';
    return end;
}