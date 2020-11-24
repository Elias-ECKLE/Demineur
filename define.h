#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h> //biblio pr gotoxyd


/*FEATURES
-Messages d'instructions au joueur (début)
-Afficher la grille cachée en début de jeu
-Lancer la partie en lui demandant de choisir deux coordonnées
-Résultat : case mine=mort / case non mine=lui préciser combien de mines sur les 8 cases autour de lui
-MAJ affichage tableau : '-' pour caché, ('x' pour mine,) 'chiffre' pour nb mines autour lui
-reboucle en lui demandant des coordonnées
-Victoire :plus que des cases bombes sont cachées
-Défaite : tomber sur case mine
*/

//PROTOTYPES :

extern void AfficherInstructions(int etatJeu, int nbDebut, int nbMilieu);
extern void SaisieCoords(int *x, int *y,int tailleLigne,int tailleColonne, int tailleLigne_min, int tailleColonne_min);
extern void CondFinPartie(int etatJeu,int,int);
extern void initGrille(int tailleLigne,int tailleColonne, int tailleLigne_min, int tailleColonne_min, int nbMines, int numRien, int numMine, int tabGrille_prcd[][tailleColonne]);
extern void AffichageGrille(int tailleLigne, int tailleColonne,int numRien,int numMine, char carRien, int tabAffichage[][tailleColonne+1]);
extern void verif_casesAutour(int caseVoisineSelect,int x,int y, int numMine,int *cptMines,int tailleLigne,int tailleColonne, int tailleLigne_min, int tailleColonne_min,int tabGrille[][tailleColonne]);
extern void ConsequenceCaseChoisie(int *etatJeu,int nbDefaite, int nbVictoire, int x, int y, int numMine,int *cptCases_Rest, int tailleColonne, int tabGrille_prcd[][tailleColonne], int tabAffichage[][tailleColonne+1]);



#endif // DEFINE_H_INCLUDED
