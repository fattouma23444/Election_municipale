#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "GDU.h"
#include "election.h"
#include "elections1.h"
#include "reclamation.h"
#include "BV.h"



/// DEC LOU 

int chckcrtr;//=1;
int tgbm = 1;
int rdb = 2, check;
char idconnecte[10];
int globalid;
int chckbtnvoteeleci = 0;

///


//////////////////////////////////////////////////////////////////////// PARTIE FATMA


int statut=0;
int choix;



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
electionfatma elect;
electionfatma e;
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

if ( statut == 1 )
	strcpy(elect.statut,"achevee");
else
	strcpy(elect.statut,"encours");
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
x=ajouterfatma("fichelect.txt", elect);
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
gtk_widget_destroy(window);
afficher_fatma=create_afficher_fatma();
set_event_box_background(afficher_fatma,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
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
gtk_widget_destroy(window);
afficher_fatma=create_afficher_fatma();
set_event_box_background(afficher_fatma,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
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
electionfatma elect;
electionfatma e;
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

if ( statut = 1 )
	strcpy(elect.statut,"achevee");
else
	strcpy(elect.statut,"encours");
/*e=chercher("electionn.txt", e.id);
if (strcmp(e.id, elect.id)==0)
gtk_label_set_text(GTK_LABEL(output), "Ajout impossible");
else if(strcmp(e.id, elect.id)!=0)
{*/
e=chercherfatma("fichelect.txt", elect.id);
if (strcmp(elect.id, e.id)==0)
{
x=modifierfatma("fichelect.txt", elect.id, elect);
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
electionfatma elec, e;
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
e=chercherfatma("fichelect.txt", elec.id);

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


/*void
on_Rcours_2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	statut=2;

}*/


void
on_modifiertf_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *Modifier_fatma;
window=lookup_widget(objet_graphique, "afficher_fatma");
gtk_widget_destroy(window);
Modifier_fatma=create_Modifier_fatma();
set_event_box_background(Modifier_fatma,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(Modifier_fatma);
}


void
on_supprimerft_clicked                 (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *supprimer_fatma;
window=lookup_widget(objet_graphique, "afficher_fatma");
gtk_widget_destroy(window);
choix=0;
supprimer_fatma=create_supprimer_fatma();
set_event_box_background(supprimer_fatma,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(supprimer_fatma);

}


void
on_actualisertf_clicked                (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *afficher_fatma , *tree_fatma;
afficher_fatma=lookup_widget(objet_graphique, "afficher_fatma");
tree_fatma=lookup_widget(objet_graphique, "tree_fatma");
afficherfatma(tree_fatma);

}


void
on_ajouterf_clicked                    (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window, *Ajouter_fatma;
window=lookup_widget(objet_graphique, "afficher_fatma");
gtk_widget_destroy(window);
Ajouter_fatma=create_Ajouter_fatma();
set_event_box_background(Ajouter_fatma,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
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

electionfatma e, elec;
entry_id=lookup_widget(objet_graphique, "entry_id_suppf");
strcpy(elec.id, gtk_entry_get_text(GTK_ENTRY(entry_id)));
outputs1=lookup_widget(objet_graphique, "resultat_chersf");
e=chercherfatma("fichelect.txt", elec.id);
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
gtk_widget_destroy(window);
afficher_fatma=create_afficher_fatma();
set_event_box_background(afficher_fatma,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(afficher_fatma);
}


void
on_check_robotf_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{choix=!choix;}
}


void
on_bconf_supf_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{

electionfatma ele;
int xsup;
char ch[20];
GtkWidget *result_supf, *entry; 
entry=lookup_widget(objet_graphique,"entry_id_suppf");
result_supf=lookup_widget(objet_graphique, "result_supf");
strcpy(ele.id,gtk_entry_get_text(GTK_ENTRY(entry)));

if(choix==1)
{
xsup=supprimerfatma("fichelect.txt", ele.id);
gtk_label_set_text(GTK_LABEL(result_supf),"suppression avec succes!");
}
else
 { 
if (choix==0)
gtk_label_set_text(GTK_LABEL(result_supf),"echec de suppression!");
}
}








void
on_retourprincipal_fatma_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GdkColor clrs;
GtkWidget *afficher_fatma = lookup_widget(button,"afficher_fatma");
gtk_widget_destroy(afficher_fatma);
GtkWidget *GDU7 = create_GDU7();
set_event_box_background(GDU7,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
GtkWidget *labelmf = lookup_widget(GDU7,"lblvecid");
gdk_color_parse ("red", &clrs);
gtk_widget_modify_fg (labelmf, GTK_STATE_NORMAL, &clrs);
gtk_label_set_text(GTK_LABEL(labelmf),idconnecte);
gtk_widget_show(GDU7);
}







////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////// PARTIE AHMED

int m=2;
int y=0;
int ob=1;
void
on_comboboxentry10_changed             (GtkComboBox     *combobox,
                                        gpointer         user_data)
{


}


void
on_button_NBajouter_une_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{ GtkWidget *w ,*ajouter_une_reclamation;
w=lookup_widget(objet,"gestion_des_reclamations");
gtk_widget_destroy(w);
ajouter_une_reclamation = create_ajouter_une_reclamation ();
set_event_box_background(ajouter_une_reclamation,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show (ajouter_une_reclamation);




}




void
on_buttonNB_modifier_une_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *w ,*modifier_une_reclamation ;
w=lookup_widget(objet,"gestion_des_reclamations");
gtk_widget_destroy(w);
modifier_une_reclamation = create_modifier_une_reclamation ();
set_event_box_background(modifier_une_reclamation,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show (modifier_une_reclamation);

}


void
on_buttonNB_supprimer_une_reclamation_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *w ,*supprimer_une_reclamation ;
w=lookup_widget(objet,"gestion_des_reclamations");
gtk_widget_destroy(w);
supprimer_une_reclamation = create_supprimer_une_reclamation ();
set_event_box_background(supprimer_une_reclamation,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show (supprimer_une_reclamation);
}


void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_nbtraite_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_nbnontraite_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{m=1;}

}


void
on_nburgente_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))

 {m=1;}
}


void
on_moyenne_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))

 {m=2;}

}


void
on_nbfaible_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))

 {m=3;}

}


void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton15_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
}


void
on_radiobutton16_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
}


void
on_button44_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
}


void
on_radiobutton17_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
}


void
on_radiobutton18_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
}


void
on_radiobutton19_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
}


void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button42_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{


}


void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{ /*GtkTreeIter iter;
gchar *jour ;
gchar *mois;
gchar *annee;
gchar *identifiant ;
gchar *num_liste;
gchar *num_bureau;
gchar *type ;
gchar *description ;
gchar *etat;
Date D;
reclamation r ;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&jour,1,&mois,2,&annee,3,&identifiant,4,&num_liste,5,&num_bureau,6,&type,7,&description,8,&etat,-1);
int k =supprimerahmed("reclamation.txt", identifiant) ;

}*/
}


void
on_checkbutton3_activate               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_rec_nada_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{int i,b,c,p;
GtkWidget *jour;
GtkWidget *mois ;
GtkWidget *annee ;

reclamation r ;
GtkWidget *identifiant,*num_liste,*num_bureau,*type,*description,*etat;


identifiant=lookup_widget(objet,"nbidentifiant_ajouter");
num_liste=lookup_widget(objet,"nbidliste");
num_bureau=lookup_widget(objet,"nbnumbr");
type=lookup_widget(objet,"combobox4050");
description=lookup_widget(objet,"entry_description_ajout");

r.num_liste=atoi(gtk_entry_get_text(GTK_ENTRY(num_liste)));



strcpy(r.identifiant,gtk_entry_get_text(GTK_ENTRY(identifiant)));


p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (num_bureau));
r.num_bureau=p;

strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(description)));

strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

