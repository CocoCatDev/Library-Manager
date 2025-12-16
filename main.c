#include <stdio.h>
#include <stdlib.h>

#include "bible.h"



int main(void)
{
   
    int nb;


    int date;

     printf("Combien de livres voulez-vous entrer aujourd'hui \n");
     scanf("%d",&nb);


    char** nom = malloc(nb * sizeof(char *));
    if (nom == NULL)
    {
        printf("Erreur mémoire \n");
    }

    char **auteurs = malloc(nb * sizeof(char *));
    if( auteurs == NULL)
    {
        printf("Erreur mémoire \n");
    }
    for (int i = 0; i < nb; i++) {
    nom[i] = malloc(100 * sizeof(char));      // 100 caractères max
    auteurs[i] = malloc(100 * sizeof(char));
}
    for (int i = 0; i < nb; i++) {
    printf("Date de sortie : ");
    scanf("%d", &date); // tu peux créer un tableau int dates[nb] si tu veux stocker tous
    printf("Auteur : \n");
    scanf("%s",auteurs[i]);
    printf("Nom : \n");
    scanf("%s",nom[i]);

}


    affiche_bibli (&nb, nom, auteurs, &date);

    for(int i = 0; i<nb; i++)
    {
    free(nom[i]);
    free(auteurs[i]);
    }
    free(nom);
    free(auteurs);
    return 0;
}
