#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "minefild.h"
#include "scoreBord.h"

void file_game(FILE* sorse){
    minefild* game = minefild_for_file(sorse);
    minefild_print(game);
}