if (m==1)
{strcpy(r.etat,"urgente");

}
if(m==2)
{strcpy(r.etat,"moyen");

}
if (m==3)
{strcpy(r.etat,"faible");

}
jour=lookup_widget(objet, "nbjour");
mois=lookup_widget(objet, "nbmois");
annee=lookup_widget(objet, "nbannee");

i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
b=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
c=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
r.D.jour=i ;
r.D.mois=b ;
r.D.annee=c ;
int g=ajouterahmed("reclamation.txt",r) ;
}



void 
on_retourner_clicked 
                  		        (GtkWidget       *objet,
                                        gpointer         user_data)
{ GtkWidget *w ,*gestion_des_reclamations ;
GtkWidget *treeview4 ;
w=lookup_widget(objet,"ajouter_une_reclamation");
gtk_widget_destroy(w);
gestion_des_reclamations = create_gestion_des_reclamations ();
set_event_box_background(gestion_des_reclamations,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show (gestion_des_reclamations);
treeview4=lookup_widget(gestion_des_reclamations,"treeview2");
afficherahmed(treeview4);
}


void
on_nb_retourner_modifier_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{ GtkWidget *w ,*gestion_des_reclamations ;
GtkWidget *treeview4 ;
w=lookup_widget(objet,"modifier_une_reclamation");
gtk_widget_destroy(w);
gestion_des_reclamations = create_gestion_des_reclamations ();
set_event_box_background(gestion_des_reclamations,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show (gestion_des_reclamations);
treeview4=lookup_widget(gestion_des_reclamations,"treeview2");
afficherahmed(treeview4);

}


void
on_nb_retourner_supprimer_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *w ,*gestion_des_reclamations ;
GtkWidget *treeview4 ;
w=lookup_widget(objet,"supprimer_une_reclamation");
gtk_widget_hide(w);
gestion_des_reclamations = create_gestion_des_reclamations ();
set_event_box_background(gestion_des_reclamations,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show (gestion_des_reclamations) ;
treeview4=lookup_widget(gestion_des_reclamations,"treeview2");
afficherahmed(treeview4);

}



void
on_supprimer_rec1_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *w ;
GtkWidget *output ;
char id[30];
w=lookup_widget(objet,"id_supp");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(w)));
output=lookup_widget(objet,"output_supp");
if(y==1)

{
int z= supprimerahmed("reclamation.txt",id) ;
  if (z==1) 
   { gtk_label_set_text(GTK_LABEL(output),"reclamation supprimer avec succes");} 
  else 
      {gtk_label_set_text(GTK_LABEL(output),"reclamation n'est pas trouve");}

   }
else 
{gtk_label_set_text(GTK_LABEL(output),"confirmer pour supprimer") ; }

}


void
on_checkbutton_supp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(togglebutton))
{y=1;}
}


void
on_chercher_re_69_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *id,*jour,*mois,*annee,*liste_elec,*nb_vote,*type,*desc,*output,*urgente,*moyenne,*faible ;
char ch2[30];
id = lookup_widget(button,"id_6969");
jour= lookup_widget(button,"jour_6969");
mois= lookup_widget(button,"mois_6969");
annee= lookup_widget(button,"annee_6969");
liste_elec = lookup_widget(button,"liste_6969");
nb_vote = lookup_widget(button,"num_bv_6969");
type = lookup_widget(button,"type_6969");
desc = lookup_widget(button,"description_6969");
output = lookup_widget(button,"output_69");
urgente = lookup_widget(button,"urgente_6969");
moyenne=lookup_widget(button,"moyenne_6969");
faible=lookup_widget(button,"faible_6969");



char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(id))) ;


 reclamation k=chercherahmed("reclamation.txt", ch);
if (strcmp(k.identifiant,"-1")==0)
	gtk_label_set_text(GTK_LABEL(output),"id n'est pas trouver");
else {
gtk_label_set_text(GTK_LABEL(output),"id trouvé") ;
sprintf(ch2,"%d",k.num_liste);
gtk_entry_set_text(GTK_ENTRY(liste_elec),ch2);
gtk_entry_set_text(GTK_ENTRY(desc),k.description);

if ( strcmp (k.type,"liste_electorale") == 0 )
	gtk_combo_box_set_active(GTK_COMBO_BOX(type),0);
else if ( strcmp (k.type,"bureau_de_vote") == 0 )
	gtk_combo_box_set_active(GTK_COMBO_BOX(type),1);
else if ( strcmp (k.type,"autres") == 0 )
	gtk_combo_box_set_active(GTK_COMBO_BOX(type),2);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),k.D.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),k.D.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),k.D.annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(nb_vote),k.num_bureau);

if (strcmp(k.etat,"urgente")==0)
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (urgente),TRUE);
}

 if (strcmp(k.etat,"moyenne")==0)
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (moyenne),TRUE);
}
if (strcmp(k.etat,"faible")==0)
{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (faible),TRUE);
}




if (strcmp(k.etat,"faible")==0)
    { gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(faible),TRUE);}


}
}







void
on_urgente_6969_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(togglebutton))
{ob=1;}
}


void
on_moyenne_6969_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if  (gtk_toggle_button_get_active(togglebutton))
{ob=2;}

}


void
on_faible_6969_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{if  (gtk_toggle_button_get_active(togglebutton))
{ob=3;}

}


void
on_modifier_rec001_clicked             (GtkWidget   *objet,
                                        gpointer         user_data)
{int i,b,c,p;
GtkWidget *jour;
GtkWidget *mois ;
GtkWidget *annee ;

reclamation r ;
GtkWidget *identifiant,*num_liste,*num_bureau,*type,*description,*etat;


identifiant=lookup_widget(objet,"id_6969");
num_liste=lookup_widget(objet,"liste_6969");
num_bureau=lookup_widget(objet,"num_bv_6969");
type=lookup_widget(objet,"type_6969");
description=lookup_widget(objet,"description_6969");

r.num_liste=atoi(gtk_entry_get_text(GTK_ENTRY(num_liste)));



strcpy(r.identifiant,gtk_entry_get_text(GTK_ENTRY(identifiant)));


p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (num_bureau));
r.num_bureau=p;

strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(description)));

strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

if (m==1)
{strcpy(r.etat,"urgente");

}
if(m==2)
{strcpy(r.etat,"moyen");

}
if (m==3)
{strcpy(r.etat,"faible");

}
jour=lookup_widget(objet, "jour_6969");
mois=lookup_widget(objet, "mois_6969");
annee=lookup_widget(objet, "annee_6969");

i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
b=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
c=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
r.D.jour=i ;
r.D.mois=b ;
r.D.annee=c ;
int g=modifierahmed("reclamation.txt",r.identifiant,r) ;

}


void
on_button_gestion_rec_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *w ,*gestion_des_reclamations;
GtkWidget *treeview4;
gestion_des_reclamations = create_gestion_des_reclamations ();
gtk_widget_show (gestion_des_reclamations);
treeview4=lookup_widget(gestion_des_reclamations,"treeview2");
afficherahmed(treeview4);
}


void
on_retour_acceuil_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GdkColor clrs;
GtkWidget *gestion_des_reclamations = lookup_widget(objet,"gestion_des_reclamations");
gtk_widget_destroy(gestion_des_reclamations);
GtkWidget *GDU9 = create_GDU9();
set_event_box_background(GDU9,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
GtkWidget *labelm = lookup_widget(GDU9,"lblvec3a");
gdk_color_parse ("red", &clrs);
gtk_widget_modify_fg (labelm, GTK_STATE_NORMAL, &clrs);
gtk_label_set_text(GTK_LABEL(labelm),idconnecte);
gtk_widget_show(GDU9);

}




//////////////////////////////////////////////////////////////////////// FIN AHMED




////////////////////////////////////////////////////////////////////////////// PARTIE MARIEM

