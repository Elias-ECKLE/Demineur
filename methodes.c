#include "define.h"
#include <stdio.h>
#include <stdlib.h>


//METHODES______________________________________________________________________________

//init
void verif_casesAutour(int caseVoisineSelect,int x,int y, int numMine,int *cptMines,int tailleLigne,int tailleColonne, int tailleLigne_min, int tailleColonne_min,int tabGrille[][tailleColonne]){
//BUT:vérifier si une des cases autour de la case sléectionnée présente une mine ou pas
//ENTREE:tableauGrille, position x,y de la case sélectionnée, et type de case voisine choisie
//SORTIE:cpt de mines

    switch(caseVoisineSelect){

        case 0: //à la droite de la case
            if((x+1<tailleLigne)&&(tabGrille[x+1][y]==numMine)){
                    *cptMines=*cptMines+1;
            }
        break;

        case 1://en dessous de la case
            if((y+1<tailleLigne)&&(tabGrille[x][y+1]==numMine)){
                    *cptMines=*cptMines+1;
            }
        break;

        case 2://gauche de la case
            if((x-1>tailleLigne_min)&&(tabGrille[x-1][y]==numMine)){
                *cptMines=*cptMines+1;
            }
        break;

        case 3://au dessus de la case
            if((y-1>tailleColonne_min)&&(tabGrille[x][y-1]==numMine)){
                *cptMines=*cptMines+1;
            }
        break;

        case 4://diagonale droite haut
            if((x+1<tailleLigne)&&(y-1>tailleColonne_min)&&(tabGrille[x+1][y-1]==numMine)){
                *cptMines=*cptMines+1;
            }
        break;

        case 5://diagonale droite bas
            if((x+1<tailleLigne)&&(y+1<tailleColonne)&&(tabGrille[x+1][y+1]==numMine)){
                *cptMines=*cptMines+1;
            }
        break;

        case 6://diagonale gauche bas
            if((x-1>tailleLigne_min)&&(y+1<tailleColonne)&&(tabGrille[x-1][y+1]==numMine)){
                *cptMines=*cptMines+1;
            }
        break;

        case 7://diagonale gauche haut
            if((x-1>tailleLigne_min)&&(y-1>tailleColonne_min)&&(tabGrille[x-1][y-1]==numMine)){
                *cptMines=*cptMines+1;
            }
        break;

    }
}
void initGrille(int tailleLigne,int tailleColonne, int tailleLigne_min, int tailleColonne_min, int nbMines, int numRien, int numMine, int tabGrille_prcd[][tailleColonne]){
//BUT:initialiser la grille : mettre en place les mines(chiffre -2), les chiffres et les cases(chiffres 0) ou il n'y a rien
//ENTREE:le tableau stockant la grille
//SORTIE: le tableau

    int i;
    int j;
    int k; //vars pour les boucles
    int nbLigne_alea=0;
    int nbColonne_alea=0;
    int cptMines_autour=0; //servira a compter le nb de mines autour de soi : les 8 cases



//initialiser dans un premier tps le tableau avec des 0 : cases vides
    for(i=0;i<tailleLigne;i++){
        for(j=0;j<tailleColonne;j++){

            tabGrille_prcd[i][j]=numRien;
        }
    }


//ajouter aléatoirement les mines : -2
    do{
        nbLigne_alea=(rand()%(tailleLigne-tailleLigne_min)) + tailleLigne_min;//nb aléatoire ligne entre 0 et 8
        nbColonne_alea=(rand()%(tailleColonne-tailleColonne_min)) + tailleColonne_min;//nb aléatoire colonne entre 0 et 8

        if(tabGrille_prcd[nbLigne_alea][nbColonne_alea]==numRien){

            tabGrille_prcd[nbLigne_alea][nbColonne_alea]=numMine;
            nbMines--;
        }

    }while(nbMines>0);


//Détecter les 8 cases autour de soi ou il y a des mines et y indiquer le nb

    for(i=0;i<tailleLigne;i++){
        for(j=0;j<tailleColonne;j++){

            if(tabGrille_prcd[i][j]==numRien){ //ds 1er tps il faut que la case en question ne soit pas minée

                for(k=0;k<8;k++){ //il y a 8 cases autour d'une case
                    verif_casesAutour(k,i,j,numMine,&cptMines_autour,tailleLigne,tailleColonne,tailleLigne_min, tailleColonne_min,tabGrille_prcd); //on check une case vosine et si mine on ajoute 1 au cptmines
                }
                tabGrille_prcd[i][j]=cptMines_autour;
                cptMines_autour=0;//on reinit cpt pour la case suivante

            }
        }
    }


}







