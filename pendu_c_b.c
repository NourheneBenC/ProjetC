#include "pendu_c_b.h"

void refaire_partie(save s[n],int * taille_s,compte joueur, int rep){
	char choix = '1';
	do{do{
        if(choix == '1'){
        jouer_partie(s,taille_s,joueur,rep);}
        printf("-------------------------------------------\n");
        printf("1.Rejouer une partie\n2.Retour au menu\n");
        printf("-------------------------------------------\n");
        printf("Veuillez choisir une option : ");
        scanf(" %c",&choix);

	}while(choix != '2' && choix != '1');
	if(choix == '2'){
		system("cls");
		menu_jouer_partie(s,taille_s,joueur);
	}

}while(choix == '1');
}
void menu_jouer_partie(save s[n], int * taille_s, compte joueur){
	char choix;
	int rep;
	do{
       printf("---------------------------------\n");
        printf("NIVEAU DE JEU\n");
        printf("---------------------------------\n");
        printf("1.Facile\n2.Moyen\n3.Difficile\n4.Retour\n");
        printf("---------------------------------\n");
        printf("Veuillez choisir une option : ");
        scanf(" %c",&choix);
	}while(choix != '1' && choix != '2' && choix != '3' && choix != '4');
             //init_compte(joueur);

	switch(choix){
		case '1':
			system("cls");
			rep = 1;
			refaire_partie(s,taille_s,joueur,rep);
			break;
		case '2':
		    system("cls");
			rep = 2;
			refaire_partie(s,taille_s,joueur,rep);
			break;
		case '3':
		    system("cls");
			rep = 3;
			refaire_partie(s,taille_s,joueur,rep);
			break;
        case '4':
			system("cls");
			menu_nouvelle_partie(s,taille_s,joueur);
			break;

}}
void menu_nouvelle_partie(save s[n], int * taille_s, compte joueur) {
	char choix;
	do{
	printf("---------------------------------\n");
	printf("NOUVELLE PARTIE\n");
	printf("---------------------------------\n");
	printf("1.Jouer une partie\n2.Regles du jeu\n3.Retour\n");
	printf("---------------------------------\n");
	printf("Veuillez choisir une option : ");
	scanf(" %c",&choix);}while(choix != '1' && choix != '2' && choix != '3');
	switch(choix){
		case '1':
			system("cls");
			menu_jouer_partie(s,taille_s,joueur);
			break;
		case '2':
			//menu_regles_partie();
			break;
		case '3':
			system("cls");
			menu_principal(joueur);
			break;
}}
void menu_principal(compte joueur){
    save s [n];
    int taille_s = importer_sauvegarde(s);
	char choix;
	do{
	printf("---------------------------------\n");
	printf("BIENVENUE AU JEU DU PENDU\n");
	printf("---------------------------------\n");
	printf("1.Nouvelle partie\n2.Charger une partie\n3.Statistiques des paties\n4.Quitter\n");
	printf("---------------------------------\n");
	printf("Veuillez choisir une option : ");
	scanf(" %c",&choix);}while(choix != '1' && choix != '2' && choix != '3' && choix != '4');
	switch(choix){
		case '1':
			system("cls");
			menu_nouvelle_partie(s,&taille_s,joueur);
			break;
		case '2':
            charger_partie(s,taille_s,joueur);
			break;
		case '3':
		    system("cls");
            afficher_statistiques(s,taille_s,joueur);
            menu_principal(joueur);
			break;
		case '4':
		    menu();
			break;
	}
}

void afficher_pendu_0(){
	printf("----------------------------------\n");
}

void afficher_pendu_1(){
	afficher_pendu_0();
	printf("\t\t\t\t |\n");
}

void afficher_pendu_2(){
	afficher_pendu_1();
	printf("\t\t\t\t/ ");
}

void afficher_pendu_3(){
	afficher_pendu_2();
	printf("\\\n");
}

void afficher_pendu_4(){
	afficher_pendu_3();
	printf("\t\t\t\t |\n");
}

void afficher_pendu_5(){
	afficher_pendu_4();
	printf("\t\t\t\t/ ");
}

void afficher_pendu_6(){
	afficher_pendu_5();
	printf("\\\n");
}

void afficher_tab(char tab [], int taille){
	int i ;
	//printf("\t\t\t\t\t");
	for (i = 0; i < taille ; i++){
		printf("%c\t",tab[i]);
	}
	printf("\n\n\n");

}