int etat=1; //disponible=1 , non_isponible=0
int test=0;
int EtatSalle(int etat )
{ 
  if ( etat == 1)
  return etat;
  else  if (etat== 0)
  return etat;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////// mariem_1
void 

on_button2MM_clicked                   (GtkWidget      *button, gpointer         user_data)
{
 GtkWidget *fenetre_1, *fenetre_2;
 fenetre_1 = lookup_widget(button,"mariem_1");
 gtk_widget_destroy (fenetre_1);
 etat = 0;
 fenetre_2 = create_mariem2();
 set_event_box_background(fenetre_2,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
 gtk_widget_show (fenetre_2);
}
void
on_buttonactualiserMM_clicked          (GtkWidget      *button,
                                        gpointer         user_data)
 { GtkWidget *treeviewMM;
  treeviewMM = lookup_widget (button,"treeview1MM");
  affichermariem (treeviewMM);
 }
void
on_button4supptreeMM_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{ 
 GtkWidget *fenetre1, *fenetre_4;
 fenetre1 = lookup_widget(button,"mariem_1");
 gtk_widget_hide (fenetre1);
 fenetre_4 = create_mariem_4();
set_event_box_background(fenetre_4,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
 gtk_widget_show (fenetre_4);
 
}


void
on_button3modtreeMM_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
 {
 GtkWidget *fenetre1, *fenetre_3;
 fenetre1 = lookup_widget(button,"mariem_1");
 gtk_widget_hide (fenetre1);
 fenetre_3 = create_mariem3();
 set_event_box_background(fenetre_3,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
 gtk_widget_show (fenetre_3);

 }
 
 /*void on_treeview1MM_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{ GtkTreeIter iter;
	guint id;
	GtkWidget *W1;
    
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
        {
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	W1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cette bureau du vote?");
	switch(gtk_dialog_run(GTK_DIALOG(W1)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(W1);
	supprimer("fich.txt",id);
	afficher(treeview);
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(W1);
	break;

        }
}
}*/
void
on_vscrollbar1_adjust_bounds           (GtkRange        *range,
                                        gdouble          value,
                                        gpointer         user_data)
{ 

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// mariem_2
    void on_button6MM_clicked       (GtkWidget      *button ,gpointer user_data)
                                                  
{ GtkWidget *mariem_1;
  GtkWidget *mariem_2;
  
  mariem_1 = create_mariem_1 ();
  set_event_box_background(mariem_1,"/home/lou/Projects/project2/src/Bkgrnd4.jpg");
  gtk_widget_show (mariem_1);
  mariem_2=lookup_widget(button,"mariem2");
  gtk_widget_hide (mariem_2);

 

}


void
on_button5MM_clicked                   (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *input1,*input2,*input3,*input4,*input5,*input6 ,*sortie;
 GtkWidget *radiobutton1 , *radiobutton2;
 BV b;
 GdkColor color; 
 int x;
 char str[50];
 char cp[50];
 input1=lookup_widget(objet_graphique,"entry1MM");
 input2=lookup_widget(objet_graphique,"entry2MM");
 input3=lookup_widget(objet_graphique,"entry3MM");
 input4=lookup_widget(objet_graphique,"combobox4MM");
 input5=lookup_widget(objet_graphique,"spinbutton1MM");
 input6=lookup_widget(objet_graphique,"entrycapobMM");
 sortie =lookup_widget(objet_graphique,"labelmsgMM");
 radiobutton1=lookup_widget(objet_graphique,"radiobutton1MM");
 radiobutton2=lookup_widget(objet_graphique,"radiobutton2MM");
 strcpy(str,gtk_entry_get_text(GTK_ENTRY(input1)));
 b.NumBV=atoi(str);
 strcpy(b.adresse,gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(b.capacite_electeur,gtk_entry_get_text(GTK_ENTRY(input3)));
 strcpy(cp,gtk_entry_get_text (GTK_ENTRY(input6)));
 b.capacite_observateur= atoi(cp);
 strcpy(b.ID_agnet,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
 b.nbr_salle =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
 if ( etat == 1 )
	b.Etat = 1;
 else
	b.Etat = 0;
 x=ajoutermariem ("fich.txt",b );
 if (x==1)
       { gdk_color_parse ("green",&color);
        gtk_widget_modify_fg (sortie,GTK_STATE_NORMAL, &color );
        gtk_label_set_text(GTK_LABEL(sortie),"Ajout avec succés !");
        }
 else
        {gdk_color_parse ("red",&color);
         gtk_widget_modify_fg (sortie,GTK_STATE_NORMAL, &color );
         gtk_label_set_text(GTK_LABEL(sortie)," Echec d'Ajout!");
         }



  
 }
///////////////////////////////////////////////////////////////////////////////////////////////// mariem_3


  







void
on_radiobutton1MM_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
 etat=1;


}


void
on_radiobutton2MM_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
 etat=0;
}


void
on_button9MM_clicked                   (GtkWidget     *objet_graphique ,
                                        gpointer         user_data)
{ GtkWidget *p1,*p2,*p3,*p4,*p5,*p6 ,*p7,*p8,*p9,*p10,*p11 ;
  GtkWidget *sortiecher ;
  GdkColor color;
  BV b;
  //char ch [50];
  
  p1 = lookup_widget(objet_graphique ,"entry4MM");
  sortiecher = lookup_widget (objet_graphique ,"label13msgreche");
  b = cherchermariem("fich.txt",atoi(gtk_entry_get_text(GTK_ENTRY(p1))));
  if (b.NumBV==-1)
    {    gdk_color_parse ("red",&color);
         gtk_widget_modify_fg (sortiecher,GTK_STATE_NORMAL, &color );
         gtk_label_set_text(GTK_LABEL(sortiecher)," Bureau du vote introuvable");
    }
  else
	{
		  gtk_label_set_text(GTK_LABEL(sortiecher),"");
		  p2 = lookup_widget(objet_graphique ,"entry5MM");
		  p3 = lookup_widget(objet_graphique ,"entry6MM");
		  p4 = lookup_widget(objet_graphique ,"combobox4MM");
		  p8 = lookup_widget (objet_graphique ,"radiobutton3MM");
		  p9 = lookup_widget (objet_graphique ,"radiobutton4MM");
		  p10 = lookup_widget (objet_graphique , "spinbutton2MM");
		  p11 = lookup_widget(objet_graphique,"entrycaplo");
		  gtk_entry_set_text(GTK_ENTRY(p2),b.adresse);
		  gtk_entry_set_text(GTK_ENTRY(p3),b.capacite_electeur);
		  char capob[20];
		  sprintf(capob,"%d",b.capacite_observateur);
		  gtk_entry_set_text(GTK_ENTRY(p11),capob);
		  if ( b.Etat == 1 )
		  	gtk_toggle_button_set_active(GTK_RADIO_BUTTON(p8),TRUE);
		  else
			gtk_toggle_button_set_active(GTK_RADIO_BUTTON(p9),TRUE);
		  if ( strcmp ( b.ID_agnet , "1234456AG") == 0 )
				  gtk_combo_box_set_active(GTK_COMBO_BOX(p4),0);
		  else if ( strcmp ( b.ID_agnet , "3458351AG") == 0 )
				  gtk_combo_box_set_active(GTK_COMBO_BOX(p4),1);
		  else if ( strcmp ( b.ID_agnet , "9804326AG") == 0 )
				  gtk_combo_box_set_active(GTK_COMBO_BOX(p4),2);
		  else if ( strcmp ( b.ID_agnet , "2265410AG") == 0 )
				  gtk_combo_box_set_active(GTK_COMBO_BOX(p4),3);
		  gtk_spin_button_set_value(GTK_SPIN_BUTTON(p10),b.nbr_salle);
	}
  
 
  
 
          
}


void
on_button7MM_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *p1,*p2,*p3,*p4,*p5,*p6 ,*p7,*p8,*p9,*p10 ;
  GtkWidget *sortie2 ;
  BV b;
  GdkColor color;
  char ch [50];
  char cpo1[50];
  p1 = lookup_widget(objet_graphique ,"entry4MM");
  p2 = lookup_widget(objet_graphique ,"entry5MM");
  p3 = lookup_widget(objet_graphique ,"entry6MM");
  p4 = lookup_widget(objet_graphique ,"combobox4MM");
  p5 = lookup_widget(objet_graphique ,"entrycaplo");
  p8 = lookup_widget (objet_graphique ,"radiobutton3MM");
  p9 = lookup_widget (objet_graphique ,"radiobutton4MM");
  p10 = lookup_widget (objet_graphique , "spinbutton2MM");
  sortie2 = lookup_widget (objet_graphique ,"label14msgmodf");
  strcpy(ch,gtk_entry_get_text(GTK_ENTRY(p1)));
  b.NumBV = atoi(ch);
  strcpy(b.adresse,gtk_entry_get_text(GTK_ENTRY(p2)));
  strcpy(b.capacite_electeur,gtk_entry_get_text(GTK_ENTRY(p3)));
  strcpy(cpo1,gtk_entry_get_text (GTK_ENTRY(p5)));
  b.capacite_observateur= atoi(cpo1);
  strcpy(b.ID_agnet,gtk_combo_box_get_active_text(GTK_COMBO_BOX(p4)));
  b.nbr_salle =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(p10));
  b.Etat=etat;
  int x=modifiermariem ("fich.txt" ,b,b.NumBV);
  if (x==1)
	{
		gdk_color_parse ("green",&color);
		gtk_widget_modify_fg (sortie2,GTK_STATE_NORMAL, &color );
	 	gtk_label_set_text(GTK_LABEL(sortie2)," Modification avec succés !");
	}
  else
	{
		gdk_color_parse ("red",&color);
		gtk_widget_modify_fg (sortie2,GTK_STATE_NORMAL, &color );
		gtk_label_set_text(GTK_LABEL(sortie2)," Echec modification");
	}
}


void
on_button8MM_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{ GtkWidget *mariem_3;
  GtkWidget *mariem_1;
  mariem_1 = create_mariem_1();
  set_event_box_background(mariem_1,"/home/lou/Projects/project2/src/Bkgrnd4.jpg");
  etat = 1;
  gtk_widget_show (mariem_1);
  mariem_3 = lookup_widget (button,"mariem3");
  gtk_widget_hide (mariem_3);

}


void
on_radiobutton3MM_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
 etat=1;

}
void
 on_radiobutton4MM_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 etat=0;

}

//////////////////////////////////////////////////////////////////////////////////////////////// mariem_4
void
on_button11MM_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{ GtkWidget *mariem_1;
  GtkWidget *mariem_4;
  mariem_1 = create_mariem_1 ();
  set_event_box_background(mariem_1,"/home/lou/Projects/project2/src/Bkgrnd4.jpg");
  gtk_widget_show (mariem_1);
  mariem_4=lookup_widget(button,"mariem_4");
  gtk_widget_hide (mariem_4);

}


void
on_button10MM_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{char ch[20];
 int x;
 BV b;
 GdkColor color;
 GtkWidget *inputsupp , *sortie3 ,*check ;
 inputsupp = lookup_widget(objet ,"entry8MM");
 sortie3 = lookup_widget(objet,"label15msgMM");
 check = lookup_widget(objet ,"checkbutton1");
  if (test = 1)
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check) ,TRUE); 
 
 strcpy(ch,gtk_entry_get_text(GTK_ENTRY(inputsupp )));
 b.NumBV=atoi(ch);
 x=supprimermariem ("fich.txt", b.NumBV );
 if (x==1)
 {      gdk_color_parse ("green",&color);
        gtk_widget_modify_fg (sortie3,GTK_STATE_NORMAL, &color );
    gtk_label_set_text(GTK_LABEL(sortie3),"Suppression Avec Succès !");
 }

 else 
 {     
        gdk_color_parse ("red",&color);
        gtk_widget_modify_fg (sortie3,GTK_STATE_NORMAL, &color );
        gtk_label_set_text (GTK_LABEL(sortie3)," Echec De Suppression !");
 }
 }
 
 void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
   test=1;

}

