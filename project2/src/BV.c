#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"BV.h"
#include "GDU.h"
#include <gtk/gtk.h>
// ajouter
              int ajoutermariem (char * fich ,BV b)
{
FILE * f;
f=fopen(fich, "a");
if(f!=NULL)
{
    fprintf(f,"%d %s %s %d %d %d %s\n",b.NumBV,b.adresse,b.capacite_electeur,b.capacite_observateur,b.nbr_salle,b.Etat,b.ID_agnet);
    fclose (f);
    return 1;


}else   return 0;
}
// modifier 
              int  modifiermariem (char* fich  ,  BV nouvBV,int NumBV)
              {
                  int test =0;
                  BV b ;
                  FILE * f=fopen (fich,"r");
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
                  remove(fich);
                  rename("nouvBV.txt",fich);
                  return test;}
//supprimer
 
              int supprimermariem (char* fich,int NumBV )
              {
                  int test=0;
                  BV b;
                  FILE * f=fopen(fich,"r");
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
                      remove (fich);
                      rename ("nouvBV.txt",fich);
                     
                  
return test ;
}
// chercher 
             BV cherchermariem (char* fich , int NumBV )
              {
                  BV b ;
                  int test=0 ;
                  FILE * f=fopen (fich ,"r");
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
    void TPE ( char* fich_user, int *nbreelecv , int *elec)
   { GDU s;
    FILE * ff=fopen(fich_user, "r");
    if(ff!=NULL)
    {
        while(fscanf(ff,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
	    if( (strcmp(s.TypeUtilisateur,"Electeur") == 0) && (s.vote != -1))
		{
			(*nbreelecv)++;
		}
	    if 	(strcmp(s.TypeUtilisateur,"Electeur") == 0)
			(*elec)++;
        }
    }
    fclose(ff);
}
// nombre de electeurs par bureau de vote 
     int NBE (char *fich_user ,int NumBV )
{
  GDU s;
  int nbrelec=0 ;
  
  FILE * ff =fopen(fich_user ,"r");
  if (ff!=NULL)
 { while (fscanf (ff,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
     if ((strcmp(s.TypeUtilisateur,"Electeur") == 0 )&&( s.NumBV == NumBV))
         { 
          nbrelec ++;
          }
  }
 fclose(ff);
 return nbrelec;
}
//treeview
enum 
{ 
 MM1,
 MM2,
 MM3,
 MM4,
 MM5,
 MM6,
 MM7,
 COLUMNS
};
 void affichermariem (GtkWidget *liste)
{
 GtkCellRenderer *renderer ;
 GtkTreeViewColumn *column ;
 GtkTreeIter iterm;
 GtkListStore *store;
 BV b;
 store = NULL ;
 FILE *f;
 if  (store == NULL)
{ 
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Numero de bureau ", renderer ,"text", MM1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Adresse ", renderer ,"text", MM2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Capacite des electeurs", renderer ,"text", MM3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
  renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Capacite des observateurs", renderer ,"text", MM4,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
      
 renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nombre des salles", renderer ,"text", MM5,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Etat des salles", renderer ,"text",MM6,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);    

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID agent de bureau du vote ", renderer ,"text",MM7,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
}

store = gtk_list_store_new (COLUMNS,G_TYPE_INT,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_INT, G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);
f=fopen("fich.txt","r");
if(f==NULL)
{return ;
}
else 
{ f=fopen("fich.txt","a+");
 while (fscanf(f,"%d %s %s %d %d %d %s\n",&b.NumBV,b.adresse,b.capacite_electeur,&b.capacite_observateur,&b.nbr_salle,&b.Etat,b.ID_agnet)!=EOF)
{
/* gtk_store_set ( store , &iterm);*/
 gtk_list_store_append(store,&iterm);
 gtk_list_store_set(store,&iterm ,MM1,b.NumBV,MM2,b.adresse,MM3,b.capacite_electeur,MM4,b.capacite_observateur,MM5,b.nbr_salle,MM6,b.Etat,MM7,b.ID_agnet, -1);
}
 fclose(f);
 gtk_tree_view_set_model (GTK_TREE_VIEW (liste) ,GTK_TREE_MODEL (store));
 g_object_unref(store);
}
}

 

       





















