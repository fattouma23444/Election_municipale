#include"reclamation.h"
#include<string.h>
#include<stdio.h>
#include <gtk/gtk.h>
enum
{  EID,
   EJOUR,
   EMOIS,
   EANNEE,
   ENUM_LISTE,
   ENUM_BUREAU,
   ETYPE,
   EDESCRIPTION,
   EETAT,
   COLUMNSS
};
int ajouterahmed (char * Filename ,reclamation r)
{
	FILE *f=fopen(Filename,"a+");
	if (f!=NULL)
	{
		fprintf(f,"%s %d %d %d %d %d %s %s %s\n",r.identifiant,r.D.jour,r.D.mois,r.D.annee,r.num_liste,r.num_bureau,r.type,r.description,r.etat);
                fclose(f);
                return 1;
        }
        else return 0 ;
}

int modifierahmed ( char* Filename, char id[], reclamation nouv )
{
    int tr=0;
    reclamation r;
    FILE * f=fopen(Filename,"r");
    FILE * f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %d %d %s %s %s\n",r.identifiant,&r.D.jour,&r.D.mois,&r.D.annee,&r.num_liste,&r.num_bureau,r.type,r.description,r.etat)!=EOF)
        {
            if (strcmp(r.identifiant,id)== 0)
            {
                fprintf(f2,"%s %d %d %d %d %d %s %s %s\n",nouv.identifiant,nouv.D.jour,nouv.D.mois,nouv.D.annee,nouv.num_liste,nouv.num_bureau,nouv.type,nouv.description,nouv.etat);
                    tr=1;
            }
            else
                fprintf(f2,"%s %d %d %d %d %d %s %s %s\n",r.identifiant,r.D.jour,r.D.mois,r.D.annee,r.num_liste,r.num_bureau,r.type,r.description,r.etat);
        }
    }
    fclose(f);
    fclose(f2);
    remove (Filename);
    rename("nouv.txt",Filename);
    return tr;
}

int supprimerahmed(char * Filename,char id[])
{

    int tr=0;
    reclamation r;
    FILE * f=fopen(Filename,"r");
    FILE * f2=fopen("nouv.txt","w");
    if (f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %d %d %s %s %s\n",r.identifiant,&r.D.jour,&r.D.mois,&r.D.annee,&r.num_liste,&r.num_bureau,r.type,r.description,r.etat)!=EOF)
        {
            if (strcmp(r.identifiant,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %d %d %d %d %d %s %s %s\n",r.identifiant,r.D.jour,r.D.mois,r.D.annee,r.num_liste,r.num_bureau,r.type,r.description,r.etat);
        }
    }
    fclose(f);
    fclose(f2);
    remove (Filename);
    rename("nouv.txt",Filename);
    return tr;
}

reclamation chercherahmed (char * Filename,char id[]) //fonction_de_recherche
{
    int tr=0 ;
    reclamation r;
FILE*f=fopen(Filename,"r");
if (f!=NULL)
{
while (tr==0 && fscanf(f,"%s %d %d %d %d %d %s %s %s\n",r.identifiant,&r.D.jour,&r.D.mois,&r.D.annee,&r.num_liste,&r.num_bureau,r.type,r.description,r.etat)!=EOF)
 {
    if(strcmp(r.identifiant,id)==0)
        tr=1;
  }
}
fclose(f);
if (tr==0)
    strcpy(r.identifiant,"-1");
return r ;
}
void afficherahmed(GtkWidget *liste)
{
char identifiant [20];
Date D;
int num_liste ;
int num_bureau;
char type[1000];
char description[200];
char etat[30];

	GtkCellRenderer *renderer;
       GtkTreeViewColumn *column;
       GtkTreeIter iter;	
       GtkListStore *store;
store=NULL;

FILE *f;
//store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
renderer=gtk_cell_renderer_text_new() ;
column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" num liste",renderer, "text",ENUM_LISTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" numbv",renderer, "text",ENUM_BUREAU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" type",renderer, "text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" description",renderer, "text",EDESCRIPTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" etat",renderer, "text",EETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);







}
store=gtk_list_store_new (COLUMNSS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("reclamation.txt","r");
if(f==NULL)
{
	return;
}
else
{
f=fopen("reclamation.txt","a+");
while(fscanf(f,"%s %d %d %d %d %d %s %s %s\n",identifiant,&D.jour,&D.mois,&D.annee,&num_liste,&num_bureau,type,description,etat)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter, EID, identifiant, EJOUR, D.jour, EMOIS, D.mois, EANNEE, D.annee, ENUM_LISTE, num_liste, ENUM_BUREAU, num_bureau, ETYPE,type,EDESCRIPTION,description,EETAT,etat,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}



