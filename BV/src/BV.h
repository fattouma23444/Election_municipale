#ifndef BV_H_INCLUDED
#define BV_H_INCLUDED
#include <stdio.h>
typedef struct
{
 int NumBV ;
 char adresse[50];
  char capacite_electeur[50];
  int capacite_observateur;
  int nbr_salle;
  int Etat; //disponible=1 , non_isponible=0
  char ID_agnet[40];



}BV;
 int ajouter (char * fich_BV ,BV bv  );
 int modifier (char * fich_BV ,BV nouvBV , int NumBV);
 int supprimer (char * fich_BV ,int  );
 BV chercher (char * fich_BV, int NumBV);
 float TPE ( char* fich_user);
 int NBE (char *fich_user ,int NumBV );
 
#endif // BV_H_INCLUDED
