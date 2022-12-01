#ifndef GDU_H_INCLUDED
#define GDU_H_INCLUDED
#include <stdio.h>
#include <string.h>

typedef struct Utilisateur
{
    char Nom[10];
    char Prenom[10];
    int jour;
    int mois;
    int annee;
    char Gender;
    int N_CIN;
    char Id[10];
    char Pass[20];
    char TypeUtilisateur[15];
    int vote;
    int NumBV;

} GDU;


int ajouter(char *, GDU );
int modifier( char *, int, GDU );
int supprimer(char *, int );
GDU chercher(char *, int);
float agemoyen(char *);
int TPHF( char * filename, int *, int *);
float TPE ( char * filename ) ;

#endif // GDU_H_INCLUDED

