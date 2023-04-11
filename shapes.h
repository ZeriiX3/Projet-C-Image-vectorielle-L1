//
// Created by Seb on 01/04/2023.
//

#ifndef PROJET_VECTEUR_FONCTIONS_H
#define PROJET_VECTEUR_FONCTIONS_H

#endif //PROJET_VECTEUR_FONCTIONS_H


// ----------------- STRUCTURES ----------------- //



// Structure Point

typedef struct {
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px, int py);        // Alloue dynamiquement une variable de type structuré Point dont les coordonnées sont données en paramètres
void delete_point(Point * p);               // Libère la mémoire alloué
void print_point(Point * p);


// Structure Line

typedef struct {
    Point *pt1;
    Point *pt2;
}Line;

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);


// Structure Square

typedef struct {
    Point *topleft;
    int length;
}Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);


// Structure Rectangle

typedef struct {
    Point *topleft;
    int length;
    int width;
}Rectangle;

Rectangle *create_rectangle(Point * point, int length, int width);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);


// Structure Cercle

typedef struct {
    Point *center;
    int radius;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);



// Structure Polygon

typedef struct polygon {
    int n;
    Point ** points; // tableau 1D dynamique de Point*
}Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);




