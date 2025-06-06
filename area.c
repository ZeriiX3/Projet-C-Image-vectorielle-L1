/* Project C: Vector Text-based Editor
Professeurs: Halim Djerroud, Fabien Calcado, Asma Gabis
Mars - Mai / 2023

Par Sébastien XU et Matthieu BACHELERIE */


// ************************************ IMPORT ************************************ //
#include <stdlib.h>
#include <stdio.h>

#include "area.h"
#include "shapes.h"
#include "fonctions.h"
// ******************************************************************************** //





// ----------------------------------------------- //
// -------------------- AREA --------------------- //
// ----------------------------------------------- //



Area* create_area(unsigned int width, unsigned int height){
    Area * area = (Area*) malloc(sizeof (Area));
    area->width = width;
    area->height = height;
    area->mat = (BOOL**)calloc(width, sizeof(BOOL*));
    for (unsigned int i = 0; i < width; i++) {
        area->mat[i] = (BOOL*)calloc(height,sizeof(BOOL));
    }
    area->nb_shape = 0;
    return area;
}


void add_shape_to_area(Area* area, Shape* shape) {

    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;
    shape->id = area->nb_shape;
}

void clear_area(Area* area) {
    for (unsigned int i = 0; i < area->width; i++) {
        for (unsigned int j = 0; j < area->height; j++) {
            area->mat[i][j] = 0;  // Permet de mettre la matrice 2D à 0
        }
    }
}

void erase_area(Area* area) {
    for (int i = 0; i < area->height; i++) {
        for (int j = 0; j < area->width; j++){
            area->mat[i][j] = 0;
        }
    }
    area->nb_shape = 0;
}

void delete_area(Area* area) {
    for (unsigned int i = 0; i < area->width; i++) {
        free(area->mat[i]);
    }
    free(area->mat);

    free(area);
}


void draw_area(Area* area) {
    for (int i = 0; i < area->nb_shape; i++) {
        int nb_pixel = 0;
        Shape* shape = area->shapes[i];
        Pixel** pixels = create_shape_to_pixel(shape, &nb_pixel);

        for (int j = 0; j < nb_pixel; j++) {
            int x = pixels[j]->px;
            int y = pixels[j]->py;
            if (x >= 0 && x < area->width && y >= 0 && y < area->height) {
                area->mat[x][y] = 1;
            }
        }
        free(pixels);
    }
}


