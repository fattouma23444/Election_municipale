#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "elections1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int statut=0;


void
on_Racheve_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	statut=1;

}


void
on_Rcours_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	statut=2;

}


void
on_bajouter_clicked                    (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *spin_jour;
GtkWidget *spin_mois;
GtkWidget *spin_annee;
GtkWidget *entry_id;
GtkWidget *entry_nbr_habitant; 
GtkWidget *combof;
GtkWidget *output;
election elect;
election e;
char j[10]; 
char mm[10];
char an[10];
char msg[50]="";
char idd[30];
char ch[30];
char *p=NULL;
long nb_h;
int x;

entry_id=lookup_widget(objet_graphique, "entry_id");
entry_nbr_habitant=lookup_widget(objet_graphique, "entry_nbr_habitant");
spin_jour=lookup_widget(objet_graphique, "spin_jour");
spin_mois=lookup_widget(objet_graphique, "spin_mois");
spin_annee=lookup_widget(objet_graphique, "spin_annee");
combof=lookup_widget(objet_graphique, "combo_muni");
output=lookup_widget(objet_graphique, "label_aff");


strcpy(ch, gtk_entry_get_text(GTK_ENTRY(entry_id)));
strcpy(elect.id, gtk_entry_get_text(GTK_ENTRY(entry_id)));
strcpy(elect.nb_habitant,gtk_entry_get_text(GTK_ENTRY(entry_nbr_habitant)));
strcpy(elect.m, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combof)));

elect.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_jour));
elect.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mois));
elect.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_annee));

nb_h=strtol(elect.nb_habitant, &p, 16);

if (nb_h<=5000)
{
elect.nb_conseiller=10;}
else if((nb_h>=5001)&&(nb_h<=10000))
elect.nb_conseiller=12;
else if ((nb_h>=10001)&&(nb_h<=25000))
elect.nb_conseiller=16;
else if ((nb_h>=25001)&&(nb_h<=50000))
elect.nb_conseiller=22;
else if ((nb_h>=50001)&&(nb_h<=100000))
elect.nb_conseiller=30;
else if ((nb_h>=100001)&&(nb_h<=500000))
elect.nb_conseiller=40;
else if (nb_h>=500001)
elect.nb_conseiller=60;

state(statut, elect.statut);
/*e=chercher("fichelect.txt", elect.id);
if ((strcmp(elect.id, e.id)==0)!!(strcmp(e.id, "-1")==0))
gtk_label_set_text(GTK_LABEL(output), "Ajout impossible veuillez verifier votre ID");
else
{
x=ajouter("fichelect.txt", elect);
if (x==1)
gtk_label_set_text(GTK_LABEL(output), "Ajout avec succes");
else if (x==0)
gtk_label_set_text(GTK_LABEL(output), "Ajout impossible");
}*/
x=ajouter("fichelect.txt", elect);
if (x==1)
gtk_label_set_text(GTK_LABEL(output), "Ajout avec succes");
else if (x==0)
gtk_label_set_text(GTK_LABEL(output), "Ajout impossible");



}


void
on_retourf_1_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *afficher_fatma;
window=lookup_widget(objet_graphique, "Ajouter_fatma");
gtk_widget_hide(window);
afficher_fatma=create_afficher_fatma();
gtk_widget_show(afficher_fatma);

}


void
on_Rachevee2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	statut=1;

}


void
on_retourf2_clicked                    (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *afficher_fatma;
window=lookup_widget(objet_graphique, "Modifier_fatma");
gtk_widget_hide(window);
afficher_fatma=create_afficher_fatma();
gtk_widget_show(afficher_fatma);


}


void
on_confirmerf_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *spin_jour;
GtkWidget *spin_mois;
GtkWidget *spin_annee;
GtkWidget *entry_id;
GtkWidget *entry_nbr_habitant; 
GtkWidget *combof;
GtkWidget *output;
election elect;
election e;
char j[10]; 
char mm[10];
char an[10];
char msg[50]="";
char idd[30];
char ch[30];
char *p=NULL;
long nb_h;
int x;

entry_id=lookup_widget(objet_graphique, "entry_id2");
entry_nbr_habitant=lookup_widget(objet_graphique, "entry_nb_h2");
spin_jour=lookup_widget(objet_graphique, "spin_jour2");
spin_mois=lookup_widget(objet_graphique, "spin_mois2");
spin_annee=lookup_widget(objet_graphique, "spin_annee2");
combof=lookup_widget(objet_graphique, "combo_muni2");
output=lookup_widget(objet_graphique, "resultatf");

strcpy(elect.id, gtk_entry_get_text(GTK_ENTRY(entry_id)));
strcpy(elect.nb_habitant,gtk_entry_get_text(GTK_ENTRY(entry_nbr_habitant)));
strcpy(elect.m, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combof)));

elect.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_jour));
elect.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mois));
elect.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_annee));

nb_h=strtol(elect.nb_habitant, &p, 16);

if (nb_h<=5000)
{
elect.nb_conseiller=10;}
else if((nb_h>=5001)&&(nb_h<=10000))
elect.nb_conseiller=12;
else if ((nb_h>=10001)&&(nb_h<=25000))
elect.nb_conseiller=16;
else if ((nb_h>=25001)&&(nb_h<=50000))
elect.nb_conseiller=22;
else if ((nb_h>=50001)&&(nb_h<=100000))
elect.nb_conseiller=30;
else if ((nb_h>=100001)&&(nb_h<=500000))
elect.nb_conseiller=40;
else if (nb_h>=500001)
elect.nb_conseiller=60;

