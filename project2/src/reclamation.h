#ifndef RECLAMATION_H_INCLUDED
#define RECLAMATION_H_INCLUDED
#include <gtk/gtk.h>

typedef struct Date{
int jour;
int mois;
int annee;
}Date;
typedef struct reclamation{
char identifiant[20];
Date D;
int num_liste ;
int num_bureau;
char type[20];
char description[200];
char etat[30];
}reclamation;

int ajouterahmed (char * Filename ,reclamation r) ;
int modifierahmed ( char* Filename, char id[], reclamation nouv );
int supprimerahmed(char * Filename,char id[]) ;
reclamation chercherahmed (char * Filename,char id[]);
void afficherahmed(GtkWidget *liste) ;

#endif // RECLAMATION_H_INCLUDED
