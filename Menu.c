#include <stdio.h>
#include <stdlib.h>

int menu() {
    int choix;
    do {
        printf("Voici le menu du jeu du Pendu \n");
        printf("Selectionner :\n");
        printf("0- Quitter \n");
        printf("1- Démarrer une nouvelle partie \n");
        printf("2- Sauvegarder la partie \n");
        printf("3- Charger une partie \n");
        printf("4- Choisir un dictionnaire linguistique \n");
        printf("5- Consulter les statistiques \n");
        printf("6- Choisir le niveau de difficulté \n");
        printf("7- Afficher les règles du jeu \n");
        printf("Saisir votre choix : ");
        scanf("%d", &choix);
    } while (choix < 0 || choix > 7);
    return choix;
}