void afficher_clavier(char tab[], int taille){
	int i, cpt = 0;
	printf("\t\t\t\t\t");
	for(i = 0; i < 26; i++){
		printf("[%c]\t",tab[i]);
		cpt++;
		if(cpt == 6){
			printf("\n\t\t\t\t\t");
			cpt = 0;
		}
		if(i == 23){
			printf("\t\t");
		}
	}
	printf("\n");
}

void supprimer_de_clavier(char clavier[], int taille_clavier,char lettre){
	int i ;
	for (i = 0 ; i < 26; i++){
		if(clavier[i] == lettre){
			clavier[i] = ' ';
		}
	}
}
//------------------------------FONCTIONS DE SAISIES---------------------------------------------
void saisir_chaine(char chaine [], int taille, char const* mess){
    printf("Veuillez saisir votre %s : ",mess);
	fgets(chaine,taille,stdin);
	chaine[strcspn(chaine,"\n")] = '\0';

}
char saisir_lettre(){
	char lettre;
	printf("Veuillez saisir une lettre : ");
	scanf(" %c",&lettre);
	return lettre ;
}


void afficher_partie(current c, char tab2[],int taille2, compte joueur){

	switch(c.tentative){
		case 0:
		    afficher_stat_jeu(joueur,c);
			afficher_pendu_0();
			afficher_current_tab(c);
			afficher_clavier(tab2,taille2);
			break;
		case 1:
		    afficher_stat_jeu(joueur,c);
			afficher_pendu_1();
			afficher_current_tab(c);
			afficher_clavier(tab2,taille2);
			break;
		case 2:
		    afficher_stat_jeu(joueur,c);
			afficher_pendu_2();
			printf("\n");
			afficher_current_tab(c);
			afficher_clavier(tab2,taille2);
			break;
		case 3:
		    afficher_stat_jeu(joueur,c);
			afficher_pendu_3();
			afficher_current_tab(c);
			afficher_clavier(tab2,taille2);
			break;
		case 4:
		    afficher_stat_jeu(joueur,c);
			afficher_pendu_4();
			afficher_current_tab(c);
			afficher_clavier(tab2,taille2);
			break;
		case 5:
		    afficher_stat_jeu(joueur,c);
			afficher_pendu_5();
			printf("\n");
			afficher_current_tab(c);
			afficher_clavier(tab2,taille2);
			break;
		case 6:
		    afficher_stat_jeu(joueur,c);
			afficher_pendu_6();
			afficher_current_tab(c);
			afficher_clavier(tab2,taille2);
			break;

	}
}
//----------------------------FONCTIONS IMPORTER NIVEAUX--------------------
//Cette fonction permet de remplir le dictionnaire à partie du fichier contenant les mots
int importer_niveau(dictionnaire d [t_d], int choix){
    int i;
	int taille;
    if(choix == 1){
        FILE * f = fopen("Facile.txt","r");
        if(f == NULL){
            FILE * f = fopen("Facile.txt","w");
            taille = 0;
            fprintf(f,"%d\n",taille);
            return taille;
            fclose(f);
        }
        else{
            fscanf(f,"%d\n",&taille);
            //printf("La taille est : %d\n",taille);
            for (i = 0; i < taille ; i++){
            fscanf(f,"%s %s\n",d[i].mot,d[i].indice);
            }
        //taille++;
            fclose(f);
            printf("Fichier niveau facile importe !\n");
            return taille;
        }
    }
    else if(choix == 2){
        FILE * f = fopen("Moyen.txt","r");
        if(f == NULL){
            FILE * f = fopen("Moyen.txt","w");
            taille = 0;
            fprintf(f,"%d\n",taille);
            return taille;
            fclose(f);
        }
        else{
            fscanf(f,"%d\n",&taille);
            printf("La taille est : %d\n",taille);
            for (i = 0; i < taille ; i++){
            fscanf(f,"%s %s\n",d[i].mot,d[i].indice);
            }
            fclose(f);
            printf("Fichier niveau moyen importe !\n");
            return taille;
            }
    }
    else {
        FILE * f = fopen("Difficile.txt","r");
        if(f == NULL){
            FILE * f = fopen("Difficile.txt","w");
            taille = 0;
            fprintf(f,"%d\n",taille);
            return taille;
            fclose(f);
        }
        else{
            fscanf(f,"%d\n",&taille);
            printf("La taille est : %d\n",taille);
            for (i = 0; i < taille ; i++){
            fscanf(f,"%s %s\n",d[i].mot,d[i].indice);
            }
            fclose(f);
            printf("Fichier niveau difficile importe !\n");
            return taille;
        }
    }

}


