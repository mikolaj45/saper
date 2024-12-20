#include<stdlib.h>
#include<stdio.h>
#include "minefild.h"

minefild * minefild_innit(int size_x, int size_y, int mines_amount){
    minefild* retVal = malloc(sizeof(minefild));
    retVal->x = size_x;
    retVal->y = size_y;

    retVal->cover = malloc(sizeof(int)*size_x*size_y);
    for(int i=0; i<size_x*size_y; i++){
        retVal->cover[i] = 0;
    }

    retVal->mines = calloc(size_x*size_y,sizeof(int));
    int rand_pos;
    for(int m=0; m<mines_amount;m++){
        rand_pos = rand()%(size_x*size_y);
        if(retVal->mines[rand_pos] == 9){
            m--;
        }
        retVal->mines[rand_pos] = 9;
    }

    return retVal;
}

void minefild_free(minefild* to_free){
    free(to_free->cover);
    free(to_free->mines);
    free(to_free);
}

void minefild_print(minefild* to_print){
    int pos;
    for(int y=0; y<to_print->y;y++){
        for(int x=0; x<to_print->x;x++){
            pos = to_print->y*y + x;
            if(to_print->cover[pos]==1){
                printf("# ");
            }else if (to_print->cover[pos]==2){
                printf("f ");
            }else if (to_print->mines[pos]==9){
                printf("M ");
            }else if( to_print->mines[pos]==0 ){
                printf("_ ");
            }else{
                printf("%d ",to_print->mines[pos]);
            }
        }
        printf("\n");
    }
}