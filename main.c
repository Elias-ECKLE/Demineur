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
const char donneeCar_CaseRien='-';



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
    int etatJeu=nbDebut_Partie;

    //TABLEAUX ::::
    int tabGrille[TAILLE_LIGNE][TAILLE_COLONNE]; //stockage chiffres, mines ect :--> chiffre =nb mines 8 cases autour/-2=bombes/0 pour rien autour// char tabGraphiqueGrille[][];//affichage des éléments
    int tabAffichage[TAILLE_LIGNE+1][TAILLE_COLONNE+1]; // on crée un tableau qui affichera les chiffres au fur et à mesure que ça  avance
    //+1 pour mettre les garduations ligne et colonne

    //Cpt des cases non minées restantes à dévoiler avt victoire de la partie
    int cptCases_Restantes=(TAILLE_LIGNE*TAILLE_COLONNE)-NB_MINES; //si 10 mines sur 81 alors, il faut dévoiler 71 cases

    //coords Jeu
    coords caseChoisie;
    caseChoisie.x=0;
    caseChoisie.y=0;

    //init de la grille et début de partie :
    initGrille(TAILLE_LIGNE,TAILLE_COLONNE,TAILLE_LIGNE_MIN, TAILLE_COLONNE_MIN, NB_MINES,donneeNum_CaseRien, donnneeNum_CaseMine, tabGrille);
    InitTabAffichage(TAILLE_LIGNE, TAILLE_COLONNE, donneeNum_CaseRien, tabAffichage);
    AfficherInstructions(etatJeu,nbDebut_Partie,nbMilieu_Partie);




//Instructions------------------------------------------------------------
    etatJeu=nbMilieu_Partie;
    do{
        AffichageGrille(TAILLE_LIGNE,TAILLE_COLONNE,donneeNum_CaseRien,donnneeNum_CaseMine,donneeCar_CaseRien,tabAffichage);
        AfficherInstructions(etatJeu,nbDebut_Partie,nbMilieu_Partie);

        SaisieCoords(&caseChoisie.x,&caseChoisie.y,TAILLE_LIGNE, TAILLE_COLONNE,TAILLE_LIGNE_MIN,TAILLE_COLONNE_MIN);
        ConsequenceCaseChoisie(&etatJeu, nbDefaite_Partie, nbVictoire_Partie, caseChoisie.x, caseChoisie.y, donnneeNum_CaseMine, &cptCases_Restantes, TAILLE_COLONNE, tabGrille, tabAffichage);





        /*
        for(i=0;i<TAILLE_LIGNE;i++){
        for(j=0;j<TAILLE_COLONNE;j++){
            printf("%d",tabGrille[i][j]);
        }
        printf("\n");
    }*/

    }while((etatJeu!=nbDefaite_Partie) || (etatJeu!=nbVictoire_Partie));


    CondFinPartie(etatJeu, nbDefaite_Partie, nbVictoire_Partie);








    return 0;
}
