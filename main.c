#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bible.h"



int main(void)
{
   
    int nb;

    int nb2;


    

     printf("Combien de livres voulez-vous entrer aujourd'hui \n");
     scanf("%d",&nb);

    int *date = malloc(nb * sizeof(int));
    if (date == NULL)
    {
        printf("Erreur mémoire \n");
        return 1;
    }
    char** nom = malloc(nb * sizeof(char *));
    if (nom == NULL)
    {
        printf("Erreur mémoire \n");
        return 1;
    }

    char **auteurs = malloc(nb * sizeof(char *));
    if( auteurs == NULL)
    {
        printf("Erreur mémoire \n");
        return 1;
    }
      for (int i = 0; i<nb; i++)
        {
            nom[i] = malloc(100);
            auteurs[i] = malloc(100);
             printf("Date de sortie : \n");
            scanf("%d", &date[i]); // tu peux créer un tableau int dates[nb] si tu veux stocker tous
            getchar();
            printf("Auteur : \n");
            fgets(auteurs[i],100,stdin);
            auteurs[i][strcspn(auteurs[i],"\n")] = 0;
            printf("Nom : \n");
            fgets(nom[i],100,stdin);
            nom[i][strcspn(nom[i],"\n")] = 0;

        }


    affiche_bibli (&nb, nom, auteurs, date);
    
    printf("Tape 1 pour continuer à rentrer des oeuvres\n2 pour quitter\n");
    scanf("%d",&nb2);

    if(nb2 == 1)
    {
        printf("Au revoir ! \n");
    }
    else if(nb2 == 2)
    {
        int add;
        printf("Combien d'entrées voulez-vous faire ?\n");
        scanf("%d",&add);
        nom = realloc(nom, (nb + add) * sizeof(char *));
        if (nom == NULL)
        {
            printf("Erreur mémoire\n");
            return 1;
        } 
        if (auteurs == NULL)
        {
            printf("Erreur mémoire \n");
            return 1;
        }
        for (int i = 0; i<nb+add; i++)
        {
            nom[i] = malloc(100);
            auteurs[i] = malloc(100);
             printf("Date de sortie : \n");
            scanf("%d", &date[i]); // tu peux créer un tableau int dates[nb] si tu veux stocker tous
            getchar();
            printf("Auteur : \n");
            fgets(auteurs[i],100,stdin);
            auteurs[i][strcspn(auteurs[i],"\n")] = 0;
            printf("Nom : \n");
            fgets(nom[i],100,stdin);
            nom[i][strcspn(nom[i],"\n")] = 0;

        }
        nb += add;
    }
    affiche_bibli(&nb,nom,auteurs,date);

    for(int i = 0; i<nb; i++)
    {
    free(nom[i]);
    free(auteurs[i]);
    }
    free(nom);
    free(auteurs);


    return 0;
}
