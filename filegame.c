#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "minefild.h"
#include "scorebord.h"

int fmove(minefild* game, FILE* source){
    char comand;
    int x,y;
    while(1){
        if(fscanf(source, "%c %d %d", &comand, &x, &y) < 3){
            printf("plik zawiera zly zapis %c\n", comand);
            clear_stdin();
            continue;
        }
        clear_stdin();
        if( comand != 'f' && comand != 'r'){
            printf("plik zawiera nieznana akcje\n");
            continue;
        }
        if( x <= 0 || y <= 0 || x > game->x || y > game->y){
            printf("plik zawiera zle koordynaty\n");
            continue;
        }
        break;
    }
    x--;
    y--;
    if(comand == 'r'){
        return minefild_open(game, x, y);
    }else if(comand == 'f'){
        minefild_flag(game, x, y);
        return 0;
    }
    return 1;
}

int file_game(FILE* source){
    int poprawne_kroki = 0;
    minefild* game = minefild_for_file(sorse);

    int end_type= 0;
    do{
        int czy_k = fmove(game, source);
        end_type = minefild_check_board(game);
        if(end_type != 1){
            poprawne_kroki++;
        }
    } while (0 == end_type && czy_k == 0);

    if(czy_k == 0){
        printf("liczba poprawnych krokow: %d\n", poprawne_kroki);
        if( end_type == 1){
            printf("liczba uzyskanych punktow: %d\n 0 - gra zakonczona niepwodzeniem", game->score);
        }else if( end_type == 2){
            printf("liczba uzyskanych punktow: %d\n 1 - gra zakonczona pwodzeniem", game->score);
        }
        return 0;
    }
    else{
        return 1;
    }
}