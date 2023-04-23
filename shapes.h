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

Polygon *create_polygon(int n,int *tab);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);




// ----------------- SHAPES ----------------- //



typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON } SHAPE_TYPE;

typedef struct shape {
    int id;     // identifiant unique de la forme
    SHAPE_TYPE shape_type;      // type de la forme pointé
    void *ptrShape;     // pointeur sur n'importe quelle forme
}Shape;


Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int length, int width);
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(int n, int *tab);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);
void shape_list();