void
on_rtraffmariem_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GdkColor clrs;
GtkWidget *mariem_1 = lookup_widget(button,"mariem_1");
gtk_widget_destroy(mariem_1);
GtkWidget *GDU7 = create_GDU7();
set_event_box_background(GDU7,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
GtkWidget *labelmkl = lookup_widget(GDU7,"lblvecid");
gdk_color_parse ("red", &clrs);
gtk_widget_modify_fg (labelmkl, GTK_STATE_NORMAL, &clrs);
gtk_label_set_text(GTK_LABEL(labelmkl),idconnecte);
gtk_widget_show(GDU7);
}

//////////////////////////////////////////////////////////////////////////////







////////////////////////////////////////////////////////////////////////////// PARTIE DHIA

int affdhia;

void
on_button_mod_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *mod7, *mod8, *pInfo;
election u;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
mod7=lookup_widget(objet,"mod7");
mod8=lookup_widget(objet,"mod8");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
u.ori=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(mod2))?0:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(mod3))?1:2;
u.idt=atoi(gtk_entry_get_text(GTK_ENTRY(mod5)));
u.id1=atoi(gtk_entry_get_text(GTK_ENTRY(mod6)));
u.id2=atoi(gtk_entry_get_text(GTK_ENTRY(mod7)));
u.id3=atoi(gtk_entry_get_text(GTK_ENTRY(mod8)));
modifierdhia(u,"election.txt");
}







void
on_mod_re_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj;
aj=lookup_widget(objet,"mod");
gtk_widget_destroy(aj);
GtkWidget *af=create_af();
set_event_box_background(af,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
affdhia = 1;
gtk_widget_show(af);
}






void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *mod7, *mod8, *pInfo;
int id;
char idt[10], id1[10], id2[10], id3[10];
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
mod7=lookup_widget(objet,"mod7");
mod8=lookup_widget(objet,"mod8");
id = atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
election p = chercherdhia(id, "election.txt");
if(p.id!=-1){
sprintf(idt,"%d",p.idt);
sprintf(id1,"%d",p.id1);
sprintf(id2,"%d",p.id2);
sprintf(id3,"%d",p.id3);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(mod2),p.ori==0?TRUE:FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(mod3),p.ori==1?TRUE:FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(mod4),p.ori==2?TRUE:FALSE);
gtk_entry_set_text(GTK_ENTRY(mod5),idt);
gtk_entry_set_text(GTK_ENTRY(mod6),id1);
gtk_entry_set_text(GTK_ENTRY(mod7),id2);
gtk_entry_set_text(GTK_ENTRY(mod8),id3);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Liste introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
     }
     
}





void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6, *aj7, *aj8;
election u;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj6=lookup_widget(objet,"aj6");
aj7=lookup_widget(objet,"aj7");
aj8=lookup_widget(objet,"aj8");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(aj1)));
u.ori=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aj2))?0:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(aj3))?1:2;
u.idt=atoi(gtk_entry_get_text(GTK_ENTRY(aj5)));
u.id1=atoi(gtk_entry_get_text(GTK_ENTRY(aj6)));
u.id2=atoi(gtk_entry_get_text(GTK_ENTRY(aj7)));
u.id3=atoi(gtk_entry_get_text(GTK_ENTRY(aj8)));
ajouterdhia(u,"election.txt");
}

void
on_ret_aj_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj;
aj=lookup_widget(objet,"aj");
gtk_widget_destroy(aj);
GtkWidget *af=create_af();
set_event_box_background(af,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
affdhia = 1;
gtk_widget_show(af);
}




