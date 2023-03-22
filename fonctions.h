//
// Created by sebxu on 22/03/2023.
//

#ifndef PROJET_IMAGE_VECTORIELLE_FONCTIONS_H
#define PROJET_IMAGE_VECTORIELLE_FONCTIONS_H

#endif //PROJET_IMAGE_VECTORIELLE_FONCTIONS_H

typedef struct {
    int pos_x:
    int pos_y;
}; Point;

Point * create_point(int x,int y);
void delete_point(Point * p);
void print_point(Point * p);