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

int minefild_cord_to_ind(minefild*, int, int);

void minefild_print(minefild*);

int minefild_open(minefild*, int, int);

void minefild_sopen(minefild*, int, int);

void minefild_floag(minefild*, int, int);

#endif