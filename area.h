/* Project C: Vector Text-based Editor
Professeurs: Halim Djerroud, Fabien Calcado, Asma Gabis
Mars - Mai / 2023

Par Sébastien XU et Matthieu BACHELERIE */

#ifndef PROJET_VECTEUR_AREA_H
#define PROJET_VECTEUR_AREA_H


// ************************************ IMPORT ************************************ //
#define SHAPE_MAX 100 // Nombre maximum de formes
#define BOOL int

#include "shapes.h"
// ******************************************************************************** //




// ----------------------------------------------- //
// ------------------ Structure ------------------ //
// ----------------------------------------------- //


struct area {
    unsigned int width; // Nombre de pixels en largeur ou nombre de colonnes (axe y)
    unsigned int height; // Nombre de pixels en hauteur ou nombre de lignes (axe x)
    BOOL** mat; // Matrice des pixels de taille (width * height)
    Shape* shapes[SHAPE_MAX]; // Tableau des formes;
    int nb_shape; // Nombre de formes dans le tableau shapes (taille logique)
};
typedef struct area Area;


// Fonctions

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);


// ----------------------------------------------- //
// -------------------- PIXEL ---------------------//
// ----------------------------------------------- //

typedef struct pixel {
    int px;
    int py;
}Pixel;


// Fonctions //

Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);

void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_line(Shape* line, Pixel*** pixel_tab, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel*** pixel_tab, int *nb_pixels);
void pixel_square(Shape* square, Pixel*** pixel_tab, int* nb_pixels);
void pixel_rectangle(Shape* rectangle, Pixel*** pixel_tab, int* nb_pixels);
void pixel_polygon(Shape* polygon, Pixel*** pixel_tab, int* nb_pixels);

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel*** pixel, int nb_pixels);


#endif //PROJET_VECTEUR_AREA_H
