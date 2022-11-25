#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"BV.h"
#include "GDU.h"
// ajouter
              int ajouter (char * fich_BV ,BV b)
{
FILE * f;
f=fopen(fich_BV, "a");
if(f!=NULL)
{
    fprintf(f,"%d %s %s %d %d %d %s\n",b.NumBV,b.adresse,b.capacite_electeur,b.capacite_observateur,b.nbr_salle,b.Etat,b.ID_agnet);
    fclose (f);
    return 1;


}else   return 0;
}
// modifier 
              int  modifier (char* fich_BV  ,  BV nouvBV,int NumBV)
              {
                  int test =0;
                  BV b ;
                  FILE * f=fopen (fich_BV,"r");
                  FILE *f2=fopen("nouvBV.txt","w");
                  if ((f!=NULL )&&(f2!=NULL))
                  {
                      while (fscanf(f,"%d %s %s %d %d %d %s\n",&b.NumBV,b.adresse,b.capacite_electeur,&b.capacite_observateur,&b.nbr_salle,&b.Etat,b.ID_agnet)!=EOF)
                      {
                          if(b.NumBV == NumBV)
{fprintf(f2,"%d %s %s %d %d %d %s \n",nouvBV.NumBV,nouvBV.adresse,nouvBV.capacite_electeur,nouvBV.capacite_observateur,nouvBV.nbr_salle,nouvBV.Etat,nouvBV.ID_agnet);


                              test =1;}
                          else
                            fprintf(f2,"%d %s %s %d %d %d %s\n",b.NumBV,b.adresse,b.capacite_electeur,b.capacite_observateur,b.nbr_salle,b.Etat,b.ID_agnet);
                      }
                  }
                  fclose(f);
                  fclose(f2);
                  remove(fich_BV);
                  rename("nouvBV.txt",fich_BV);
                  return test;}
//supprimer
 
              int supprimer (char* fich_BV,int NumBV )
              {
                  int test=0;
                  BV b;
                  FILE * f=fopen(fich_BV ,"r");
                  FILE *f2=fopen ("nouvBV.txt","w");
                  if ((f!=NULL)&&(f2!=NULL))
                  {
                      while(fscanf(f,"%d %s %s %d %d %d %s\n",&b.NumBV,b.adresse,b.capacite_electeur,&b.capacite_observateur,&b.nbr_salle,&b.Etat,b.ID_agnet)!=EOF)
                      {
                          if (b.NumBV==NumBV)
                            
                        
                                test =1;
                            
                            else  fprintf (f2,"%d %s %s %d %d %d %s\n",b.NumBV,b.adresse,b.capacite_electeur,b.capacite_observateur,b.nbr_salle,b.Etat,b.ID_agnet);
}
                      }
                      fclose(f);
                      fclose(f2);
                      remove (fich_BV);
                      rename ("nouvBV.txt",fich_BV);
                     
                  
return test ;
}
// chercher 
             BV chercher (char* fich_BV , int NumBV )
              {
                  BV b ;
                  int test=0 ;
                  FILE * f=fopen (fich_BV ,"r");
                  if(f!=NULL)
                  {while (test==0 && fscanf(f,"%d %s %s %d %d %d %s\n",&b.NumBV,b.adresse,b.capacite_electeur,&b.capacite_observateur,&b.nbr_salle,&b.Etat,b.ID_agnet)!=EOF)

                   {if (b.NumBV ==NumBV)
                       test=1;


                   }
                  }
                  fclose(f);
                  if(test==0)
                     b.NumBV = -1;
                  return b ;
}
// taux de participation des electeurs 
    float TPE ( char* fich_user)
   { GDU s;
      int nbrelecv = 0,elec = 0;
    FILE * ff=fopen(fich_user, "r");
    if(ff!=NULL)
    {
        while(fscanf(ff,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
	    if( (strcmp(s.TypeUtilisateur,"electeur") == 0) && (s.vote != -1))
		{
			nbrelecv++;
		}
	    if 	(strcmp(s.TypeUtilisateur,"electeur") == 0)
			elec++;
        }
    }
    fclose(ff);
    return (float)nbrelecv/elec;
}
// nombre de electeurs par bureau de vote 
     int NBE (char *fich_user ,int NumBV )
{
  GDU s;
  int nbrelec=0 ;
  
  FILE * ff =fopen(fich_user ,"r");
  if (ff!=NULL)
 { while (fscanf (ff,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
     if ((strcmp(s.TypeUtilisateur,"electeur") == 0 )&&( s.NumBV == NumBV))
         { 
          nbrelec ++;
          }
  }
 fclose(ff);
 return nbrelec;
}
        
 























