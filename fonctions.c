//
// Created by Seb on 11/04/2023.
//

#include "fonctions.h"
#include "shapes.h"
#include "stdio.h"



// Affichage des menus

void main_menu() {

    printf("START\n");
    printf("Veuillez choisir une action :\n");
    printf("    A- Ajouter une forme\n");
    printf("    B- Afficher la liste des formes\n");
    printf("    C- Supprimer une forme de la liste\n");
    printf("    D- Tracer le dessin\n");
    printf("    E- Aide\n");
    printf("    F - Quitter le programme\n");
    printf(">> Votre choix : ");
}

void menu_A() {

    printf("Veuillez choisir une action :\n");
    printf("    1- Ajouter un point\n");
    printf("    2- Ajouter une ligne\n");
    printf("    3- Ajouter un cube\n");
    printf("    4- Ajouter un rectangle\n");
    printf("    5- Ajouter un cercle\n");
    printf("    6- Ajouter un polygone\n");
    printf("    7- Revenir ua menu precedent\n");
    printf(">> Votre choix : ");
}

void add_point() {
    int px, py;
    printf("Saisir les informations du point :\n");
    printf(">> Saisir les coordonnees x y : ");
    scanf("%d %d",&px, &py);

    printf("Votre point a ete ajoute !\n");
}

void add_line() {
    int px1, py1, px2, py2;
    printf("Saisir les informations pour la ligne :\n");
    printf(">> Saisir les coordonnees du premier point x1 y1 : ");
    scanf("%d %d",&px1, &py1);
    printf(">> Saisir les coordonnees deuxieme point x2 y2 : ");
    scanf("%d %d",&px2, &py2);

    printf("Votre ligne a ete ajoute !\n");
}

void add_square() {
    int px, py, length;
    printf("Saisir les informations pour le cube :\n");
    printf(">> Saisir les coordonnees du point x y : ");
    scanf("%d %d",&px, &py);
    printf(">> Saisir la longueur des cotes du cube : ");
    scanf("%d",&length);

    Point * p = create_point(px,py);
    Square * s = create_square(p, length);
    printf("Votre cube a ete ajoute !\n");
}

void add_rectangle() {
    int px, py, length, width;
    printf("Saisir les informations pour le rectangle :\n");
    printf(">> Saisir les coordonnees du point x y : ");
    scanf("%d %d",&px, &py);
    printf(">> Saisir la longueur du rectangle : ");
    scanf("%d",&length);
    printf(">> Saisir la largeur du rectangle : ");
    scanf("%d",&width);

    Point * p = create_point(px,py);
    Rectangle * r = create_rectangle(p, length, width);
    printf("Votre rectangle a ete ajoute !\n");
}

void add_cercle() {
    int px, py, radius;
    printf("Saisir les informations pour le cercle :\n");
    printf(">> Saisir le point centre x y : ");
    scanf("%d %d",&px, &py);
    printf(">>Saisir le rayon du cercle : ");
    scanf("%d",&radius);

    Point * p = create_point(px,py);
    Circle * c = create_circle(p,radius);
    printf("Votre rectangle a ete ajoute !\n");
}