void exporter_niveau(dictionnaire d[t_d], int taille_d, int choix){
    int i;
    if(choix == 1){
        FILE * f = fopen("Facile.txt","w");
        fprintf(f,"%d\n",taille_d);
        for (i = 0; i < taille_d ; i++){
		fprintf(f,"%s %s\n",d[i].mot,d[i].indice);
        }
        fclose(f);
    }
    else if(choix == 2){
        FILE * f = fopen("Moyen.txt","w");
        fprintf(f,"%d\n",taille_d);
        for (i = 0; i < taille_d ; i++){
		fprintf(f,"%s %s\n",d[i].mot,d[i].indice);
        }
        fclose(f);
    }
    else {
        FILE * f = fopen("Difficile.txt","w");
        fprintf(f,"%d\n",taille_d);
        for (i = 0; i < taille_d ; i++){
		fprintf(f,"%s %s\n",d[i].mot,d[i].indice);
        }
        fclose(f);
}}


//-----------------------FONCTIONS DE CURRENT-------------------------------

void creer_current(current * c, dictionnaire d[t_d], int id){
	strcpy(c->mot,d[id].mot);
	strcpy(c->indice,d[id].indice);
	c->tentative = 0;
	int i ;
	for(i = 0 ; i < strlen(d[id].mot) ; i++){
		c->c_mot[i] = '_';
	}
    c->c_mot[i++] = '\0';
}

void afficher_current(current c){
        printf("-------------------------------------------\n");
		printf("Mot : %s |Indice : %s |Actuel : ",c.mot,c.indice);
		int i ;
		for(i = 0 ; i < strlen(c.mot); i++){
			printf("%c",c.c_mot[i]);
		}
		printf(" |Tentative : %d\n",c.tentative);
		printf("-------------------------------------------\n");
}

void afficher_current_tab(current c){
	int i ;
		for(i = 0 ; i < strlen(c.mot); i++){
			printf("%c\t",c.c_mot[i]);
		}
		printf("\n\n\n");
}
//-----------------------------------------------------------------------------



void afficher_dictionnaire(dictionnaire d [], int taille ){
	int i;
	for(i = 0 ; i < taille ; i++){
		printf("le mot %d est : %s et son indice est : %s\n",i+1,d[i].mot,d[i].indice);
	}
	printf("\n");
}

//-------------------------FONCTIONS DE COMPTES ----------------------------------------


void creer_compte(compte c[], int * taille, compte * joueur){
	//FILE * f = fopen("Compte.txt","a+");
    int i;
	char login [20], password[20];
    printf("Veuillez saisir votre login : ");
    scanf("%s",login);
    printf("Veuillez saisir votre password : ");
    scanf("%s",password);
	for ( i = 0 ; i < strlen(login) ; i++){
        login[i] = mettre_en_majuscule(login[i]);
	}
	//saisir_chaine(password,20,"mot de passe");
	strcpy(c[*taille].login,login);
	strcpy(c[*taille].password,password);
	(*taille)++;
	strcpy(joueur->login,login);
    strcpy(joueur->password,password);
	printf("Votre compte a ete cree avec succes %s!\n",login);
	//fclose(f);
}

int importer_compte(compte c[]){
	FILE * f = fopen("Compte.txt","r+");
	if (f == NULL){
        int taille = 0;
        FILE * f = fopen("Compte.txt","w");
        printf("Bonjour");
        fprintf(f,"%d\n",taille);
        fclose(f);
        return taille;
	}
	int taille ;
	fscanf(f,"%d\n",&taille);
	int i ;
	for( i = 0 ; i < taille ; i++){
		fscanf(f,"%s %s\n",c[i].login,c[i].password);
	}
	printf("Logins et passwords importes avec succes !\n");
	fclose(f);
	return taille;
}

void exporter_compte(compte c[], int taille){
	FILE * f = fopen("Compte.txt","w");
	int i ;
	fprintf(f,"%d\n",taille);
	for(i = 0 ; i < taille ; i++){
		fprintf(f,"%s %s\n",c[i].login,c[i].password);
	}
	printf("Logins et passwords exportes avec succes !\n");
	fclose(f);
}


void afficher_compte(compte c[], int taille){
	int i;
	if(taille == 0){
        printf("Aucun compte n'est cree !\n");
	}
	for(i = 0 ; i < taille ; i++){
		printf("Compte_%d\nLogin : %s\nPassword : %s\n",i+1,c[i].login,c[i].password);
	}
}