void print_area(Area* area) {
    for ( int i = 0; i < area->height; i++) {
        for (int j = 0; j < area->width; ++j) {
            if (area->mat[i][j] == 0) {
                printf(" . ");
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }
}



// ----------------------------------------------- //
// -------------------- PIXEL -------------------- //
// ----------------------------------------------- //


Pixel* create_pixel(int px, int py) {
    Pixel* pixel = (Pixel*)malloc(sizeof(Pixel));
    pixel->px = px;
    pixel->py = py;
    return pixel;
}

void delete_pixel(Pixel* pixel) {
    free(pixel);
    pixel = NULL;
}

void delete_pixel_shape(Pixel ***pixel, int nb_pixels)
{
    for (int i = 0; i < nb_pixels; i++)
    {
        delete_pixel((*pixel)[i]);
    }
    free(*pixel);
}

void pixel_point(Shape *shape, Pixel ***pixel_tab, int *nb_pixels){
    Point *p = (Point *)shape->ptrShape;
    *pixel_tab = (Pixel **)malloc(sizeof(Pixel *));
    *pixel_tab[0] = create_pixel(p->pos_x, p->pos_y);
    *nb_pixels = 1;
}

void pixel_line(Shape *shape, Pixel ***pixel_tab, int *nb_pixels){

    // Création d'un type Line et affection à son type LINE
    Line *l = (Line *)shape->ptrShape;

    int l1x = l->pt1->pos_x, l1y = l->pt1->pos_y;
    int l2x = l->pt2->pos_x, l2y = l->pt2->pos_y;


    if (l1x < l2x){
        // on trace vers la droite
        int p_x = l2x - l1x;
        int p_y = l2y - l1y;
        int dmin = min(p_x, abs(p_y));
        int dmax = max(p_x, abs(p_y));

        Pixel **temp_tab_pixels = (Pixel **)malloc((dmax + 1) * sizeof(Pixel *));

        int nb_segment = dmin + 1;
        int taille_segment = (dmax + 1) / (dmin + 1);
        int restant = (dmax + 1) % (dmin + 1);

        int segments[nb_segment];
        for (int i = 0; i < nb_segment; i++){
            segments[i] = taille_segment;
        }

        int *cumulation = (int *)malloc(nb_segment * sizeof(int));
        cumulation[0] = 0;

        for (int i = 2; i < nb_segment + 1; i++){
            cumulation[i - 1] = ((i * restant) % (dmin + 1) < ((i - 1) * restant) % (dmin + 1));
        }

        for (int i = 0; i < nb_segment; i++){
            segments[i] += cumulation[i];
        }

        if (p_y < 0){
            // On trace vers le bas
            if (p_x > abs(p_y)){
                // les segments sont horizontaux
                int temp_p_x = l1x, temps_p_y = l1y;
                for (int i = 0; i < nb_segment; i++){

                    for (int j = 0; j < segments[i]; j++){
                        temp_tab_pixels[*nb_pixels] = create_pixel(temp_p_x, temps_p_y);
                        (*nb_pixels)++;
                        temp_p_x++;
                    }
                    temps_p_y--;
                }
            }
            else {// Les segments sont verticaux

                int temp_x = l1x;
                int temp_y = l1y;

                for (int i = 0; i < nb_segment; i++){

                    for (int j = 0; j < segments[i]; j++){

                        temp_tab_pixels[*nb_pixels] = create_pixel(temp_x, temp_y);
                        (*nb_pixels)++;
                        temp_y--;
                    }
                    temp_x++;
                }
            }
        }

        else {// on trace vers le haut

            if (p_x > p_y){

                // les segments sont horizontaux
                int temp_x = l1x, temp_y = l1y;
                for (int i = 0; i < nb_segment; i++){

                    for (int j = 0; j < segments[i]; j++){

                        temp_tab_pixels[*nb_pixels] = create_pixel(temp_x, temp_y);
                        (*nb_pixels)++;
                        temp_x++;
                    }
                    temp_y++;
                }
            }
            else{
                // les segments sont verticaux
                int temp_x = l1x, temp_y = l1y;
                for (int i = 0; i < nb_segment; i++){

                    for (int j = 0; j < segments[i]; j++){

                        temp_tab_pixels[*nb_pixels] = create_pixel(temp_x, temp_y);
                        (*nb_pixels)++;
                        temp_y++;
                    }
                    temp_x++;
                }
            }
        }
        *pixel_tab = temp_tab_pixels;
    }
    else{
        // on trace vers ma gauche
        int p_x = l1x - l2x;
        int p_y = l1y - l2y;
        int dmin = min(p_x, abs(p_y));
        int dmax = max(p_x, abs(p_y));

        Pixel **temp_tab_pixels = (Pixel **)malloc((dmax + 1) * sizeof(Pixel *));

        int nb_segments = dmin + 1;
        int taille_segment = (dmax + 1) / (dmin + 1);
        int reste = (dmax + 1) % (dmin + 1);

        int segments[nb_segments];
        for (int i = 0; i < nb_segments; i++){

            segments[i] = taille_segment;
        }

        int *cumul = (int *)malloc(nb_segments * sizeof(int));
        cumul[0] = 0;

        for (int i = 2; i < nb_segments + 1; i++){

            cumul[i - 1] =
                    ((i * reste) % (dmin + 1) < ((i - 1) * reste) % (dmin + 1));
        }

        for (int i = 0; i < nb_segments; i++){

            segments[i] = segments[i] + cumul[i];
        }

        if (p_y < 0){
            // on trace vers le bas
            if (p_x > abs(p_y)){

                // les segments sont horizontaux
                int temp_x = l2x, temp_y = l2y;
                for (int i = 0; i < nb_segments; i++){

                    for (int j = 0; j < segments[i]; j++){

                        temp_tab_pixels[*nb_pixels] = create_pixel(temp_x, temp_y);
                        (*nb_pixels)++;
                        temp_x++;
                    }
                    temp_y--;
                }
            }
            else{

                // les segments sont verticaux
                int temp_x = l2x, temp_y = l2y;

                for (int i = 0; i < nb_segments; i++){


                    for (int j = 0; j < segments[i]; j++){

                        temp_tab_pixels[*nb_pixels] = create_pixel(temp_x, temp_y);
                        (*nb_pixels)++;
                        temp_y--;
                    }
                    temp_x++;
                }
            }
        }

        else{

            // on trace vers le haut
            if (p_x > p_y)
            { // les segments sont horizontaux
                int temp_x = l2x, temp_y = l2y;
                for (int i = 0; i < nb_segments; i++){

                    for (int j = 0; j < segments[i]; j++){

                        temp_tab_pixels[*nb_pixels] = create_pixel(temp_x, temp_y);
                        (*nb_pixels)++;
                        temp_x++;
                    }
                    temp_y++;
                }
            }

            else{

                // les segments sont verticaux
                int temp_x = l2x, temp_y = l2y;
                for (int i = 0; i < nb_segments; i++){

                    for (int j = 0; j < segments[i]; j++){

                        temp_tab_pixels[*nb_pixels] = create_pixel(temp_x, temp_y);
                        (*nb_pixels)++;
                        temp_y++;
                    }
                    temp_x++;
                }
            }
        }
        *pixel_tab = temp_tab_pixels;
    }
}


void pixel_square(Shape *shape, Pixel ***pixel_tab, int *nb_pixels)
{
    Square *square = (Square *)shape->ptrShape;
    int p1 = square->topleft->pos_x;
    int p2 = square->topleft->pos_y;
    int cote = square->length;

    *pixel_tab = (Pixel **)malloc(cote * cote * sizeof(Pixel *));

    int index = 0;
    // Haut
    for (int i = 0; i < cote; i++){
        Pixel *px = create_pixel(p1 + i, p2);
        (*pixel_tab)[index++] = px;
        (*nb_pixels)++;
    }

    // Droit
    for (int i = 1; i < cote - 1; i++){
        Pixel *px = create_pixel(p1 + cote - 1, p2 + i);
        (*pixel_tab)[index++] = px;
        (*nb_pixels)++;
    }

    // Bas
    for (int i = 0; i < cote; i++){
        Pixel *px = create_pixel(p1 + i, p2 + cote - 1);
        (*pixel_tab)[index++] = px;
        (*nb_pixels)++;
    }

    // Gauche
    for (int i = 1; i < cote - 1; i++){
        Pixel *px = create_pixel(p1, p2 + i);
        (*pixel_tab)[index++] = px;
        (*nb_pixels)++;
    }
}


void pixel_circle(Shape *shape, Pixel ***pixel_tab, int *nb_pixels){
    Circle *circle = (Circle *)shape->ptrShape;
    int x = 0;
    int y = circle->radius;
    int d = 3 - 2 * circle->radius;

    Pixel *pixel = NULL; // Pixel de type PIXEL

    *pixel_tab = (Pixel **)malloc(8 * circle->radius * sizeof(Pixel *));

    while (x <= y){


        pixel = create_pixel(circle->center->pos_x + x, circle->center->pos_y + y);
        (*pixel_tab)[(*nb_pixels)++] = pixel;


        pixel = create_pixel(circle->center->pos_x + y, circle->center->pos_y + x);
        (*pixel_tab)[(*nb_pixels)++] = pixel;


        pixel = create_pixel(circle->center->pos_x - x, circle->center->pos_y + y);
        (*pixel_tab)[(*nb_pixels)++] = pixel;


        pixel = create_pixel(circle->center->pos_x - y, circle->center->pos_y + x);
        (*pixel_tab)[(*nb_pixels)++] = pixel;


        pixel = create_pixel(circle->center->pos_x + x, circle->center->pos_y - y);
        (*pixel_tab)[(*nb_pixels)++] = pixel;


        pixel = create_pixel(circle->center->pos_x + y, circle->center->pos_y - x);
        (*pixel_tab)[(*nb_pixels)++] = pixel;


        pixel = create_pixel(circle->center->pos_x - x, circle->center->pos_y - y);
        (*pixel_tab)[(*nb_pixels)++] = pixel;


        pixel = create_pixel(circle->center->pos_x - y, circle->center->pos_y - x);
        (*pixel_tab)[(*nb_pixels)++] = pixel;

        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void pixel_rectangle(Shape *shape, Pixel ***pixel_tab, int *nb_pixels){

    Rectangle *rectangle = (Rectangle *)shape->ptrShape;
    int x = rectangle->topleft->pos_x;
    int y = rectangle->topleft->pos_y;
    int length = rectangle->length;
    int width = rectangle->width;
    *pixel_tab = (Pixel **)malloc((2 * length + 2 * width - 4) * sizeof(Pixel *));
    int index = 0;

    // Haut
    for (int i = 0; i < length; i++){

        Pixel *px = create_pixel(x + i, y);
        (*pixel_tab)[index++] = px;
        (*nb_pixels)++;
    }

    // Droit
    for (int i = 1; i < width - 1; i++){

        Pixel *px = create_pixel(x + length - 1, y + i);
        (*pixel_tab)[index++] = px;
        (*nb_pixels)++;
    }

    // Bas
    for (int i = length - 1; i >= 0; i--){

        Pixel *px = create_pixel(x + i, y + width - 1);
        (*pixel_tab)[index++] = px;
        (*nb_pixels)++;
    }

    // Gauche
    for (int i = width - 2; i > 0; i--){

        Pixel *px = create_pixel(x, y + i);
        (*pixel_tab)[index++] = px;
        (*nb_pixels)++;
    }
}


void pixel_polygon(Shape *shape, Pixel ***pixel_tab, int *nb_pixels){

    Polygon *poly = (Polygon *)shape->ptrShape;
    int nb_point = poly->n;
    Point **points = poly->points;


    *pixel_tab = (Pixel **)malloc(nb_point * sizeof(Pixel *));
    Shape **l = (Shape **)malloc((nb_point + 1) * sizeof(Shape *));

    for (int i = 0; i < nb_point; i++){

        l[i] = create_line_shape(points[i]->pos_x, points[i]->pos_y, points[(i + 1) % nb_point]->pos_x, points[(i + 1) % nb_point]->pos_y);
    }

    int nb_pixels_tmp = 0;
    Pixel **pixel_tmp = NULL;

    for (int i = 0; i < nb_point; i++){

        pixel_line(l[i], &pixel_tmp, &nb_pixels_tmp);
        *pixel_tab = (Pixel **)realloc(*pixel_tab, (*nb_pixels + nb_pixels_tmp) * sizeof(Pixel *));
        for (int j = 0; j < nb_pixels_tmp; j++)
        {
            (*pixel_tab)[*nb_pixels + j] = pixel_tmp[j];
        }
        *nb_pixels += nb_pixels_tmp;
    }

    // Libérer la mémoire des lignes
    for (int i = 0; i <= nb_point; i++){

        delete_shape(l[i]);
    }
    free(l);
}


// Création de la forme (pixel) selon de type
Pixel **create_shape_to_pixel(Shape *shape, int *nb_pixel){

    Pixel **pixel = NULL;
    switch (shape->shape_type){

        case LINE:
            pixel_line(shape, &pixel, nb_pixel);
            break;
        case POINT:
            pixel_point(shape, &pixel, nb_pixel);
            break;
        case SQUARE:
            pixel_square(shape, &pixel, nb_pixel);
            break;
        case RECTANGLE:
            pixel_rectangle(shape, &pixel, nb_pixel);
            break;
        case CIRCLE:
            pixel_circle(shape, &pixel, nb_pixel);
            break;
        case POLYGON:
            pixel_polygon(shape, &pixel, nb_pixel);
            break;
    }
    return pixel;
}
