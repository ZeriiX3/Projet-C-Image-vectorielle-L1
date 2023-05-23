//
// Created by Seb on 23/05/2023.
//

#ifndef PROJET_VECTEUR_COMMAND_H
#define PROJET_VECTEUR_COMMAND_H

#include "area.h"

typedef struct command{
    char name[50];
    int int_size;
    int int_params[10];
    int str_size;
    char* str_params[10];
}Command;


Command* create_command();
void free_cmd(Command* cmd);
int read_exec_command(Command* cmd, int* state, Area* area);



#endif //PROJET_VECTEUR_COMMAND_H




