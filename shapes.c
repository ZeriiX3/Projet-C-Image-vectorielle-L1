#include "shapes.h"
#include "id.h"
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
    p = NULL;
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
    line->pt1 = NULL;
    line->pt2 = NULL;
    line = NULL;
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
    square->topleft = NULL;
    square = NULL;
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
    rectangle->topleft = NULL;
    rectangle = NULL;
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
    circle->center = NULL;
    circle = NULL;
}

void print_circle(Circle * circle) {
    printf("CIRCLE [center (%d, %d) with radius (%d)]\n",circle->center->pos_x,circle->center->pos_y,circle->radius);
}



// Structure Polygon - FONCTION

Polygon *create_polygon(int n, int *tab) {
    Polygon *polygon = (Polygon*) malloc(sizeof(Polygon));
    polygon->n = n;
    Point * x = (Point*) malloc(n*sizeof(Point));

    for (int i = 0; i < n; i++) {
        polygon->points[i]->pos_x = tab[2*i];
        polygon->points[i]->pos_y = tab[2*i + 1];
    }
    return polygon;
}

void delete_polygon(Polygon * polygon) {

    for (int i = 0; i < polygon->n; i++) {
        free(polygon->points[i]);
        polygon->points[i]= NULL;
    }
    free(polygon);
    polygon = NULL;
}

void print_polygon(Polygon * polygon) {

    printf("POLYGON ");
    for (int i = 0; i < polygon->n; i++) {
        printf("(%d, %d) ",polygon->points[i]->pos_x,polygon->points[i]->pos_y);
    }
}



// ----------------- SHAPES ----------------- //



Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->id = get_next_id(); // plus tard on appelera get_next_id();
    shp->shape_type = shape_type;
    shp->ptrShape = NULL;
    return shp;
}

Shape *create_point_shape(int px, int py) {

    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Point * p1 = create_point (px1, py1);
    Point * p2 = create_point (px2, py2);
    Line * l = create_line(p1,p2);
    shp->ptrShape = l;
    return shp;
}


Shape *create_square_shape(int px, int py, int length) {
    Shape *shp = create_empty_shape(SQUARE);
    Point * p = create_point(px,py);
    Square * s = create_square(p, length);
    shp->ptrShape = s;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int length, int width) {
    Shape *shp = create_empty_shape(RECTANGLE);
    Point * p = create_point(px,py);
    Rectangle * r = create_rectangle(p, length, width);

    shp->ptrShape = r;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius) {
    Shape *shp = create_empty_shape(CIRCLE);
    Point * p = create_point(px,py);
    Circle * c = create_circle(p,radius);

    shp->ptrShape = c;
    return shp;
}



Shape *create_polygon_shape(int n, int *tab) {
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *poly = create_polygon(n,tab);
    shp->ptrShape = poly;
    return shp;
}


void delete_shape(Shape *shape) {

    switch (shape->shape_type) {
        case POINT: {
            delete_point((Point *)shape->ptrShape);
            break;
        }

        case LINE: {
            delete_line((Line *)shape->ptrShape);
            break;
        }

        case SQUARE: {
            delete_square((Square *)shape->ptrShape);
            break;
        }

        case RECTANGLE: {
            delete_rectangle((Rectangle *)shape->ptrShape);
            break;
        }

        case CIRCLE: {
            delete_circle((Circle *)shape->ptrShape);
            break;
        }

        case POLYGON: {
            delete_polygon((Polygon *)shape->ptrShape);
            break;
        }
    }
    free(shape);

}


void print_shape(Shape * shape) {

    printf("%d : ", shape->id);
    switch (shape->shape_type) {
        case POINT: {
            print_point((Point *)shape->ptrShape);
            break;
        }

        case LINE: {
            print_line((Line *)shape->ptrShape);
            break;
        }

        case SQUARE: {
            print_square((Square *)shape->ptrShape);
            break;
        }

        case RECTANGLE: {
            print_rectangle((Rectangle *)shape->ptrShape);
            break;
        }

        case CIRCLE: {
            print_circle((Circle *)shape->ptrShape);
            break;
        }

        case POLYGON: {
            print_polygon((Polygon *)shape->ptrShape);
            break;
        }
    }
}