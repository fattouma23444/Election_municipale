#ifndef BV_H_INCLUDED
#define BV_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
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
 int ajouter (char * fich ,BV bv  );
 int modifier (char * fich ,BV nouvBV , int NumBV);
 int supprimer (char * fich,int NumBV );
 BV chercher (char * fich, int NumBV);
 float TPE ( char* fich_user);
 int NBE (char *fich_user ,int NumBV );
 void afficher (GtkWidget *liste);
 
#endif // BV_H_INCLUDED