void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *af, *mod;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
mod=create_mod();
set_event_box_background(mod,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(mod);
}
void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	guint id;
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cette liste?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimerdhia(id,"election.txt");
	afficherdhia(GTK_WIDGET(treeview),"election.txt",-1);
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}
}
}
void
on_button8_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
}
void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *treeview, *af, *e;
int id;
af=lookup_widget(objet,"af");
e=lookup_widget(af, "entry1");
id = atoi(gtk_entry_get_text(GTK_ENTRY(e)));
gtk_widget_destroy(af);
af = create_af();
set_event_box_background(af,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
treeview=lookup_widget(af,"treeview1");
afficherdhia(treeview, "election.txt", id);
gtk_widget_show(af);
affdhia = 1;
}
void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *af, *aj;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
aj=create_aj();
set_event_box_background(aj,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(aj);
}
void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
if ( affdhia == 1 )
	{
		GtkWidget *treeview, *af;
		af=lookup_widget(objet,"af");
		gtk_widget_destroy(af);
		af = create_af();
		treeview=lookup_widget(af,"treeview1");
		afficherdhia(treeview,"election.txt", -1);
		set_event_box_background(af,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
		gtk_widget_show(af);
		affdhia = 0;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////// END DHIA




typedef struct electiondh
{
int id;
int ori;
int idt;
int id1;
int id2;
int id3;
}electiondhialou;






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

void afficher_personne(GtkWidget *liste, char * filename)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	GDU p;
	store = NULL;
	FILE *f;
	//store = gtk_tree_view_get_model(liste);
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

			store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);
			f = fopen(filename,"r");
			if (f==NULL)
			{
				return;
			}
			else
			{
				f = fopen(filename,"a+");
				while(fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d \n",p.Nom,p.Prenom,&p.jour,&p.mois,&p.annee,&p.Gender,&p.N_CIN,p.Id,p.Pass,p.TypeUtilisateur,&p.vote,&p.NumBV)!=EOF)
				{
					int bd = 2022-p.annee;
					char strg[2] = "";
					strncat(strg,&p.Gender,1);
					gtk_list_store_append(store,&iter);	gtk_list_store_set(store,&iter,NOM,p.Nom,PRENOM,p.Prenom,AGE,bd,GENDER,strg,CIN,p.N_CIN,ID,p.Id,PASS,p.Pass,TYPEUTILISATEUR,p.TypeUtilisateur,VOTE,p.vote,NUMBV,p.NumBV,-1);
				}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
}
		}

}





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
else
		{	
			GDU bb = chercher("GDU.txt",k.N_CIN);
			if ( bb.N_CIN == -1 )
				{
					int m = ajouter("GDU.txt",k);
					gdk_color_parse ("green", &color2);
		  			gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color2);
					gtk_label_set_text(GTK_LABEL(output2),"Utilisateur ajouté avec succès");
				}
			else
				{
					gdk_color_parse ("red", &color2);
  					gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color2);
					gtk_label_set_text(GTK_LABEL(output2),"Utilisateur déja existant");
				}
			
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
GtkWidget *GDU1 , *GDU2,*treev;
GDU2 = lookup_widget(button,"GDU2");
gtk_widget_destroy(GDU2);
GDU1 = create_GDU1();
set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(GDU1);
treev = lookup_widget(GDU1,"trvf1");
afficher_personne(treev,"GDU.txt");
}




void
on_btnrtrsuppr_clicked                 (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *GDU4 ,*GDU1,*treev;
GDU4 = lookup_widget(button,"GDU4");
gtk_widget_destroy(GDU4);
GDU1 = create_GDU1();
set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(GDU1);
treev = lookup_widget(GDU1,"trvf1");
afficher_personne(treev,"GDU.txt");
}



void
on_boutonajouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU2 ,*GDU1,*m,*m2;
GDU1 = lookup_widget(button,"GDU1");
gtk_widget_destroy(GDU1);
GDU2 = create_GDU2();
set_event_box_background(GDU2,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(GDU2);
m = lookup_widget(GDU2,"comboboxtypeuts");
m2 = lookup_widget(GDU2,"comboboxannee");
gtk_combo_box_set_active(GTK_COMBO_BOX(m),0);
gtk_combo_box_set_active(GTK_COMBO_BOX(m2),0);
check = 0;
}



void
on_boutonsuppr_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU4 , *GDU1;
GDU1 = lookup_widget(button,"GDU1");
gtk_widget_destroy(GDU1);
GDU4 = create_GDU4();
set_event_box_background(GDU4,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(GDU4);
}


GtkWidget *tak;
void
on_btncrtr_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *GDU1,*GDU5,*ccbx;
GDU1 = lookup_widget(button,"GDU1");
tak = GDU1;
GDU5 = create_GDU5();
set_event_box_background(GDU5,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
gtk_widget_show(GDU5);
chckcrtr=1;
ccbx = lookup_widget(GDU5,"crtr4entry");
gtk_combo_box_set_active(GTK_COMBO_BOX(ccbx),0);
}


void
on_crtr1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		chckcrtr = 1;
}


void
on_crtr3_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		chckcrtr = 3;
}


void
on_crtr2_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		chckcrtr = 2;
}


void
on_crtr4_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		chckcrtr = 4;
}


void
on_crtr5_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		chckcrtr = 5;
}


void
on_crtr6_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		chckcrtr = 6;
}



int chercher_str(char * filename, char *filename2, int y, char pr[])
{
    GDU s;
    int k=0;
    char t[20];
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen(filename2,"w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
	    if (y==1)
		strcpy(t,s.Nom);
	    else if (y==2)
		strcpy(t,s.Prenom);
	    else if (y==4)
		strcpy(t,s.TypeUtilisateur);
            if(strcmp(t,pr)==0)
{
                fprintf(f2,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,s.jour,s.mois,s.annee,s.Gender,s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,s.vote,s.NumBV);
		k = 1;
}
        }
    }
    fclose(f);
    fclose(f2);
return k;
}




int chercher_int(char * filename, char *filename2, int n, int p)
{
    GDU s;
    int mb=0;
    int t;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen(filename2,"w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
	    if (n==3)
		t=s.N_CIN;
	    else if (n==5)
		t=s.vote;
	    else if (n==6)
		t=s.NumBV;
            if(t==p)
{
                fprintf(f2,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,s.jour,s.mois,s.annee,s.Gender,s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,s.vote,s.NumBV);
		mb = 1;
}
        }
    }
    fclose(f);
    fclose(f2);	
return mb;
}




