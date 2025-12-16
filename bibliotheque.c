#include <stdio.h>
#include <stdlib.h>
#include "bible.h"


typedef struct {
        int* nb;
        char* nom;
        char* auteurs;
        char* date;

}livres;


int affiche_bibli (int *pt_nb, char ** pt_nom, char** pt_auteur, int *pt_date)
{


    for (int i = 0; i < *pt_nb; i++) {
    printf("Date : %d, Auteur : %s, Nom : %s\n", pt_date[i], pt_auteur[i], pt_nom[i]);

    }
    
    


    return 0;
}