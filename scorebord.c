#include<stdlib.h>
#include<stdio.h>

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
        // if(fscanf(sorse, "%d : ", retVal->wynik[retVal->n]) == EOF){
        //     printf("aa\n");
        //     break;
        // }
        // if(load_name(sorse, retVal->gracz[retVal->n]) == EOF){
        //     printf("bb\n");
        //     break;
        // }
        retVal->n++;
    }
    retVal->n++;

    fclose(sorse);

    return retVal;
}

void scorebord_free();

void scorebord_add(scorebord* link, int new_score, char player_name[NAME_LEN]);

void scorebord_save(scorebord* link);

void scorebord_print(scorebord* link){
    for(int i=0; i<link->n; i++){
        printf("%d : %s\n", link->wynik[i], link->gracz[i]);
    }
};

int load_name(FILE * stream, char retVal[NAME_LEN]){
    int n;
    char c;
    for(n=0; n<NAME_LEN-1; n++){
        c = fgetc(stream);
        if(c == EOF){
            retVal[n] = '\0';
            return EOF;
        }
        if(c == '\n'){
            break;
        }
        retVal[n] = c;
    }
    retVal[n] = '\0';
    return 0;
}