void
on_confcrtr_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char k[70];
GtkWidget *ipt1,*otpt1,*ipt2,*cbxcrtr,*ipt3,*ipt5,*ipt6,*GDU5,*GDU1,*trv;
GdkColor color;
switch (chckcrtr)
{
	case 1:
		ipt1 = lookup_widget(objet_graphique, "crtr1entry") ;
		otpt1 = lookup_widget(objet_graphique,"labelcrtr");
		int w = chercher_str("GDU.txt","GDU2.txt",1,strcpy(k,gtk_entry_get_text(GTK_ENTRY(ipt1))));
		if (w==0)
			{
  				gdk_color_parse ("red", &color);
  				gtk_widget_modify_fg (otpt1, GTK_STATE_NORMAL, &color);
				gtk_label_set_text(GTK_LABEL(otpt1),strcat(strcpy(k,gtk_entry_get_text(GTK_ENTRY(ipt1)))," : Nom introuvable "));
			}
		else
			{
				GDU5 = lookup_widget(objet_graphique,"GDU5");
				gtk_widget_destroy(GDU5);
				GDU1 = create_GDU1();
				set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
				gtk_widget_show(GDU1);
				gtk_widget_destroy(tak);
				trv = lookup_widget(GDU1,"trvf1");
				afficher_personne(trv,"GDU2.txt");
			}
	break;
	case 2:
		ipt2 = lookup_widget(objet_graphique, "crtr2entry") ;
		otpt1 = lookup_widget(objet_graphique,"labelcrtr");
		int j = chercher_str("GDU.txt","GDU2.txt",2,strcpy(k,gtk_entry_get_text(GTK_ENTRY(ipt2))));
		if (j==0)
			{
  				gdk_color_parse ("red", &color);
  				gtk_widget_modify_fg (otpt1, GTK_STATE_NORMAL, &color);
				gtk_label_set_text(GTK_LABEL(otpt1),strcat(strcpy(k,gtk_entry_get_text(GTK_ENTRY(ipt2)))," : Prénom introuvable "));
			}
		else
			{
				GDU5 = lookup_widget(objet_graphique,"GDU5");
				gtk_widget_destroy(GDU5);
				GDU1 = create_GDU1();
				set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
				gtk_widget_show(GDU1);
				gtk_widget_destroy(tak);
				trv = lookup_widget(GDU1,"trvf1");
				afficher_personne(trv,"GDU2.txt");
			}
	break;
	case 3:
		ipt3 = lookup_widget(objet_graphique, "crtr3entry") ;
		otpt1 = lookup_widget(objet_graphique,"labelcrtr");
		int v = chercher_int("GDU.txt","GDU2.txt",3,atoi(gtk_entry_get_text(GTK_ENTRY(ipt3))));
		if (v==0)
			{
				gdk_color_parse ("red", &color);
  				gtk_widget_modify_fg (otpt1, GTK_STATE_NORMAL, &color);
				strcpy(k,gtk_entry_get_text(GTK_ENTRY(ipt3)));
				gtk_label_set_text(GTK_LABEL(otpt1),strcat(k," : CIN introuvable "));
			}
		else
			{
				GDU5 = lookup_widget(objet_graphique,"GDU5");
				gtk_widget_destroy(GDU5);
				GDU1 = create_GDU1();
				set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
				gtk_widget_show(GDU1);
				gtk_widget_destroy(tak);
				trv = lookup_widget(GDU1,"trvf1");
				afficher_personne(trv,"GDU2.txt");
			}
	break;
	case 4:
		cbxcrtr = lookup_widget(objet_graphique,"crtr4entry");
		otpt1 = lookup_widget(objet_graphique,"labelcrtr");
		int z = chercher_str("GDU.txt","GDU2.txt",4,strcpy(k,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbxcrtr))));
		if (z==0)
		{
  			gdk_color_parse ("red", &color);
  			gtk_widget_modify_fg (otpt1, GTK_STATE_NORMAL, &color);
			strcpy(k,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbxcrtr)));
			gtk_label_set_text(GTK_LABEL(otpt1),strcat(k," : Type Utilisateur Introuvable"));
		}
		else
			{
				GDU5 = lookup_widget(objet_graphique,"GDU5");
				gtk_widget_destroy(GDU5);
				GDU1 = create_GDU1();
				set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
				gtk_widget_show(GDU1);
				gtk_widget_destroy(tak);
				trv = lookup_widget(GDU1,"trvf1");
				afficher_personne(trv,"GDU2.txt");
			}
	break;
	case 5:
		ipt5 = lookup_widget(objet_graphique, "crtr5entry") ;
		otpt1 = lookup_widget(objet_graphique,"labelcrtr");
		int u = chercher_int("GDU.txt","GDU2.txt",5,atoi(gtk_entry_get_text(GTK_ENTRY(ipt5))));
		if (u==0)
			{
				gdk_color_parse ("red", &color);
  				gtk_widget_modify_fg (otpt1, GTK_STATE_NORMAL, &color);
				strcpy(k,gtk_entry_get_text(GTK_ENTRY(ipt5)));
				gtk_label_set_text(GTK_LABEL(otpt1),strcat(k," : Vote introuvable "));
			}
		else
			{
				GDU5 = lookup_widget(objet_graphique,"GDU5");
				gtk_widget_destroy(GDU5);
				GDU1 = create_GDU1();
				set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
				gtk_widget_show(GDU1);
				gtk_widget_destroy(tak);
				trv = lookup_widget(GDU1,"trvf1");
				afficher_personne(trv,"GDU2.txt");
			}
	break;
	case 6:
		ipt6 = lookup_widget(objet_graphique, "crtr6entry") ;
		otpt1 = lookup_widget(objet_graphique,"labelcrtr");
		int b = chercher_int("GDU.txt","GDU2.txt",6,atoi(gtk_entry_get_text(GTK_ENTRY(ipt6))));
		if (b==0)
			{
				gdk_color_parse ("red", &color);
  				gtk_widget_modify_fg (otpt1, GTK_STATE_NORMAL, &color);
				strcpy(k,gtk_entry_get_text(GTK_ENTRY(ipt6)));
				gtk_label_set_text(GTK_LABEL(otpt1),strcat(k," : Numéro BV introuvable "));
			}
		else
			{
				GDU5 = lookup_widget(objet_graphique,"GDU5");
				gtk_widget_destroy(GDU5);
				GDU1 = create_GDU1();
				set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
				gtk_widget_show(GDU1);
				gtk_widget_destroy(tak);
				trv = lookup_widget(GDU1,"trvf1");
				afficher_personne(trv,"GDU2.txt");
			}
	break;
	case 7:
				GDU5 = lookup_widget(objet_graphique,"GDU5");
				gtk_widget_destroy(GDU5);
				GDU1 = create_GDU1();
				set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
				gtk_widget_show(GDU1);
				gtk_widget_destroy(tak);
				trv = lookup_widget(GDU1,"trvf1");
				afficher_personne(trv,"GDU.txt");
	break;
}
}


void
on_annulercrtr_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GDU5;
GDU5 = lookup_widget(objet_graphique,"GDU5");
gtk_widget_destroy(GDU5);
}


void
on_crtr7_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		chckcrtr = 7;
}


void
on_boutonrecherchermodif_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *en1,*opt1,*en2,*en3,*en4,*en5,*en6,*en7,*en8,*en9,*en10,*en11,*en12,*en13;
GdkColor color2;
char cin[20],strng[20];
int cbxoption;
GDU g;
en1 = lookup_widget(button,"txtentrycinmodif");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(en1)));
opt1 = lookup_widget(button,"labelrech");
g = chercher("GDU.txt",atoi(cin));
if (g.N_CIN == -1 )
	{
			gdk_color_parse ("red", &color2);
  			gtk_widget_modify_fg (opt1, GTK_STATE_NORMAL, &color2);
			gtk_label_set_text(GTK_LABEL(opt1),"Utilisateur Introuvable");
	}
else
		{

			gdk_color_parse ("green", &color2);
			gtk_widget_modify_fg (opt1, GTK_STATE_NORMAL, &color2);
			gtk_label_set_text(GTK_LABEL(opt1),"Utilisateur Trouvé");
			en2 = lookup_widget(button,"txtentrynommodif");
			en3 = lookup_widget(button,"txtentryprenommodif");
			en4 = lookup_widget(button,"txtentryidmodif");
			en5 = lookup_widget(button,"txtentrypassmodif");
			en6 = lookup_widget(button,"votemodif");
			en7 = lookup_widget(button,"txtentrybvmodif");
			gtk_entry_set_text(GTK_ENTRY(en2),g.Nom);
			gtk_entry_set_text(GTK_ENTRY(en3),g.Prenom);
			gtk_entry_set_text(GTK_ENTRY(en4),g.Id);
			gtk_entry_set_text(GTK_ENTRY(en5),g.Pass);
			sprintf(strng,"%d",g.vote);
			gtk_entry_set_text(GTK_ENTRY(en6),strng);
			sprintf(strng,"%d",g.NumBV);
			gtk_entry_set_text(GTK_ENTRY(en7),strng);
			en8 = lookup_widget(button,"radiobuttonmmodif");
			en9 = lookup_widget(button,"radiobuttonfmodif");
			if (g.Gender == 'M')
				gtk_toggle_button_set_active(GTK_RADIO_BUTTON(en8),TRUE);
			else
				gtk_toggle_button_set_active(GTK_RADIO_BUTTON(en9),TRUE);
			en10 = lookup_widget(button,"spinbuttonjmodif");
			gtk_spin_button_set_value(GTK_SPIN_BUTTON(en10),g.jour);
			en11 = lookup_widget(button,"spinbuttonmmodif");
			gtk_spin_button_set_value(GTK_SPIN_BUTTON(en11),g.mois);
			en12 = lookup_widget(button,"spinbuttonannee");
			gtk_spin_button_set_value(GTK_SPIN_BUTTON(en12),g.annee);
			en13 = lookup_widget(button,"comboboxtpmodif");
			if (strcmp(g.TypeUtilisateur,"Admin")==0)
				cbxoption = 0;
			else if (strcmp(g.TypeUtilisateur,"AgentBV")==0)
				cbxoption = 1;
			else if (strcmp(g.TypeUtilisateur,"Electeur")==0)
				cbxoption = 2;
			else if (strcmp(g.TypeUtilisateur,"Observateur")==0)
				cbxoption = 3;
			gtk_combo_box_set_active(GTK_COMBO_BOX(en13),cbxoption);

		}
}


