#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "election.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	ID,
	ORI,
	IDT,
	ID1,
	ID2,
	ID3,
	COLUMNS
};


void ajouterdhia(election u, char *fname){
GtkWidget *pQuestion;
FILE *f;
int b=0;
gpointer user_data;
election p;
f=fopen(fname,"a+");
if(f!=NULL)
{	
	while(fscanf(f,"%d %d %d %d %d %d\n",&(p.id),&(p.ori),&(p.idt),&(p.id1),&(p.id2),&(p.id3))!=EOF)
	{	
		if(u.id==p.id)
		b=1;
	}
	if(b==0){
	fprintf(f,"%d %d %d %d %d %d\n",u.id,u.ori,u.idt,u.id1,u.id2,u.id3);
	}
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,b==0?GTK_MESSAGE_INFO:GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,b==0?"Liste  ajoutée avec succès !":"Liste déja existante !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	fclose(f);
}
}

void modifierdhia(election u, char *fname){
election p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%d %d %d %d %d %d\n",&(p.id),&(p.ori),&(p.idt),&(p.id1),&(p.id2),&(p.id3))!=EOF)
	{
		if(p.id!=u.id)
			fprintf(g,"%d %d %d %d %d %d\n",p.id,p.ori,p.idt,p.id1,p.id2,p.id3);
		else
			fprintf(g,"%d %d %d %d %d %d\n",u.id,u.ori,u.idt,u.id1,u.id2,u.id3);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Liste modifiée avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void afficherdhia(GtkWidget *liste, char *fname, int id)
{
election p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar ori[20];
FILE *f;
p = chercherdhia(id, "election.txt");
//store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Orientation", renderer,"text",ORI, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ID Tete", renderer,"text",IDT, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_resizable(column,TRUE);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ID 1", renderer,"text",ID1, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ID 2", renderer,"text",ID2, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ID 3", renderer,"text",ID3, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);



store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
if (p.id==-1){
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%d %d %d %d %d %d\n",&(p.id),&(p.ori),&(p.idt),&(p.id1),&(p.id2),&(p.id3))!=EOF)
	{
sprintf(ori,p.ori==0?"Droite":p.ori==1?"Gauche":"Centre");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,ORI,ori,IDT,p.idt,ID1,p.id1,ID2,p.id2,ID3,p.id3,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
else{
sprintf(ori,p.ori==0?"Droite":p.ori==1?"Gauche":"Centre");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,ORI,ori,IDT,p.idt,ID1,p.id1,ID2,p.id2,ID3,p.id3,-1);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
gtk_tree_view_set_reorderable(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_search_column(GTK_TREE_VIEW(liste),0);
gtk_tree_view_set_enable_tree_lines(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(liste),GTK_TREE_VIEW_GRID_LINES_BOTH);
}

void supprimerdhia(int id, char *fname)
{
election p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%d %d %d %d %d %d\n",&(p.id),&(p.ori),&(p.idt),&(p.id1),&(p.id2),&(p.id3))!=EOF)
	{
		if(p.id!=id)
			fprintf(g,"%d %d %d %d %d %d\n",p.id,p.ori,p.idt,p.id1,p.id2,p.id3);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Liste supprimée avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

election chercherdhia(int id, char *fname){
FILE *f;
election p, e={id:-1};
f=fopen(fname,"r");
if(f!=NULL)
{
	while(fscanf(f,"%d %d %d %d %d %d\n",&(p.id),&(p.ori),&(p.idt),&(p.id1),&(p.id2),&(p.id3))!=EOF)
	{
	if(p.id==id)
            return p;
	}
	fclose(f);
}
    return e;

}

char* vote_liste(char *fname){
FILE *f;
f=fopen(fname,"r");
int x[100][2] = {};
int b, n = 0, cin, vote;
char* ch = malloc(500);
char tmp[50];
strcpy(ch, "");
while(fscanf(f,"%d %d\n",&cin,&vote)!=EOF)
	{
	if(vote>0){
		b=0;
		for (int i=0;i<100;i++){
			if (x[i][0] == vote){
				x[i][1] = x[i][1] + 1;
				b=1;
				break;
			}
		}
        if(b == 0){
			x[n][0] = vote;
			x[n][1] = 1;
			n++;
		}
	}
	}
	for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (x[i][1] < x[j][1]){
                int s1 = x[j][0];
                int s2 = x[j][1];
                x[j][0] = x[i][0];
                x[j][1] = x[i][1];
                x[i][0] = s1;
                x[i][1] = s2;
            }
	}
	}


	for (int j=0;j<n;j++){
	    sprintf(tmp, "Liste %d : %d votes\n", x[j][0], x[j][1]);
	    strcat(ch, tmp);
}
return ch;
} 
