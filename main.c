#include "stdio.h"
#include "shapes.h"
#include "fonctions.h"
extern unsigned global_id;


int main() {

    char choix_action, choix_forme;

    do {
        main_menu();
        scanf(" %c", &choix_action);

        switch (choix_action) {


            case 'A': {         // Ajouter une forme

                do {
                    menu_A();
                    scanf(" %c", &choix_forme);

                    switch (choix_forme) {

                        case '1': {
                            int px, py;
                            printf("Saisir les informations du point :\n");
                            printf(">> Saisir les coordonnees x y : ");
                            scanf("%d %d",&px, &py);
                            Shape *create_point_shape(int px, int py);

                            printf("Votre point a ete ajoute !\n");;
                            break;
                        }
                        case '2': {
                            int px1, py1, px2, py2;
                            printf("Saisir les informBations pour la ligne :\n");
                            printf(">> Saisir les coordonnees du premier point x1 y1 : ");
                            scanf("%d %d",&px1, &py1);
                            printf(">> Saisir les coordonnees deuxieme point x2 y2 : ");
                            scanf("%d %d",&px2, &py2);
                            Shape *create_line_shape(int px1, int py1, int px2, int py2);


                            printf("Votre ligne a ete ajoute !\n");;
                            break;
                        }
                        case '3': {
                            int px, py, length;
                            printf("Saisir les informations pour le cube :\n");
                            printf(">> Saisir les coordonnees du point x y : ");
                            scanf("%d %d",&px, &py);
                            printf(">> Saisir la longueur des cotes du cube : ");
                            scanf("%d",&length);
                            Shape *create_square_shape(int px, int py, int length);


                            printf("Votre cube a ete ajoute !\n");;
                            break;
                        }
                        case '4': {
                            int px, py, length, width;
                            printf("Saisir les informations pour le rectangle :\n");
                            printf(">> Saisir les coordonnees du point x y : ");
                            scanf("%d %d",&px, &py);
                            printf(">> Saisir la longueur du rectangle : ");
                            scanf("%d",&length);
                            printf(">> Saisir la largeur du rectangle : ");
                            scanf("%d",&width);
                            Shape *create_rectangle_shape(int px, int py, int length, int width);


                            printf("Votre rectangle a ete ajoute !\n");;
                            break;
                        }
                        case '5': {
                            int px, py, radius;
                            printf("Saisir les informations pour le cercle :\n");
                            printf(">> Saisir le point centre x y : ");
                            scanf("%d %d",&px, &py);
                            printf(">>Saisir le rayon du cercle : ");
                            scanf("%d",&radius);
                            Shape *create_circle_shape(int px, int py, int radus);


                            printf("Votre cercle a ete ajoute !\n");;
                            break;
                        }
                        case '6': {
                            break; // polygon
                        }
                        case '7': {
                            break; // retourner au menu precedent
                        }
                        default:
                            printf("Ce chiffre correspond a aucun menu");
                    }

                } while (choix_forme != '7');
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


            case 'F' : {
                break;
            }

            default:
                printf("Cette lettre n'existe pas\n");
        }

    }while (choix_action != 'F');

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