char mettre_en_majuscule(char lettre){
    if(lettre >= 97 && lettre <= 122){
        lettre = lettre - 32;
    }
    return lettre ;
}

int rechercher_compte(compte c [], int taille){
    int i;
    char login [20], password [20];
    printf("Veuillez saisir votre login : ");
    scanf("%s",login);
    printf("Veuillez saisir votre password : ");
    scanf("%s",password);
	//fgets(login,20,stdin);
	//login[strcspn(login,"\n")] = '\0';
    //saisir_chaine(password,20,"password");
    for(i = 0 ; i < strlen(login) ; i++){
        login[i] = mettre_en_majuscule(login[i]);
    }
    for(i = 0  ; i < taille; i++){
        if(strcmp(c[i].login,login)==0 && strcmp(c[i].password,password)== 0){
            return i;
        }
    }
    return -1;
}

void authentification_compte(compte c[], int taille, compte * joueur){
    int verifier = rechercher_compte(c,taille);
    if(verifier != -1){
        strcpy(joueur->login,c[verifier].login);
        strcpy(joueur->password,c[verifier].password);
        printf("Compte_%d\nLogin : %s\nPassword : %s\n",verifier+1,joueur->login,joueur->password);
        menu_principal(*joueur);
    }
    else {
        printf("Le compte est introuvable !\n");
        menu();
    }


}

void menu_compte(compte c[], int * taille, compte * joueur){

    char choix ;
    do{
        system("cls");
        printf("-------------------------------\n");
        printf("MENU COMPTES\n");
        printf("-------------------------------\n");
        printf("1.Creer un compte\n2.Se connecter\n3.Quitter\n");
        printf("-------------------------------\n");
        printf("Veuillez choisir une option : ");
        scanf(" %c",&choix);
    }while(choix != '1' && choix != '2' && choix != '3');
    switch (choix){
    case '1' :
        system("cls");
        printf("-------------------------------\n");
        printf("CREATION DE COMPTE\n");
        printf("-------------------------------\n");
        creer_compte(c,taille,joueur);
        exporter_compte(c,*taille);
        menu_principal(*joueur);
        break;
    case '2' :
        system("cls");
        printf("-------------------------------\n");
        printf("CONNEXION A COMPTE\n");
        printf("-------------------------------\n");
        authentification_compte(c,*taille,joueur);
        //menu_principal(*joueur);
        break;
    case '3' :
        break;

    }



}

void menu(){
	compte cc [n_c], joueur;
	int taille_compte;
	taille_compte= importer_compte(cc);
	printf("%d\n",taille_compte);
	menu_compte(cc,&taille_compte,&joueur);

}

//----------------------------------FONCTIONS SUR LE JEU------------------------------------



int verifier_lettre(current * c, char lettre, int * cmp, char clavier[], int taille_clavier){
	int i, cc = 0;
	if(lettre >= 97 && lettre <= 122){
		lettre = lettre - 32;
	}
	for(i = 0 ; c->mot[i] != '\0' ; i++){
		if(c->mot[i] == lettre){
			c->c_mot[i] = lettre;
			supprimer_de_clavier(clavier,taille_clavier,lettre);
			cc++;
		}
	}
	if(cc == 0){
		c->tentative++;
	}
	else {
		*cmp = *cmp + cc;
		if (*cmp == strlen(c->mot)){
			return 1;}
	}
	return 0;
}

