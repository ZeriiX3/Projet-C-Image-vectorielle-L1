//
// Created by sebxu on 22/03/2023.
//

#include "fonctions.h"
#include "stdio.h"
#include "stdlib.h"

Point * create_point(int px,int py){
    Point * p = (Point *)malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;

    return p;
}

void delete_point(Point * p){
    free(p);
}

void print_point(Point * p){
    printf("%d %d",p->pos_x, p->pos_y);
}