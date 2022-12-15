#include "elections1.h"
#include <gtk/gtk.h>

int ajouterfatma(char *filename, electionfatma elect)
{
    FILE * f;
    f=fopen(filename, "a+");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %s %s %s %d %s \n", elect.jour,elect.mois, elect.annee,elect.m,elect.id,elect.nb_habitant, elect.nb_conseiller, elect.statut);
        fclose(f);
      return 1;
    }
    else
      return 0;

	
}
int modifierfatma( char *filename, char id[], electionfatma nouv )
{
    int tr=0;
    electionfatma elect;
    FILE *f=fopen(filename, "r");
    FILE *f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %s %d %s\n", &elect.jour,&elect.mois,&elect.annee,elect.m,elect.id,elect.nb_habitant, &elect.nb_conseiller, elect.statut)!=EOF)
        {
            if(strcmp(elect.id,id)==0)
            {
                fprintf(f2,"%d %d %d %s %s %s %d %s \n",nouv.jour,nouv.mois,nouv.annee, nouv.m, nouv.id, nouv.nb_habitant, nouv.nb_conseiller, nouv.statut);
                tr=1;
            }
            else
               fprintf(f2,"%d %d %d %s %s %s %d %s \n", elect.jour,elect.mois, elect.annee,elect.m,elect.id,elect.nb_habitant, elect.nb_conseiller, elect.statut);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimerfatma(char * filename, char id[])
{
    int tr=0;
    electionfatma elect;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
          while(fscanf(f,"%d %d %d %s %s %s %d %s \n",&elect.jour,&elect.mois, &elect.annee, elect.m ,elect.id , elect.nb_habitant , &elect.nb_conseiller, elect.statut)!=EOF)
        {
            if(strcmp(elect.id,id)==0)
                tr=1;
            else
                fprintf(f2,"%d %d %d %s %s %s %d %s \n",elect.jour,elect.mois, elect.annee,elect.m,elect.id,elect.nb_habitant, elect.nb_conseiller, elect.statut);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
electionfatma chercherfatma(char *filename, char id[])
{
    electionfatma elect;
    int tr=0;
    FILE *f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %s %s %s %d %s \n",&elect.jour,&elect.mois, &elect.annee,elect.m,elect.id,elect.nb_habitant, &elect.nb_conseiller, elect.statut)!=EOF)
        {
            if(strcmp(elect.id,id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(elect.id, "-1");
    return elect;

}
int calcul_nb_habitant(long nb_h)
{
int nb_conseiller;
if (nb_h<=5000)
{
nb_conseiller=10;}
else if((nb_h>=5001)&&(nb_h<=10000))
nb_conseiller=12;
else if ((nb_h>=10001)&&(nb_h<=25000))
nb_conseiller=16;
else if ((nb_h>=25001)&&(nb_h<=50000))
nb_conseiller=22;
else if ((nb_h>=50001)&&(nb_h<=100000))
nb_conseiller=30;
else if ((nb_h>=100001)&&(nb_h<=500000))
nb_conseiller=40;
else if (nb_h>=500001)
nb_conseiller=60;
return nb_conseiller;
}

/////////////////
enum
{
JOUR,
MOIS, 
ANNEE, 
MUNICIPALITE,
IDENTIFIANT,
NOMBRE_HABITANT, 
NOMBRE_CONSEILLER,
ETAT,
COLUMNS
};
void afficherfatma(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
electionfatma e; 
store=NULL;
FILE *f; 
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOIS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", ANNEE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Municipalite", renderer, "text", MUNICIPALITE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID", renderer, "text", IDENTIFIANT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nbre habitants", renderer, "text", NOMBRE_HABITANT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nbre Conseillers", renderer, "text", NOMBRE_CONSEILLER, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Statut", renderer, "text", ETAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}


store= gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);
f=fopen("fichelect.txt", "r");
if (f==NULL)
{
return;
}
else
{f=fopen("fichelect.txt", "a+");
while(fscanf(f,"%d %d %d %s %s %s %d %s\n", &e.jour,&e.mois,&e.annee,e.m,e.id,e.nb_habitant, &e.nb_conseiller, e.statut)!=EOF)
{
gtk_list_store_append (store, &iter);
		gtk_list_store_set (store, &iter, JOUR, e.jour, MOIS, e.mois, ANNEE, e.annee, MUNICIPALITE, e.m, IDENTIFIANT, e.id , NOMBRE_HABITANT, e.nb_habitant ,NOMBRE_CONSEILLER, e.nb_conseiller, ETAT, e.statut,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}



