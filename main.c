#include "define.h"
#define TAILLE_LIGNE 9
#define TAILLE_COLONNE 9
#define NB_MINES 10
#define TAILLE_LIGNE_MIN 0
#define TAILLE_COLONNE_MIN 0

const int nbVictoire_Partie=2;
const int nbDefaite_Partie=-2;
const int nbDebut_Partie=0;
const int nbMilieu_Partie=1; //lors du choix des coords

const int donnneeNum_CaseMine=nbDefaite_Partie;
const int donneeNum_CaseRien=nbDebut_Partie;



typedef struct coords{

    int x;
    int y;

}coords;



int main()
{


//Déclaration et init variables :------------------------------------------

    //init fct aléatoire
    srand(time(0)); //init de la fct rand --> gère le choix aléatoire du chiffre lors du lancer de dé dans

    //Etat du jeu : 0=début du jeu, 1=choix des coods, -2=défaite, 2=victoire
    int etatJeu=0;

    int tabGrille[TAILLE_LIGNE][TAILLE_COLONNE]; //stockage chiffres, mines ect :--> chiffre =nb mines 8 cases autour/-2=bombes/0 pour rien autour
   // char tabGraphiqueGrille[][];//affichage des éléments

    //coords Jeu
    coords caseChoisie;
    caseChoisie.x=0;
    caseChoisie.y=0;

    //init de la grille et début de partie :
    initGrille(TAILLE_LIGNE,TAILLE_COLONNE,TAILLE_LIGNE_MIN, TAILLE_COLONNE_MIN, NB_MINES,donneeNum_CaseRien, donnneeNum_CaseMine, tabGrille);
    AfficherInstructions(&etatJeu);


//Instructions------------------------------------------------------------
   //do{
        etatJeu=1;
        AfficherInstructions(&etatJeu);
        SaisieCoords(&caseChoisie.x,&caseChoisie.y,TAILLE_LIGNE, TAILLE_COLONNE,TAILLE_LIGNE_MIN,TAILLE_COLONNE_MIN);
        ConsequenceCaseChoisie(&etatJeu,nbDefaite_Partie,caseChoisie.x,caseChoisie.y,donnneeNum_CaseMine,TAILLE_COLONNE,tabGrille);



        int i;
        int j;

        for(i=0;i<TAILLE_LIGNE;i++){
        for(j=0;j<TAILLE_COLONNE;j++){
            printf("%d",tabGrille[i][j]);
        }
        printf("\n");
    }


  // }while((etatJeu!=-2) || (etatJeu=2));












    return 0;
}
