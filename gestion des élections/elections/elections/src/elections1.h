#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dates{
int jour;
int mois; 
int annee;
}Date;
typedef struct elections{
Date date;
char m[20];
long id;
long nb_habitant;
int nb_conseiller;
int statut;
}election;
int ajouter(char *, election);
int modifier( char *, int , election);
int supprimer(char *, int );
election chercher(char *, int);
#endif //ELECTION_H_INCLUDED
