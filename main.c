#include <stdio.h>
#include <stdlib.h>

int main() {
    int choix;
    do {
        choix = menu();

        switch (choix) {
            case 1: {
                printf("Vous avez choisi l'option 1 : Démarrer une nouvelle partie \n");
                demarrerNouvellePartie();
                break;
            }
            case 2: {
                printf("Vous avez choisi l'option 2 : Sauvegarder la partie \n");
                sauvegarderPartie();
                break;
            }
            case 3: {
                printf("Vous avez choisi l'option 3 : Charger une partie \n");
                chargerPartie();
                break;
            }
            case 4: {
                printf("Vous avez choisi l'option 4 : Choisir un dictionnaire linguistique \n");
                choisirDictionnaire();
                break;
            }
            case 5: {
                printf("Vous avez choisi l'option 5 : Consulter les statistiques \n");
                afficherStatistiques();
                break;
            }
            case 6: {
                printf("Vous avez choisi l'option 6 : Choisir le niveau de difficulté \n");
                choisirNiveauDifficulte();
                break;
            }
            case 7: {
                printf("Vous avez choisi l'option 7 : Afficher les règles du jeu \n");
                afficherReglesJeu();
                break;
            }
            case 0:
                printf("Sortie du programme.\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);

    printf(" ******** \n");
    return 0;
}
