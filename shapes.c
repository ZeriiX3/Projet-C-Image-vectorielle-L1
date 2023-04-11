//
// Created by Seb on 01/04/2023.
//

#include "shapes.h"

#include "stdio.h"
#include "stdlib.h"


// ----------------- STRUCTURES ----------------- //



// Structure Point - FONCTIONS


Point *create_point(int px, int py) {
    Point *p = (Point *)malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;

    return p;
}

void delete_point(Point *p) {
    free(p);
}

void print_point(Point * p) {
    printf("POINT [(%d, %d)]\n",p->pos_x, p->pos_y);
}



// Structure Line - FONCTIONS


Line *create_line(Point * p1, Point * p2) {
    Line * line = (Line*)malloc(sizeof(Line));
    line->pt1 = p1;
    line->pt2 = p2;
    return line;
}

void delete_line(Line * line) {
    free(line->pt1);
    free(line->pt2);
    free(line);
}

void print_line(Line * line) {
    printf("LINE [(%d, %d),(%d, %d)]\n",line->pt1->pos_x, line->pt1->pos_y, line->pt2->pos_x, line->pt2->pos_y);
}



// Structure Square - FONCTIONS


Square *create_square(Point * point, int length) {
    Square *square = (Square*) malloc(sizeof(Square));
    square->topleft = point;
    square->length = length;
    return square;
}

void print_square(Square * square) {
    printf("SQUARE [(%d, %d),(%d, %d),\n",square->topleft->pos_x, square->topleft->pos_y, square->topleft->pos_x,square->topleft->pos_y + square->length);
    printf("        (%d, %d),(%d, %d)]\n", square->topleft->pos_x + square->length, square->topleft->pos_y,
           square->topleft->pos_x + square->length,square->topleft->pos_y + square->length);

}

void delete_square(Square * square) {
    free(square->topleft);
    free(square);
}



// Structure Rectangle - FONCTIONS


Rectangle *create_rectangle(Point * point, int length, int width) {
    Rectangle *rectangle = (Rectangle *) malloc(sizeof(Rectangle));
    rectangle->topleft = point;
    rectangle->length = length;
    rectangle->width = width;
    return rectangle;
}

void delete_rectangle(Rectangle * rectangle) {
    free(rectangle->topleft);
    free(rectangle);
}

void print_rectangle(Rectangle * rectangle) {
    printf("RECTANGLE [(%d, %d),(%d, %d),\n",rectangle->topleft->pos_x, rectangle->topleft->pos_y,
           rectangle->topleft->pos_x,rectangle->topleft->pos_y + rectangle->length);
    printf("           (%d, %d),(%d, %d)]\n", rectangle->topleft->pos_x + rectangle->width, rectangle->topleft->pos_y,
           rectangle->topleft->pos_x + rectangle->width,rectangle->topleft->pos_y + rectangle->length);
}



// Structure Rectangle - FONCTION

Circle *create_circle(Point * center, int radius) {
    Circle *circle = (Circle *) malloc(sizeof(Circle));
    circle->center = center;
    circle->radius = radius;
    return circle;
}

void delete_circle(Circle * circle) {
    free(circle->center);
    free(circle);
}

void print_circle(Circle * circle) {
    printf("CIRCLE [center (%d, %d) with radius (%d)]\n",circle->center->pos_x,circle->center->pos_y,circle->radius);
}



// Structure Polygon - FONCTION

Polygon *create_polygon(int n) {
    Polygon *polygon = (Polygon*) malloc(sizeof(Polygon));
    polygon->n = n;

    for (int i = 0; i < n; i++) {
        polygon->points[i];
    }

    return polygon;
}

void delete_polygon(Polygon * polygon) {

    for (int i = 0; i < polygon->n; i++) {
        free(polygon->points[i]);
    }
    free(polygon);
}

void print_polygon(Polygon * polygon) {

    printf("POLYGON ");
    for (int i = 0; i < polygon->n; i++) {
        printf("(%d, %d) ",polygon->points[i]->pos_x,polygon->points[i]->pos_y);
    }
}