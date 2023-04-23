#include "stdio.h"
#include "shapes.h"
#include "fonctions.h"
#include "stdlib.h"
extern unsigned global_id;


int main() {
    Shape **shape_list = (Shape **) malloc(100 * sizeof(Shape *));

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
                            Point *p= (Point *) create_point_shape(px, py);
                            shape_list[global_id - 1] = (Shape *) p;

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
                            Line *l= (Point *)create_line_shape(px1,py1,px2, py2);
                            shape_list[global_id - 1] = (Shape *) l;


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
                            Square *s= (Point *)create_square_shape(px,py,length);
                            shape_list[global_id - 1] = (Shape *) s;


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
                            Rectangle *r= (Point *) create_rectangle_shape(px, py, length, width);
                            shape_list[global_id - 1] = (Shape *) r;


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
                            Circle *c = (Point *) create_circle_shape(px, py, radius);
                            shape_list[global_id - 1] = (Shape *) c;

                            printf("Votre cercle a ete ajoute !\n");;
                            break;
                        }
                        case '6': {
                            int n, x;
                            int * tab;
                            printf("Saisir les informations du polygone: \n Saisir le nombre de points :" );
                            scanf("%d", &n);

                            tab = (int*) malloc(2 *n * sizeof (int));
                            for (x=0 ; x< n; x++){
                                printf(">> Saisir les coordonnees x y du point %d : ", x + 1 );
                                scanf("%d %d", &tab[2*x], &tab[2*x+1]);

                                Polygon *poly = (Point *) create_polygon_shape(n, tab);
                                shape_list[global_id - 1] = (Shape *) poly;

                                printf("Votre polygone a ete ajoute \n");

                            }
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

                if (global_id == 0) {
                    printf("La liste est vide \n");
                }else{
                    for (int x = 0; x < global_id; x++){
                        print_shape(shape_list[x]);
                    }
                }
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