//Affichage------------------------------------------------------------------------
void AfficherInstructions(int *etatJeu){
//BUT : afficher les différentes instructions du jeu ->message d'accueil, entrer deux coords
//ENTREE: etatDujeu : 0 est le début, 1 choix coords
//SORTIE: rien

    switch(*etatJeu){

        case 0:
             printf("Bienvenue dans le jeu du demineur, arriverez-vous a eviter les mines ?\n\n");
        break;
        case 1:
             printf("Veuillez entrer les coordonnees de la case sur laquelle vous souhaitez aller : (chiffre entre 1 et 9)\ligne puis colonne\n");
        break;
    }
}

void CondFinPartie(int *etatJeu){
//BUT : Afficher les messages victoire ou défaite
//ENTREE:etatDuJeu --> -2 pour la défaite et 2 pour la victoire
//SORTIE:rien

}
void AffichageGrille(int tailleLigne_prcd, int tailleColonne_prcd, int tabGrille_prcd[][tailleColonne_prcd]){
//BUT :Afficher la grille : met à jour graphiquement la grille : cases cachées, nb
//ENTREE: tabGrille
//SORTIE:rien

    int i;
    int j;
    /*
    for(i=0;i<;i++){
        for(j=0;j<;j++){
            switch case(){

        }
    }*/
}




//Saisi joueur---------------------------------------------------------------------
void SaisieCoords(int *x, int *y,int tailleLigne,int tailleColonne, int tailleLigne_min, int tailleColonne_min){
//BUT:Demander à l'utilisateur de saisir les deux coords
//ENTREE:
//SORTIE:Les deux coords

    do{
        printf("Premiere coordoonnee : ");
        scanf("%d",&*x);
        printf("Deuxieme coordoonnee :");
        scanf("%d",&*y);
        if((*x<tailleLigne_min) || (*x>=tailleLigne) || (*y<tailleColonne_min) || (*y>=tailleColonne)){
            printf("Erreur, au moins une des coordoonnee n'est pas valable. Veuillez reessayer\n\n");
        }

    }while((*x<tailleLigne_min) || (*x>=tailleLigne) || (*y<tailleColonne_min) || (*y>=tailleColonne));
}





//Calculs--------------------------------------------------------------------------
void VerifierCaseChoisie(){
}
void ConsequenceCaseChoisie(int *etatJeu,int nbDefaite, int x, int y, int numMine, int tailleColonne, int tabGrille_prcd[][tailleColonne]){
//BUT:indiquer au joueur s'il est tombé sur une mine ou non, et modifier les paramètres en conséquence
//ENTREE:etatJeu, numMine, tabGrille, coords x et y choisi préablement par le joueur
//SORTIE:etatJeu qui soit reste à 1 pour les choix coords, soit passe à -2 car mine, soit 2 pour la victoire


    //VerifierCaseChoisie()


    if(tabGrille_prcd[x][y]==numMine){
        printf("BOOOOOOOOOOM, KABOOOOOOOOOM !!!!!!!!!!! Malheureusement vous etes tombe sur une mine\n");
        *etatJeu=nbDefaite;
    }
  /*  else if(){
        toutes cases trouvées
    }*/
    else{
        printf("Vous avez de la chance, vous n etes pas tombe sur une mine\n");
    }

}
