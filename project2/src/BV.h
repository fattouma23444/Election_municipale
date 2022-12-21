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
 int ajoutermariem (char * fich ,BV bv  );
 int modifiermariem (char * fich ,BV nouvBV , int NumBV);
 int supprimermariem (char * fich,int NumBV );
 BV cherchermariem (char * fich, int NumBV);
 void TPE ( char* fich_user, int *nbreelecv , int *elec);
 int NBE (char *fich_user ,int NumBV );
 void affichermariem (GtkWidget *liste);
 
#endif // BV_H_INCLUDED
