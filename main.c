/* Project C: Vector Text-based Editor
Professeurs: Halim Djerroud, Fabien Calcado, Asma Gabis
Mars - Mai / 2023

Par Sébastien XU et Matthieu BACHELERIE */


// ************************************ IMPORT ************************************ //
#include <stdio.h>
#include <stdlib.h>

#include "shapes.h"
#include "fonctions.h"
#include "area.h"

extern unsigned global_id;
// ******************************************************************************** //





// ******************************************************************************** //
// ******************************************************************************** //
// ******************************************************************************** //
// ****************************** Boucle principale ******************************* //
// ******************************************************************************** //
// ******************************************************************************** //
// ******************************************************************************** //


int main() {

    // Déclaration des variables //
    char choix_action, choix_forme;

    // Allocation des espaces mémoires //
    Shape **shape_list = (Shape **) malloc(100 * sizeof(Shape *));
    Area *area = create_area(10, 10);


    // Début du menu

    do {
        main_menu();    // Fonction permettant l'affichage du texte

        scanf(" %c", &choix_action);    // Demande à l'utilisateur de saisir une action

        switch (choix_action) {


            case 'A': {         // Ajouter une forme
                do {
                    menu_A();       // Fonction permettant l'affichage du texte
                    scanf(" %c", &choix_forme);     // Demande à l'utilisateur de saisir une action

                    switch (choix_forme) {

                        case '1': {     // POINT
                            // Demande des informations pour la création de POINT
                            int px, py;
                            printf("Saisir les informations du point :\n");
                            printf(">> Saisir les coordonnees x y : ");
                            scanf("%d %d",&px, &py);
                            // Création du shape et ajout dans la shape area
                            Shape *p= create_point_shape(px, py);
                            shape_list[global_id - 1] = (Shape *) p;
                            add_shape_to_area(area, p);

                            printf("Votre point a ete ajoute !\n");
                            break;
                        }
                        case '2': {     // LINE
                            // Demande des informations pour la création de LINE
                            int px1, py1, px2, py2;
                            printf("Saisir les informations pour la ligne :\n");
                            printf(">> Saisir les coordonnees du premier point x1 y1 : ");
                            scanf("%d %d",&px1, &py1);
                            printf(">> Saisir les coordonnees deuxieme point x2 y2 : ");
                            scanf("%d %d",&px2, &py2);
                            // Création du shape et ajout dans la shape area
                            Shape *l= create_line_shape(px1,py1,px2, py2);
                            shape_list[global_id - 1] = (Shape *) l;
                            add_shape_to_area(area, l);

                            printf("Votre ligne a ete ajoute !\n");
                            break;
                        }
                        case '3': {
                            // Demande des informations pour la création de SQUARE
                            int px, py, length;
                            printf("Saisir les informations pour le carre :\n");
                            printf(">> Saisir les coordonnees du point x y : ");
                            scanf("%d %d",&px, &py);
                            printf(">> Saisir la longueur des cotes du cube : ");
                            scanf("%d",&length);
                            // Création du shape et ajout dans la shape area
                            Shape *s= create_square_shape(px,py,length);
                            shape_list[global_id - 1] = (Shape *) s;
                            add_shape_to_area(area,s);

                            printf("Votre cube a ete ajoute !\n");
                            break;
                        }
                        case '4': {
                            // Demande des informations pour la création de RECTANGLE
                            int px, py, length, width;
                            printf("Saisir les informations pour le rectangle :\n");
                            printf(">> Saisir les coordonnees du point x y : ");
                            scanf("%d %d",&px, &py);
                            printf(">> Saisir la longueur du rectangle : ");
                            scanf("%d",&length);
                            printf(">> Saisir la largeur du rectangle : ");
                            scanf("%d",&width);
                            // Création du shape et ajout dans la shape area
                            Shape *r= create_rectangle_shape(px, py, length, width);
                            shape_list[global_id - 1] = (Shape *) r;
                            add_shape_to_area(area,r);

                            printf("Votre rectangle a ete ajoute !\n");
                            break;
                        }
                        case '5': {
                            // Demande des informations pour la création de CIRCLE
                            int px, py, radius;
                            printf("Saisir les informations pour le cercle :\n");
                            printf(">> Saisir le point centre x y : ");
                            scanf("%d %d",&px, &py);
                            printf(">>Saisir le rayon du cercle : ");
                            scanf("%d",&radius);
                            // Création du shape et ajout dans la shape area
                            Shape *c = create_circle_shape(px, py, radius);
                            shape_list[global_id - 1] = (Shape *) c;
                            add_shape_to_area(area,c);

                            printf("Votre cercle a ete ajoute !\n");
                            break;
                        }
                        case '6': {
                            // Demande des informations pour la création de POLYGON
                            int n, x;
                            int * points;
                            printf("Saisir les informations du polygone: \n Saisir le nombre de points :" );
                            scanf("%d", &n);
                            // Allocation de l'espace mémoire
                            points = (int*) malloc(2 * n * sizeof (int));
                            for (x=0 ; x< n; x++){
                                printf(">> Saisir les coordonnees x y du point %d : ", x + 1 );
                                scanf("%d %d", &points[2 * x], &points[2 * x + 1]);
                            }
                            // Création du shape et ajout dans la shape area
                            Shape *poly = create_polygon_shape(n, points);
                            shape_list[global_id - 1] = (Shape *) poly;
                            add_shape_to_area(area,poly);

                            printf("Votre polygone a ete ajoute \n");
                            break; // polygon
                        }
                        case '7': {
                            break; // Retourner au menu precedent
                        }
                        default:
                            printf("Ce chiffre ne correspond a aucun menu");

                    }
                } while (choix_forme != '7');
            }


            case 'B': {     // Affichage de la liste des formes

                printf("Liste des formes\n");

                if (global_id == 0) {
                    printf("La liste est vide \n");
                }
                else{
                    for(int i = 0; i < area->nb_shape; i++) {
                        printf("(ID = %d) ", area->shapes[i]->id);
                        print_shape(area->shapes[i]);
                        printf("\n");
                    }
                }
                break;

            }


            case 'C' : {     // Suprimmer une forme de la liste

                printf("Veuillez selectionner la forme a supprimer : \n");

                // Affichage de la liste des formes
                printf("Liste des formes\n");
                if (global_id == 0) {
                    printf("La liste est vide\n");
                }
                else{
                    for(int i = 0; i < area->nb_shape; i++) {
                        printf("(ID=%d) ", area->shapes[i]->id);
                        print_shape(area->shapes[i]);
                        printf("\n");
                    }
                }
                printf(">>> ");

                // Supprime la forme de la liste
                int id;
                scanf("%d",&id);
                area->nb_shape--;
                for (int i = 0; i < area->nb_shape; ++i) {
                    if (area->shapes[i]->id == id) {
                        delete_shape(area->shapes[i]);
                        // Décalage des éléments suivants vers la gauche
                        for (int j = i; j < area->nb_shape; ++j) {
                            area->shapes[j] = area->shapes[j + 1];
                        }
                        break;
                    }
                }
                break;
            }


            case 'D' : {    // Tracer le dessin

                printf("Voici le dessin demande\n\n");
                draw_area(area);
                print_area(area);
                break;

            }


            case 'E' : {    // Reset l'ecran à 0

                erase_area(area);
                break;

            }

            case 'F': {     // Redimentionne l'ecran
                int width, height;
                printf("Saisissez la nouvelle taille de l'ecran : ");
                printf("x >>> ");
                scanf("%d",&width);
                printf("y >>> ");
                scanf("%d",&height);

                Shape** temp = area->shapes;
                int temp_size = area->nb_shape;

                *area = *create_area(width, height);

                for(int i = 0; i < temp_size; i++) {
                    add_shape_to_area(area, temp[i]);
                }
                break;
            }

            case 'G' : {
                break;      // Quitte le jeu
            }

            default:
                printf("Cette lettre n'existe pas\n");
        }

    }while (choix_action != 'G');


    return 0;
}