void
on_boutonrtrmodif_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU3,*GDU1,*trvv;
GDU3 = lookup_widget(button,"GDU3");
gtk_widget_destroy(GDU3);
GDU1 = create_GDU1();
set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(GDU1);
trvv = lookup_widget(GDU1,"trvf1");
afficher_personne(trvv,"GDU.txt");
}


void
on_boutonconfmodif_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *ccin,*inp1,*inp2,*inp3,*inp4,*inp5,*inp6,*inp7,*inp8,*inp9,*inp10,*inp11,*inp12,*otp;
GDU d;
GdkColor color3;


			ccin = lookup_widget(button,"txtentrycinmodif");
			inp1 = lookup_widget(button,"txtentrynommodif");
			inp2 = lookup_widget(button,"txtentryprenommodif");
			inp3 = lookup_widget(button,"txtentryidmodif");
			inp4 = lookup_widget(button,"txtentrypassmodif");
			inp5 = lookup_widget(button,"votemodif");
			inp6 = lookup_widget(button,"txtentrybvmodif");
			inp7 = lookup_widget(button,"radiobuttonmmodif");
			inp8 = lookup_widget(button,"radiobuttonfmodif");
			inp9 = lookup_widget(button,"spinbuttonjmodif");
			inp10 = lookup_widget(button,"spinbuttonmmodif");
			inp11 = lookup_widget(button,"spinbuttonannee");
			inp12 = lookup_widget(button,"comboboxtpmodif");
			otp = lookup_widget(button,"labelrech");
			strcpy(d.Nom,gtk_entry_get_text(GTK_ENTRY(inp1)));
			strcpy(d.Prenom,gtk_entry_get_text(GTK_ENTRY(inp2)));
			strcpy(d.Id,gtk_entry_get_text(GTK_ENTRY(inp3)));
			strcpy(d.Pass,gtk_entry_get_text(GTK_ENTRY(inp4)));
			d.jour = gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON ( inp9 ) );
			d.mois = gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON ( inp10 ) );
			d.annee = gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON ( inp11 ) );
			d.vote = atoi(gtk_entry_get_text(GTK_ENTRY(inp5)));
			d.NumBV = atoi(gtk_entry_get_text(GTK_ENTRY(inp6)));
			strcpy(d.TypeUtilisateur,gtk_combo_box_get_active_text(GTK_COMBO_BOX( inp12 )));
			if ( tgbm == 1 )
				d.Gender = 'M';
			else if ( tgbm == 2 )
				d.Gender = 'F';
			d.N_CIN = atoi(gtk_entry_get_text(GTK_ENTRY(ccin)));
			int p = modifier("GDU.txt",atoi(gtk_entry_get_text(GTK_ENTRY(ccin))),d);
			if ( p == 1 )
				{
					gdk_color_parse ("green", &color3);
  					gtk_widget_modify_fg (otp, GTK_STATE_NORMAL, &color3);
					gtk_label_set_text(GTK_LABEL(otp),"Modification avec succès");
				}
			else
				{
					gdk_color_parse ("red", &color3);
  					gtk_widget_modify_fg (otp, GTK_STATE_NORMAL, &color3);
					gtk_label_set_text(GTK_LABEL(otp),"Echec Modification");
				}
}


void
on_radiobuttonfmodif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)) )
		tgbm = 2;
}


void
on_radiobuttonmmodif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)) )
		tgbm = 1;
}


void
on_boutonmodifier_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU3,*GDU1;
GDU1 = lookup_widget(button,"GDU1");
gtk_widget_destroy(GDU1);
GDU3 = create_GDU3();
set_event_box_background(GDU3,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(GDU3);
}


void
on_boutonretour_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GdkColor clrs;
GtkWidget *GDU1 = lookup_widget(button,"GDU1");
gtk_widget_destroy(GDU1);
GtkWidget *GDU7 = create_GDU7();
set_event_box_background(GDU7,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
GtkWidget *labelmkl = lookup_widget(GDU7,"lblvecid");
gdk_color_parse ("red", &clrs);
gtk_widget_modify_fg (labelmkl, GTK_STATE_NORMAL, &clrs);
gtk_label_set_text(GTK_LABEL(labelmkl),idconnecte);
gtk_widget_show(GDU7);
}




GDU chercher_idpass(char * filename, char str1[] , char str2[])
{
    GDU s;
    int idp=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(idp==0&& fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
            if(strcmp(s.Id,str1) == 0 && strcmp(s.Pass,str2) == 0 )
                idp=1;
        }
    }
    fclose(f);
    if ( idp == 0 )
	strcpy(s.TypeUtilisateur,"nn");
    return s;

}


void
on_btncnxlo_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *string1 = lookup_widget(button,"entryidlo");
GtkWidget *string2 = lookup_widget(button,"entrypasslo");
GtkWidget *string3 = lookup_widget(button,"lblinflo");
GdkColor clrs;
char ch1[20];
char ch2[20];
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(string1)));
strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(string2)));
GDU i = chercher_idpass("GDU.txt",ch1,ch2);
if ( strcmp(i.TypeUtilisateur,"nn") == 0 )
	{
		gdk_color_parse ("red", &clrs);
		gtk_widget_modify_fg (string3, GTK_STATE_NORMAL, &clrs);
		gtk_label_set_text(GTK_LABEL(string3),"Identifiant/Mot de passe Incorrect");
	}
else
	{
	//switch(atoi(i.TypeUtilisateur))
		if (strcmp(i.TypeUtilisateur,"Admin") == 0)
			{	
				GtkWidget *GDU6 = lookup_widget(button,"GDU6");
				gtk_widget_destroy(GDU6);
				GtkWidget *GDU7 = create_GDU7();
				set_event_box_background(GDU7,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
				GtkWidget *labelmkl = lookup_widget(GDU7,"lblvecid");
				gdk_color_parse ("red", &clrs);
				gtk_widget_modify_fg (labelmkl, GTK_STATE_NORMAL, &clrs);
				gtk_label_set_text(GTK_LABEL(labelmkl),i.Id);
				gtk_widget_show(GDU7);
				strcpy(idconnecte,i.Id);
			}
		if (strcmp(i.TypeUtilisateur,"Electeur") == 0)
			{	
				GtkWidget *GDU6 = lookup_widget(button,"GDU6");
				gtk_widget_destroy(GDU6);
				GtkWidget *GDU8 = create_GDU8();
				set_event_box_background(GDU8,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
				GtkWidget *labelmkl = lookup_widget(GDU8,"lblvec2a");
				gdk_color_parse ("red", &clrs);
				gtk_widget_modify_fg (labelmkl, GTK_STATE_NORMAL, &clrs);
				gtk_label_set_text(GTK_LABEL(labelmkl),i.Id);
				gtk_widget_show(GDU8);
				strcpy(idconnecte,i.Id);
				globalid = i.N_CIN;
			}
		if (strcmp(i.TypeUtilisateur,"Observateur") == 0)
			{	
				GtkWidget *GDU6 = lookup_widget(button,"GDU6");
				gtk_widget_destroy(GDU6);
				GtkWidget *GDU9 = create_GDU9();
				set_event_box_background(GDU9,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
				GtkWidget *labelmkl = lookup_widget(GDU9,"lblvec3a");
				gdk_color_parse ("red", &clrs);
				gtk_widget_modify_fg (labelmkl, GTK_STATE_NORMAL, &clrs);
				gtk_label_set_text(GTK_LABEL(labelmkl),i.Id);
				gtk_widget_show(GDU9);
				strcpy(idconnecte,i.Id);
			}
				
	}

}

int mcv = 0;

void
on_montrercacher_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
mcv = !mcv;
GtkWidget *passfld = lookup_widget(button,"entrypasslo");
if ( mcv )
	gtk_entry_set_visibility(GTK_ENTRY(passfld), TRUE);
else
	gtk_entry_set_visibility(GTK_ENTRY(passfld), FALSE);
}




void
on_menuprincipalebtn2_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU7 = lookup_widget(button,"GDU7");
gtk_widget_destroy(GDU7);
GtkWidget *mariem_1 = create_mariem_1();
set_event_box_background(mariem_1,"/home/lou/Projects/project2/src/Bkgrnd4.jpg");
gtk_widget_show(mariem_1);
}


