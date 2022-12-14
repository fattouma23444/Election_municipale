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
char ID[10];
char Pass[20];
char TypeUtilisateur[10];
int vote; 
int NumBV;
}GDU;

#endif
	


