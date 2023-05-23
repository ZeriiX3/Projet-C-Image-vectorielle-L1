/* Project C: Vector Text-based Editor
Professeurs: Halim Djerroud, Fabien Calcado, Asma Gabis
Mars - Mai / 2023

Par Sébastien XU et Matthieu BACHELERIE */


// ************************************ IMPORT ************************************ //
#include "fonctions.h"
#include "shapes.h"
#include "stdio.h"
// ******************************************************************************** //


// Affichage des menus

void main_menu() {

    printf("Bienvenue dans le menu!\n\n");
    printf("Veuillez choisir une action :\n");
    printf("    A- Ajouter une forme\n");
    printf("    B- Afficher la liste des formes\n");
    printf("    C- Supprimer une forme de la liste\n");
    printf("    D- Tracer le dessin\n");
    printf("    E- Effacer l'ecran\n");
    printf("    F- Redimentionner l'ecran\n");
    printf("    G- Quitter le programme\n");
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
    printf("    7- Revenir au menu precedent\n");
    printf(">> Votre choix : ");
}


// Fonctions permettant de calculer le maximum et le minimum

int min(int x, int y){
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int max(int x, int y){
    if (x > y){
        return x;
    }
    else{
        return y;
    }
}
