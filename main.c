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

minefild* command_setup(){
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

int main(){
    srand(time(NULL));
    minefild* game;
    game = command_setup();
    minefild_print(game);
    return 0;
}