void
on_menuprincipalebtn3_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GdkColor clrs;
GtkWidget *GDU7 = lookup_widget(button,"GDU7");
gtk_widget_destroy(GDU7);
GtkWidget *afficher_fatma = create_afficher_fatma();
set_event_box_background(afficher_fatma,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(afficher_fatma);
}


void
on_menuprincipalebtn1_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU7 = lookup_widget(button,"GDU7");
gtk_widget_destroy(GDU7);
GtkWidget *GDU1 = create_GDU1();
GtkWidget *treeview3 = lookup_widget(GDU1,"trvf1");
afficher_personne(treeview3,"GDU.txt");
set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
gtk_widget_show(GDU1);
}


void
on_menuprincipalebtn4_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_menuprincipaledex_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU7 = lookup_widget(button,"GDU7");
gtk_widget_destroy(GDU7);
GtkWidget *GDU6 = create_GDU6();
set_event_box_background(GDU6,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
mcv = 0;
gtk_widget_show(GDU6);
}


void
on_menuelecteurbtn1_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU8 = lookup_widget(button,"GDU8");
gtk_widget_destroy(GDU8);
GtkWidget *af = create_af ();
set_event_box_background(af,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
affdhia = 1;
gtk_widget_show (af);
}


void
on_menuelecteurdex_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU8 = lookup_widget(button,"GDU8");
gtk_widget_destroy(GDU8);
GtkWidget *GDU6 = create_GDU6();
set_event_box_background(GDU6,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
mcv = 0;
gtk_widget_show(GDU6);
}


void
on_menuobservateurbtn_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU9 = lookup_widget(button,"GDU9");
gtk_widget_destroy(GDU9);
GtkWidget *gestion_des_reclamations = create_gestion_des_reclamations();
set_event_box_background(gestion_des_reclamations,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
GtkWidget *treeview4=lookup_widget(gestion_des_reclamations,"treeview2");
afficherahmed(treeview4);
gtk_widget_show(gestion_des_reclamations);
}


void
on_menuobservateurdex_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDU9 = lookup_widget(button,"GDU9");
gtk_widget_destroy(GDU9);
GtkWidget *GDU6 = create_GDU6();
set_event_box_background(GDU6,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
mcv = 0;
gtk_widget_show(GDU6);
}


void
on_btnrtrelecvote_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GdkColor clrs;
GtkWidget *GDU10 = lookup_widget(button,"GDU10");
gtk_widget_destroy(GDU10);
GtkWidget *GDU8 = create_GDU8();
set_event_box_background(GDU8,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
GtkWidget *labelmk = lookup_widget(GDU8,"lblvec2a");
gdk_color_parse ("red", &clrs);
gtk_widget_modify_fg (labelmk, GTK_STATE_NORMAL, &clrs);
gtk_label_set_text(GTK_LABEL(labelmk),idconnecte);
gtk_widget_show(GDU8);
}


void
on_btnconfirmervoteelec_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cboxvotelou2 = lookup_widget(button,"comboboxvoteeleclo");
GtkWidget *chckbtnsaye = lookup_widget(button,"chkbtnvoteblnc");
GtkWidget *lblsaye = lookup_widget(button,"lblchlistelo");
GDU rs = chercher("GDU.txt",globalid);
GdkColor color;
if ( chckbtnvoteeleci == 0 )
		rs.vote = atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(cboxvotelou2)));
else
		rs.vote = 0;
int modifvotesaye = modifier("GDU.txt",globalid,rs);
if ( modifvotesaye )
			{
				gtk_widget_set_sensitive(cboxvotelou2,FALSE);
				gtk_widget_set_sensitive(chckbtnsaye,FALSE);
				gdk_color_parse ("green", &color);
  				gtk_widget_modify_fg (lblsaye, GTK_STATE_NORMAL, &color);
				gtk_label_set_text(GTK_LABEL(lblsaye),"Vote Ajouté!");
			}
	
}


void
on_chkbtnvoteblnc_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *combovotelodh = lookup_widget(button,"comboboxvoteeleclo");
chckbtnvoteeleci = !chckbtnvoteeleci;
if ( chckbtnvoteeleci == 1 )
	gtk_widget_set_sensitive(combovotelodh,FALSE);
else
	gtk_widget_set_sensitive(combovotelodh,TRUE);
}


void
on_menuelecteurbtn2_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GdkColor color2;
GtkWidget *GDU8 = lookup_widget(button,"GDU8");
GDU dejavoteee = chercher("GDU.txt",globalid);
if ( dejavoteee.vote != -1 )
	{
		GtkWidget *dejavotelbllou = lookup_widget(GDU8,"lbldejavote");
		gdk_color_parse ("red", &color2);
  		gtk_widget_modify_fg (dejavotelbllou, GTK_STATE_NORMAL, &color2);
		gtk_label_set_text(GTK_LABEL(dejavotelbllou),"Vous avez déja voté.");
	}
else
{
	gtk_widget_destroy(GDU8);
	GtkWidget *GDU10 = create_GDU10();
	electiondhialou k;
	char b[10];
	set_event_box_background(GDU10,"/home/lou/Projects/project2/src/Bkgrnd3.jpg");
	GtkWidget *combovotelou = lookup_widget(GDU10,"comboboxvoteeleclo");
	FILE *f = fopen("election.txt","r");
	if ( f != NULL )
	{
		while(fscanf(f,"%d %d %d %d %d %d \n",&k.id,&k.ori,&k.idt,&k.id1,&k.id2,&k.id3) != EOF )
			{
				sprintf(b,"%d",k.id);
				gtk_combo_box_append_text (GTK_COMBO_BOX (combovotelou), _(b));
			}
		fclose(f);
	}
	chckbtnvoteeleci = 0;
	gtk_combo_box_set_active(GTK_COMBO_BOX(combovotelou),0);
	gtk_widget_show (GDU10);
}
}


void
on_btnrtrdhia_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *af, *GDU8;
GdkColor clrs;
af=lookup_widget(button,"af");
gtk_widget_destroy(af);
GDU8=create_GDU8();
set_event_box_background(GDU8,"/home/lou/Projects/project2/src/Bkgrnd2.jpg");
GtkWidget *labelmkdhia = lookup_widget(GDU8,"lblvec2a");
gdk_color_parse ("red", &clrs);
gtk_widget_modify_fg (labelmkdhia, GTK_STATE_NORMAL, &clrs);
gtk_label_set_text(GTK_LABEL(labelmkdhia),idconnecte);
gtk_widget_show(GDU8);
}








void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		m = 2;
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		m = 3;
}








void
on_Rcours_2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
	statut=2;
}

