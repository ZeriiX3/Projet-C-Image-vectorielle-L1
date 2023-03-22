#include <stdio.h>
#include "fonctions.h"


int main() {

    Point * p1;
    p1 = create_point(10,15);
    print_point(p1);
    delete_point(p1);
    return 0;
}
