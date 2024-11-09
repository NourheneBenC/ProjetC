#ifndef PENDU_H__
#define PENDU_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100
#define t_d 20
#define n_c 100
	struct dictionnaire {
		char mot[20];
		char indice[20];
	};
	typedef struct dictionnaire dictionnaire;
	struct current {
		char mot[20];
		char indice[20];
		char c_mot[20];
		int tentative;
	};
	typedef struct current current ;
	struct compte{
		char login[20];
		char password[20];
	};
	typedef struct compte compte;

	struct save {
		compte c ;
		current play ;
	};
	typedef struct save save ;
//-------------------------FONCTIONS D'AFFICHAGE DE PENDU-----------------------------------------
	void afficher_pendu_0();
	void afficher_pendu_1();
	void afficher_pendu_2();
	void afficher_pendu_3();
	void afficher_pendu_4();
	void afficher_pendu_5();
	void afficher_pendu_6();
	void afficher_clavier(char tab[], int taille);
	void afficher_partie(current c,char tab2[], int taille2, compte joueur);
	void afficher_tab(char tab[], int taille);

//-------------------------FONCTIONS DE SAISIES-----------------------------------------
	char saisir_lettre();
	void saisir_chaine(char chaine [], int taille, char const * mess);
    char mettre_en_majuscule(char lettre);
	void afficher_dictionnaire(dictionnaire d [], int taille );

//-------------------------FONCTIONS DE CURRENTS-----------------------------------------

	void creer_current(current * c, dictionnaire d[t_d], int id);
	void afficher_current(current c);
	void afficher_current_tab(current c);

//-------------------------FONCTIONS DE COMPTES-----------------------------------------


//-------------------------FONCTIONS DE COMPTES-----------------------------------------

	void creer_compte(compte c[], int * taille, compte * joueur);
	int importer_compte(compte c[]);
	void afficher_compte(compte c[], int taille);
	void exporter_compte(compte c[], int taille);
	int rechercher_compte(compte c[], int taille);
	void authentification_compte(compte c[], int taille, compte * joueur);
	void menu_compte(compte c[], int * taille, compte * joueur);
	void menu();

//-------------------------FONCTIONS DE JEU-----------------------------------------

	int verifier_lettre(current * c, char lettre, int * cmp, char clavier[], int taille_clavier);
	void menu_principal(compte joueur);
	void menu_nouvelle_partie(save s[n], int * taille_s, compte joueur);
	void menu_jouer_partie(save s[n], int * taille_s, compte joueur);
	void jouer_partie(save s[n], int * taille_s, compte joueur, int choix);
	void charger_partie(save s[n], int taille_s, compte joueur);
	void refaire_partie(save s[n], int * taille_s, compte joueur, int rep);
	void supprimer_de_clavier(char clavier[], int taille_clavier, char lettre);

//-------------------------FONCTIONS DE SAUVEGARDE-----------------------------------------
//Fonction concernant la sauvegarde d'une partie
    void sauvegarder_partie(save s[n], int * taille, compte joueur, current c);
    void exporter_sauvegarde(save s[n], int taille);
    int importer_sauvegarde(save s[n]);
    void afficher_sauvegarde_partie(save s[n], int taille);
    void afficher_s_actu(save s[n], int taille);

//-------------------------FONCTIONS IMPORTER NIVEAUX-----------------
    int importer_niveau(dictionnaire d [t_d], int choix);
    void exporter_niveau(dictionnaire d[t_d],int taille_d, int choix);


//-------------------------FONCTIONS DE STATISTIQUES------------------
    void afficher_statistiques(save s[n], int taille_s, compte joueur);
    void afficher_stat_jeu(compte joueur, current c);

//-------------------------FONCTIONS REMPLIR FICHIERS-----------------

void remplir_fichier_niveaux(int choix);

#endif
