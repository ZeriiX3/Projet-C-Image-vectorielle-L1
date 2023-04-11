#include "stdio.h"
#include "shapes.h"
#include "fonctions.h"


int main() {

    main_menu();
    char choix_action, choix_forme;
    scanf(" %c", &choix_action);

    switch (choix_action) {


        case 'A': {         // Ajouter une forme

            menu_A();
            scanf(" %c", &choix_forme);

            switch (choix_forme) {
                case '1': {
                    add_point();
                    break;
                }
                case '2': {
                    add_line();
                    break;
                }
                case '3': {
                    add_square();
                    break;
                }
                case '4': {
                    add_rectangle();
                    break; //rectangle
                }
                case '5': {
                    add_cercle();
                    break; // cercle
                }
                case '6': {
                    break; // polygon
                }
                case '7': {
                    break; // retourner au menu precedent
                }
                default :
                    printf("Ce numero n'existe pas\n");
            }
            break;
        }


        case 'B': {     // Afficher la liste des formes

            printf("Liste des formes\n");
            break;
        }


        case 'C' : {     // Suprimmer une forme de la liste

            printf("Veuillez selectionner la forme a supprimer : \n");
            break;
        }


        case 'D' : {    // Tracer le dessin

            printf("Voici le dessin demande\n");
            break;
        }


        case 'E' : {

            printf("Voici la liste des aides qui pourrait vous etre utiles : \n");
            break;
        }

        default:
            printf("Cette lettre n'existe pas\n");
    }



    /*
    printf("Liste des formes :\n");
    Point * p1 = create_point (10, 10);
    Point * p2 = create_point (15, 15);
    Line * l = create_line(p1,p2);
    Square * s = create_square(p1,2);
    Rectangle *r= create_rectangle(p2,10,5);
    Circle * rond = create_circle(p2,3);

    print_point(p1);
    print_line(l);
    print_square(s);
    print_rectangle(r);
    print_circle(rond);

    delete_point(p1);
    delete_point(p2);
    delete_line(l);
    delete_square(s);
    delete_rectangle(r);
    delete_circle(rond);
*/
    return 0;
}
