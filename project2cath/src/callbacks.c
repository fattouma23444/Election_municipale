#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "GDU.h"




int chckcrtr;//=1;
int tgbm = 1;
int rdb = 2, check;

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
on_boutonretour_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

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
		gtk_label_set_text(GTK_LABEL(string3),"");
	//switch(i.TypeUtilisateur)
	//case "Admin" :
 	//break;
	//case

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



