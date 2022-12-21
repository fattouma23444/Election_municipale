#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
/*typedef struct dates{
int jour;
int mois; 
int annee;
}Date;*/
typedef struct elections{
int jour;
int mois;
int annee;
char m[20];
char id[20];
char nb_habitant[20];
int nb_conseiller;
char statut[20];
}electionfatma;
int ajouterfatma(char *, electionfatma);
int modifierfatma( char *, char *, electionfatma);
int supprimerfatma(char *, char*);
electionfatma chercherfatma(char *, char *);
//void state(int , char *);
void afficherfatma(GtkWidget *);
int calcul_nb_habitant(long);
#endif //ELECTION_H_INCLUDED
