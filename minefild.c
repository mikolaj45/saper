#include<stdlib.h>
#include<stdio.h>
#include "minefild.h"

#define MINE 9

minefild * minefild_innit(int size_x, int size_y, int mines_amount){
    minefild* retVal = malloc(sizeof(minefild));
    retVal->x = size_x;
    retVal->y = size_y;

    retVal->cover = malloc(sizeof(int)*size_x*size_y);
    retVal->mines = malloc(sizeof(int)*size_x*size_y);
    for(int i=0; i<size_x*size_y; i++){
        retVal->cover[i] = 1;
        retVal->mines[i] = 0;
    }

    int rand_pos;
    for(int m=0; m<mines_amount;m++){
        rand_pos = rand()%(size_x*size_y);
        if(retVal->mines[rand_pos] == MINE){
            m--;
        }
        retVal->mines[rand_pos] = MINE;
    }

    return retVal;
}

void minefild_free(minefild* to_free){
    free(to_free->cover);
    free(to_free->mines);
    free(to_free);
}

int minefild_cord_to_ind(minefild* base, int x, int y){
    return base->y*x + y;
};

void minefild_print(minefild* to_print){
    int pos;

    printf("  ");
    for(int i=0; i<to_print->y;i++){
        printf("%d ", i+1);
    }
    printf("\n");

    for(int x=0; x<to_print->x;x++){
        printf("%d ", x+1);
        for(int y=0; y<to_print->y;y++){
            pos = minefild_cord_to_ind(to_print, x, y);
            // if (to_print->mines[pos]==MINE){
            //     printf("M ");
            // }else 
            if(to_print->cover[pos]==1){
                printf("# ");
            }else if (to_print->cover[pos]==2){
                printf("F ");
            }else if (to_print->mines[pos]==MINE){
                printf("M ");
            }else if( to_print->mines[pos]==0 ){
                printf(". ");
            }else{
                printf("%d ",to_print->mines[pos]);
            }
        }
        printf("\n");
    }
}

// 0 - safe; 1 - mines
int minefild_open(minefild* play, int x, int y){
    int pos = minefild_cord_to_ind(play, x, y);
    play->cover[pos] = 0;
    if(play->mines[pos] == MINE){
        return 1;
    }
    
    int pola_around[8][2];
    int pola_n = 0;
    for(int move_x= -1; move_x < 2; move_x++){
        for(int move_y= -1; move_y < 2; move_y++){
            if(move_x==0 && move_y==0){
                continue;
            }
            if(x+move_x < 0 || x+move_x >= play->x){
                continue;
            }
            if(y+move_y < 0 || y+move_y >= play->y){
                continue;
            }
            pola_around[pola_n][0] = x+move_x;
            pola_around[pola_n][1] = y+move_y;
            pola_n++;
        }
    }

    //zliczanie min
    for(int i=0; i<pola_n; i++){
        if( play->mines[
            minefild_cord_to_ind(play, pola_around[i][0], pola_around[i][1])
        ] == MINE){
            play->mines[pos]++;
        }
    }

    if(play->mines[pos] != 0){
        return 0;
    }

    for(int i=0; i<pola_n; i++){
        if( play->cover[
            minefild_cord_to_ind(play, pola_around[i][0], pola_around[i][1])
        ] == 0){
            continue;
        }
        minefild_open(play, pola_around[i][0], pola_around[i][1]);
    }

    return 0;
}

// tylko startowy ruch
void minefild_sopen(minefild* play, int x, int y){
    int pos = minefild_cord_to_ind(play, x, y);
    if(play->mines[pos] == MINE){
        int new_pos;
        do{
            new_pos = rand()%(play->x*play->y);
            // printf("%d\n", new_pos);
        } while (play->mines[new_pos] == MINE);
        play->mines[pos] = 0;
        play->mines[new_pos] = MINE;
    }
    minefild_open(play, x, y);
};