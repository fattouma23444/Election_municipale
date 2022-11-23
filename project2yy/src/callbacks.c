#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "GDU.h"


int rdb = 2, check = 0;
void on_boutonconfirmeraj_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
GDU k;
GtkWidget* input1 , * input2, *spnbtnj,*spnbtnm,*cboxannee, *input3 , *input4, *input5 ,*cboxtype , * input7;
GtkWidget* output , *output2 ;
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
on_boutonrtraj_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}




void
on_btnrtrsuppr_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}



