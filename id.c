/* Project C: Vector Text-based Editor
Professeurs: Halim Djerroud, Fabien Calcado, Asma Gabis
Mars - Mai / 2023

Par Sébastien XU et Matthieu BACHELERIE */

// ************************************ IMPORT ************************************ //
#include "id.h"
// ******************************************************************************** //


unsigned int global_id = 0;

// Fonctions permettant d'incrémenter la variable global_id

unsigned int get_next_id() {
    global_id ++;
    return global_id;
}