state(statut, elect.statut);
/*e=chercher("electionn.txt", e.id);
if (strcmp(e.id, elect.id)==0)
gtk_label_set_text(GTK_LABEL(output), "Ajout impossible");
else if(strcmp(e.id, elect.id)!=0)
{*/
e=chercher("fichelect.txt", elect.id);
if (strcmp(elect.id, e.id)==0)
{
x=modifier("fichelect.txt", elect.id, elect);
gtk_label_set_text(GTK_LABEL(output), "Modification avec succes");
}
else if (x==0)
gtk_label_set_text(GTK_LABEL(output), "Modification impossible");

}


void
on_chercherf_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *spin_jour;
GtkWidget *spin_mois;
GtkWidget *spin_annee;
GtkWidget *entry_id;
GtkWidget *entry_nbr_habitant; 
GtkWidget *combof;
GtkWidget *output;
GtkWidget *togglef1;
GtkWidget *togglef2;
election elec, e;
char j[10]; 
char mm[10];
char an[10];
char msg[50]="";
char idd[30];
long nb_h;
int x1;
int i, jour, mois;
long annee;

entry_id=lookup_widget(objet_graphique, "entry_id2");
entry_nbr_habitant=lookup_widget(objet_graphique, "entry_nb_h2");

spin_jour=lookup_widget(objet_graphique, "spin_jour2");
spin_mois=lookup_widget(objet_graphique, "spin_mois2");
spin_annee=lookup_widget(objet_graphique, "spin_annee2");

combof=lookup_widget(objet_graphique, "combo_muni2");
output=lookup_widget(objet_graphique, "resultatf");
togglef1=lookup_widget(objet_graphique, "Rachevee2");
togglef2=lookup_widget(objet_graphique, "Rcours_2");

strcpy(elec.id, gtk_entry_get_text(GTK_ENTRY(entry_id)));
e=chercher("fichelect.txt", elec.id);

if(strcmp(e.id,"-1")!=0)
{
   gtk_entry_set_text(GTK_ENTRY(entry_nbr_habitant), e.nb_habitant);
        if (strcmp(e.m, "Tunis")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(combof),0);
    else if(strcmp(e.m, "Manzah")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(combof),1);
    else if (strcmp(e.m, "Manar")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(combof),2);
    else if (strcmp(e.m,  "Ariana")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(combof),3);
    else if (strcmp(e.m, "Naceur")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(combof),4);
    else if (strcmp(e.m, "Hammamet")==0)
	gtk_combo_box_set_active(GTK_COMBO_BOX(combof),5);

	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_jour), e.jour);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_mois), e.mois);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_annee), e.annee);

	if(strcmp(e.statut, "achevee")==0)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglef1), TRUE);
	}
	else if (strcmp(e.statut, "encours")==0)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglef2), TRUE);



}
else if (strcmp(e.id,"-1")==0)
gtk_label_set_text(GTK_LABEL(output),"introuvable");


}


void
on_Rcours_2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	statut=2;

}


void
on_modifiertf_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *Modifier_fatma;
window=lookup_widget(objet_graphique, "afficher_fatma");
gtk_widget_hide(window);
Modifier_fatma=create_Modifier_fatma();
gtk_widget_show(Modifier_fatma);
}


void
on_supprimerft_clicked                 (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *supprimer_fatma;
window=lookup_widget(objet_graphique, "afficher_fatma");
gtk_widget_hide(window);
supprimer_fatma=create_supprimer_fatma();
gtk_widget_show(supprimer_fatma);

}


void
on_actualisertf_clicked                (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *afficher_fatma , *tree_fatma;
afficher_fatma=lookup_widget(objet_graphique, "afficher_fatma");
tree_fatma=lookup_widget(objet_graphique, "tree_fatma");
afficher(tree_fatma);

}


void
on_ajouterf_clicked                    (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *Ajouter_fatma;
window=lookup_widget(objet_graphique, "afficher_fatma");
gtk_widget_hide(window);
Ajouter_fatma=create_Ajouter_fatma();
gtk_widget_show(Ajouter_fatma);
}


void
on_chercher_suppf_clicked              (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry_id;
GtkWidget *outputs1=NULL;
GtkWidget *outputs2=NULL;
char idd[30];

election e, elec;
entry_id=lookup_widget(objet_graphique, "entry_id_suppf");
strcpy(elec.id, gtk_entry_get_text(GTK_ENTRY(entry_id)));
outputs1=lookup_widget(objet_graphique, "resultat_chersf");
e=chercher("fichelect.txt", elec.id);
if (strcmp(e.id,elec.id)==0)
gtk_label_set_text(GTK_LABEL(outputs1), "l'election existe");
else if(e.id!=elec.id)
gtk_label_set_text(GTK_LABEL(outputs1), "l'election n'existe pas");


}


void
on_bannuler_supf_clicked               (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *afficher_fatma;
window=lookup_widget(objet_graphique, "supprimer_fatma");
gtk_widget_hide(window);
afficher_fatma=create_afficher_fatma();
gtk_widget_show(afficher_fatma);
}

int choix=0;
void
on_check_robotf_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{choix=1;}
}


void
on_bconf_supf_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{

election ele;
int xsup;
char ch[20];
GtkWidget *result_supf, *entry; 
entry=lookup_widget(objet_graphique,"entry_id_suppf");
result_supf=lookup_widget(objet_graphique, "result_supf");
strcpy(ele.id,gtk_entry_get_text(GTK_ENTRY(entry)));

if(choix==1)
{
xsup=supprimer("fichelect.txt", ele.id);
gtk_label_set_text(GTK_LABEL(result_supf),"suppression avec succes!");
}
else
 { 
if (choix==0)
gtk_label_set_text(GTK_LABEL(result_supf),"echec de suppression!");
}
}








void
on_retourprincipal_fatma_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}

