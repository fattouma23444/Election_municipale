#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "GDU.h"



/*

enum
{
	NOM,
	PRENOM,
	AGE,
	GENDER,
	CIN,
	ID,
	PASS,
	TYPEUTILISATEUR,
	VOTE,
	NUMBV,
	COLUMNS
};

void afficher_personne(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	GDU p;
	store = NULL;
	FILE *f;
	store = gtk_tree_view_get_model(GTK_TREE_MODEL(liste));
	if (store == NULL)
		{
			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Prénom",renderer,"text",PRENOM,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Age",renderer,"text",AGE,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Gender",renderer,"text",GENDER,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",ID,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Mot de Passe",renderer,"text",PASS,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Type Utilisateur",renderer,"text",TYPEUTILISATEUR,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Vote",renderer,"text",VOTE,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes("Num BV",renderer,"text",NUMBV,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

			store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_CHAR,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);
			f = fopen("GDU.txt","r");
			if (f==NULL)
			{
				return;
			}
			else
			{
				f = fopen("GDU.txt","a+");
				while(fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d \n",p.Nom,p.Prenom,&p.jour,&p.mois,&p.annee,&p.Gender,&p.N_CIN,p.Id,p.Pass,p.TypeUtilisateur,&p.vote,&p.NumBV)!=EOF)
				{
					int bd = 2022-p.annee;
					gtk_list_store_append(store,&iter);	gtk_list_store_set(store,&iter,NOM,p.Nom,PRENOM,p.Prenom,AGE,bd,GENDER,p.Gender,CIN,p.N_CIN,ID,p.Id,PASS,p.Pass,TYPEUTILISATEUR,p.TypeUtilisateur,VOTE,p.vote,NUMBV,p.NumBV,-1);
				}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
}
		}

}


*/



int rdb = 2, check = 0;
void on_boutonconfirmeraj_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
GDU k;
GtkWidget* input1 , * input2, *spnbtnj,*spnbtnm,*cboxannee, *input3 , *input4, *input5 ,*cboxtype , * input7;
GtkWidget* output , *output2 ;
GtkWidget *fenetre_afficher , *treeview1;
GdkColor color2;
input1 = lookup_widget(objet_graphique, "txtentrynom") ;
strcpy(k.Nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2 = lookup_widget(objet_graphique, "txtentryprenom") ;
strcpy(k.Prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
spnbtnj = lookup_widget(objet_graphique,"spinbuttonj");
k.jour = gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON ( spnbtnj ) );
spnbtnm = lookup_widget(objet_graphique,"spinbuttonm");
k.mois = gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON ( spnbtnm ) );
cboxannee = lookup_widget(objet_graphique,"comboboxannee");
k.annee = atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX( cboxannee ) ));
if (rdb == 1)
	k.Gender = 'M';
else
	k.Gender = 'F';

input3 = lookup_widget(objet_graphique, "txtentrycin") ;
k.N_CIN = atoi(gtk_entry_get_text(GTK_ENTRY(input3)));
input4 = lookup_widget(objet_graphique, "txtentryid") ;
strcpy(k.Id,gtk_entry_get_text(GTK_ENTRY(input4)));
input5 = lookup_widget(objet_graphique, "txtentrypass") ;
strcpy(k.Pass,gtk_entry_get_text(GTK_ENTRY(input5)));
cboxtype = lookup_widget(objet_graphique,"comboboxtypeuts");
strcpy(k.TypeUtilisateur,gtk_combo_box_get_active_text(GTK_COMBO_BOX( cboxtype ) ) ) ;
output = lookup_widget(objet_graphique, "casevote") ;
k.vote = atoi(gtk_label_get_text(GTK_LABEL(output)));
input7 = lookup_widget(objet_graphique, "txtentrybv") ;
k.NumBV = atoi(gtk_entry_get_text(GTK_ENTRY(input7)));
output2 = lookup_widget(objet_graphique,"checkbtnlabel");
if (check == 0 )
		{
			gdk_color_parse ("red", &color2);
  			gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color2);
			gtk_label_set_text(GTK_LABEL(output2),"Veuillez cocher la case ->");
		}
else if ( check == 1 )
		{	
			gdk_color_parse ("green", &color2);
  			gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color2);
			gtk_label_set_text(GTK_LABEL(output2),"Utilisateur ajouté avec succès");
			int m = ajouter("GDU.txt",k);
		}

}


void on_radiobuttonf_toggled (GtkToggleButton *togglebutton, gpointer user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		rdb = 2;
}

void on_radiobuttonm_toggled (GtkToggleButton *togglebutton, gpointer user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		rdb = 1;
}



void on_checkbtn_toggled (GtkToggleButton *togglebutton, gpointer user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		check = 1;
	else
		check = 0;
}





void on_boutoncfrsuppr_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget* input ;
GtkWidget* output ;
GdkColor color;
char numcin[10];
input = lookup_widget(objet_graphique, "txtentrycinn") ;
output = lookup_widget(objet_graphique, "labelconfsupp") ;
strcpy(numcin,gtk_entry_get_text(GTK_ENTRY(input)));
int x = supprimer("GDU.txt",atoi(numcin));
if (x==1)
	{
  		gdk_color_parse ("green", &color);
  		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
		gtk_label_set_text(GTK_LABEL(output),"l'utilisateur est supprimé");
	}
else
	{
		gdk_color_parse ("red", &color);
  		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
		gtk_label_set_text(GTK_LABEL(output),"Echec suppression");
	}
}


void
on_boutonrtraj_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU1 , *GDU2;
GDU2 = lookup_widget(button,"GDU2");
gtk_widget_destroy(GDU2);
GDU1 = create_GDU1();
gtk_widget_show(GDU1);
}




void
on_btnrtrsuppr_clicked                 (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *GDU4 ,*GDU1;
GDU4 = lookup_widget(button,"GDU4");
gtk_widget_destroy(GDU4);
GDU1 = create_GDU1();
gtk_widget_show(GDU1);
}



void
on_boutonajouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU2 ,*GDU1;
GDU1 = lookup_widget(button,"GDU1");
gtk_widget_destroy(GDU1);
GDU2 = create_GDU2();
gtk_widget_show(GDU2);
}



void
on_boutonsuppr_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU4 , *GDU1;
GDU1 = lookup_widget(button,"GDU1");
gtk_widget_destroy(GDU1);
GDU4 = create_GDU4();
gtk_widget_show(GDU4);
}

