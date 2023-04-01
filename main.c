#include <stdio.h>
#include "shapes.h"

int main() {
    printf("Liste des formes :\n");
    Point * p1 = create_point (10, 10);
    Point * p2 = create_point (15, 15);
    Line * l = create_line(p1,p2);
    Square * s = create_square(p1,2);
    Rectangle *r= create_rectangle(p2,10,5);

    print_point(p1);
    print_line(l);
    print_square(s);
    print_rectangle(r);

    delete_point(p1);
    delete_point(p2);
    delete_line(l);
    delete_square(s);
    delete_rectangle(r);

    return 0;
}
