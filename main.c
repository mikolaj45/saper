#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "minefild.h"

#define BUFFERSIZE 256

// czytanie wejscia
// fgets(inputBuffer, BUFFERSIZE, stdin);
// printf("%s\n", inputBuffer);
// fflush(stdin);

// tylko dla nie pustego stdin
void clear_stdin(){
    while(getchar()!='\n'){}
}

minefild* setup(){
    printf("podaj poziom trudnosci\n");
    printf("1-latwy; 2-sredni; 3-trudny; 4-wlasny\n");
    int dificulty;
    while(1){
        if(scanf("%d", &dificulty) == 0){
            printf("podaj licze\n");
            clear_stdin();
            continue;
        };
        if(dificulty < 0 || dificulty > 4){
            printf("podaj z przedzialu <1;4>\n");
            continue;
        }
        break;
    }

    if(dificulty < 4){
        int std_seting[][3] = {
            {9,9,10},
            {16,16,40},
            {16,30,99}
        };
        dificulty--;
        return minefild_innit(std_seting[dificulty][0],std_seting[dificulty][1],std_seting[dificulty][2]);
    }

    int custom_minefild_data[3];
    printf("podaj wymiary i ilosc min\nw formacie: x y mine\n");
    while(1){
        if(scanf(
            "%d %d %d", &custom_minefild_data[0], &custom_minefild_data[1], &custom_minefild_data[2]
        ) < 3){
            printf("zly format\n");
            clear_stdin();
            continue;
        }
        if(custom_minefild_data[0]*custom_minefild_data[1]/2 < custom_minefild_data[2]){
            printf("za duzo min\n");
            continue;
        }
        break;
    }
    return minefild_innit(custom_minefild_data[0], custom_minefild_data[1], custom_minefild_data[2]);

}

void load_move(minefild* game, int anser[3]){
    // anser to (0-uncower;1-flag),x,y

    printf("podaj ruch\n");
    char comand;
    while(1){
        if(scanf("%c %d %d", &comand, &anser[1], &anser[2]) < 3){
            printf("zly zapis\n");
            clear_stdin();
            continue;
        }
        if( comand != 'f' && comand != 'r'){
            printf("nieznana akcja\n");
            continue;
        }
        if( anser[1] <= 0 || anser[2] <= 0 || anser[1] > game->x || anser[2] > game->y){
            printf("zle kordynaty\n");
            continue;
        }
        break;
    }
    if( comand == 'r'){
        anser[0] = 0;
    }else{
        anser[0] = 1;
    }
    anser[1]--;
    anser[2]--;
}

void move(){

}

void start_move(minefild* game){
    printf("podaj startowe kordynaty\n");
    int x,y;
    while(1){
        if(scanf("%d %d", &x, &y) < 2){
            printf("podaj liczby\n");
            clear_stdin();
            continue;
        }
        if( x <= 0 || y <= 0 || x > game->x || y > game->y){
            printf("zle kordynaty %d %d\n", x, y);
            continue;
        }
        break;
    }
    x--;
    y--;
    minefild_sopen(game, x, y);
}

int main(){
    srand(time(NULL));
    minefild* game;
    game = setup();
    minefild_print(game);
    start_move(game);
    minefild_print(game);
    return 0;
}