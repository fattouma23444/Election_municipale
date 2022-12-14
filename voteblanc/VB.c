#include "GDU.h"
float TVB(char *nom_fichier)
{
GDU u;
FILE *f;
f=fopen(nom_fichier, "r");
int nbr_VB=0;
int nbr_V=0;
float taux;
if (f!=NULL)
{
while(fscanf(f, "%s %s %d %d %d %c %d %s %s %s %d %d", u.Nom, u.Prenom, &u.jour, &u.mois, &u.annee, &u.Gender, &u.N_CIN, u.ID, u.Pass, u.TypeUtilisateur, &u.vote, &u.NumBV)!=EOF)
{
	nbr_V++;
	if (u.vote==0)
	{
		nbr_VB++;
	}
}
fclose(f);
}
taux=(float)(100*nbr_VB)/nbr_V;

return taux; 
}