/*
void jouer_partie(save s[n],int * taille_s,compte joueur, int choix){
    dictionnaire d[t_d];
    current c;
	char clavier[] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int taille_d, taille_clavier = 26, id = 0, cmp = 0, etat;
	int quitter = 0;
    taille_d = importer_niveau(d,choix);
	afficher_dictionnaire(d,taille_d);
	creer_current(&c,d,id);
	afficher_current(c);
	do{
		system("cls");
		char lettre ;
		afficher_partie(c,clavier,taille_clavier,joueur);
		lettre = saisir_lettre();
		if(lettre == '1'){
            system("cls");
            afficher_partie(c,clavier,taille_clavier,joueur);
            printf("INDICE : %s\n",c.indice);
            lettre = saisir_lettre();
		}
		if(lettre == '2'){
            quitter = 1;
            break;
		}
		etat = verifier_lettre(&c,lettre,&cmp,clavier,taille_clavier);
	}while(c.tentative < 6 && etat != 1);
	if(quitter == 1){
        printf("%s vous avez quitte la partie !\n",joueur.login);
        sauvegarder_partie(s,taille_s,joueur,c);
        afficher_statistiques(s,*taille_s,joueur);
        exporter_sauvegarde(s,*taille_s);
	}
	else{
       if(etat == 1 && c.tentative < 6 && quitter == 0){
		system("cls");
		afficher_partie(c,clavier,taille_clavier,joueur);
		printf("Vous avez gagne !\n");
		afficher_current(c);
		sauvegarder_partie(s,taille_s,joueur,c);
		//afficher_sauvegarde_partie(s,*taille_s);
		afficher_statistiques(s,*taille_s,joueur);
		exporter_sauvegarde(s,*taille_s);
		}
	else {
		system("cls");
		afficher_partie(c,clavier,taille_clavier,joueur);
		printf("Vous avez perdu !\n");
	}
	}
	//verifier_lettre(&c,lettre);
} */
void jouer_partie(save s[], int *taille_s, compte joueur, int rep) {
    current c;
    dictionnaire d[t_d];
    int taille_d = importer_niveau(d, rep);
    static int level = 0;
    int game_over = 0;
    char clavier[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int taille_clavier = 26;
    char lettre;
    time_t start_time, end_time;
    joueur.life = 3;
    joueur.score = 0;

    start_time = clock();

    while (!game_over && joueur.life > 0) {
        int id = rand() % taille_d;
        creer_current(&c, d, id);

        c.tentative = 0;  // Reset tentative at the beginning of each round

        while (!game_over && c.tentative < 6) {
            afficher_partie(c, clavier, taille_clavier, joueur);

            lettre = saisir_lettre();
            supprimer_de_clavier(clavier, taille_clavier, lettre);

            int found = 0;
            int i;
            for (i = 0; i < strlen(c.mot); i++) {
                if (toupper(c.mot[i]) == toupper(lettre) && c.c_mot[i] == '_') {
                    c.c_mot[i] = c.mot[i];
                    joueur.score += 10;
                    found = 1;
                }
            }

            if (!found) {
                c.tentative++;
            }

         if (strcmp(c.mot, c.c_mot) == 0) {
            end_time = clock();
        joueur.score += (6 - c.tentative) * 5;
        float temp = end_time - start_time;
        level++;
        printf("Bravo! Vous avez trouvé le mot en %.2f secondes, vous passez au niveau %d!\n", temp, level);
    break;
}


        }

        if (c.tentative == 6) {
            joueur.life--;
            printf("Vous avez epuise vos tentatives !\n");

            if (joueur.life == 0) {
                game_over = 1;
                printf("Vous n'avez plus de vies restantes.\n");
                break;
            } else {
                printf("Vies restantes: %d\n", joueur.life);
                printf("Tentatives réinitialisees! Vous restez au niveau %d.\n", level + 1);
            }
        }
    }

    end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);

    if (game_over) {
        printf("Dommage, vous avez perdu! Le mot était : %s\n", c.mot);
        level = 0;  // Reset level if game over
    } else {
        printf("Bravo! Vous avez trouvé le mot : %s\n", c.mot);
    }

    printf("Score: %d points\n", joueur.score);
    printf("Temps écoulé: %.2f secondes\n", time_taken);

    char restart;
    printf("Voulez-vous recommencer la partie? (O/N): ");
    scanf(" %c", &restart);

    if (restart == 'N' || restart == 'n') {
   menu_principal(joueur);
    }
    }





void afficher_stat_jeu(compte joueur, current c) {
    printf("Joueur: %s | Tentatives restantes: %d\n", joueur.login, 6 - c.tentative);
    printf("Score actuel: %d\n", joueur.score);
}
/*
void init_compte(compte c) {

    c.score = 0;
} */
void charger_partie(save s[n], int taille_s,compte joueur){
    int i, j ;
    //current c;
    save sauve [n];
    int ilyapartie = 0 ;
    int taille_sauve = 0;
    for(i = 0 ; i < taille_s ; i++){
        if(strcmp(s[i].c.login,joueur.login)== 0 && strcmp(s[i].c.password,joueur.password)==0){
                for(j = 0 ; s[i].play.c_mot[j] != '\0'; j++){
                    if(s[i].play.c_mot[j] == '_'){
                        strcpy(sauve[taille_sauve].play.c_mot,s[i].play.c_mot);
                        strcpy(sauve[taille_sauve].play.indice,s[i].play.indice);
                        strcpy(sauve[taille_sauve].play.mot,s[i].play.mot);
                        strcpy(sauve[taille_sauve].c.login,s[i].c.login);
                        strcpy(sauve[taille_sauve].c.password,s[i].c.password);
                        sauve[taille_sauve].play.tentative = s[i].play.tentative;
                        taille_sauve ++;
                        ilyapartie++;
                        break;
                    }
                }

        }
    }
    if(ilyapartie != 0){
        afficher_sauvegarde_partie(sauve,taille_sauve);
    }
    else {
        printf("Aucune partie non terminee !\n");
    }

}


