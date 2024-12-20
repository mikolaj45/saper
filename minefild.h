#ifndef _minefild_h
#define _minefild_h

typedef struct{
    int x,y;
    // 0 visible; 1 is cover; 2 is flagd
    int * cover;
    // <0;8> how many mines; 9 mines egzist
    int * mines;
} minefild;

minefild * minefild_innit(int size_x, int size_y, int mines_amount);

void minefild_free(minefild*);

void minefild_print(minefild*);

#endif