//---------------------------FONCTION DE SAUVEGARDE DES PATIES TERMINEES-------------------------
void sauvegarder_partie(save s[n], int * taille, compte joueur, current c){
   strcpy(s[*taille].c.login,joueur.login);
   strcpy(s[*taille].c.password, joueur.password);
      strcpy(s[*taille].c.score,joueur.score);


   strcpy(s[*taille].play.c_mot, c.c_mot);
   strcpy(s[*taille].play.indice,c.indice);
   strcpy(s[*taille].play.mot,c.mot);
   s[*taille].play.tentative = c.tentative;
   printf("Partie sauvegardee avec success sur le compte %s !\n",joueur.login);
   (*taille)++;
}

void exporter_sauvegarde(save s[n], int taille){
    FILE * f = fopen("savet.txt","w");
    int i;
    fprintf(f,"%d\n",taille);
    for (i = 0 ; i < taille ; i++){
        fprintf(f,"%s %s %s %s %s %d\n",s[i].c.login,s[i].c.password,s[i].play.mot,s[i].play.indice,s[i].play.c_mot,s[i].play.tentative,s[i].c.score);
    }
    printf("Partie exportee avec succes !\n");
    fclose(f);
}

int importer_sauvegarde(save s[n]){
    FILE * f = fopen("savet.txt","r");
    int taille;
    if(f == NULL){
        FILE * f = fopen("savet.txt","w");
        taille = 0;
        fprintf(f,"%d\n",taille);
        fclose(f);
        return taille;
    }
    int i ;
    fscanf(f,"%d\n",&taille);
    for ( i = 0 ; i < taille ; i++){
        fscanf(f,"%s %s %s %s %s %d\n",s[i].c.login,s[i].c.password,s[i].play.mot,s[i].play.indice,s[i].play.c_mot,&s[i].play.tentative,s[i].c.score);
    }
    printf("Sauvegarde des parties importees avec succes !\n");
    fclose(f);
    return taille;
}
void afficher_s_actu(save s[n], int taille){
    printf("-------------------------------------------------------------------------------------\n");
    printf("Login : %s |Password : %s |Mot : %s |Indice : %s |Mot_actu : %s |Tentative : %d |sccore %d \n",s[taille].c.login,s[taille].c.password,s[taille].play.mot,s[taille].play.indice,s[taille].play.c_mot,s[taille].play.tentative,s[taille].c.score);
    printf("-------------------------------------------------------------------------------------\n");
}
void afficher_sauvegarde_partie(save s[n], int taille){
    int i ;
    for (i = 0 ; i < taille ; i++){
       afficher_s_actu(s,i);
    }
}
//--------------------------FONCTION DE STATISTIQUES---------------

void afficher_statistiques(save s[n], int taille_s, compte joueur){
    int i ;
    printf("STATISQUES DES PARTIES PRECEDENTES\n");
    for ( i = 0 ; i < taille_s ; i++){
        if(strcmp(joueur.login,s[i].c.login) == 0 && strcmp(joueur.password,s[i].c.password)== 0){
            afficher_s_actu(s,i);
        }
    }

}
/*
void afficher_stat_jeu(compte joueur, current c){
    printf("JOUEUR : %s | TENTATIVE_RESTANTE : %d |\n",joueur.login,6 - c.tentative);
    printf("1.Indice\n2.Quitter partie\n");
} */


//-----------------------------FONCTIONS REMPLIR FICHIERS------------------

void remplir_fichier_niveaux(int choix){
    dictionnaire d[t_d];
    int taille_d;
    char mot [20];
    char indice[20];
    //int taille;
    printf("Veuillez saisir le mot a ajouter : ");
    scanf("%s",mot);
    printf("Veuillez saisir l'indice du mot a ajouter : ");
    scanf("%s",indice);
    taille_d = importer_niveau(d,choix);
    strcpy(d[taille_d].mot,mot);
    strcpy(d[taille_d].indice,indice);
    taille_d++;
    exporter_niveau(d,taille_d,choix);
    }

