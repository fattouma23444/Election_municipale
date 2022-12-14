#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "BV.h"

int etat=0; //disponible=1 , non_isponible=0
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
 gtk_widget_hide (fenetre_1);
 fenetre_2 = create_mariem2();
 gtk_widget_show (fenetre_2);
}
void
on_buttonactualiserMM_clicked          (GtkWidget      *button,
                                        gpointer         user_data)
 { GtkWidget *treeviewMM;
  treeviewMM = lookup_widget (button,"treeview1MM");
  afficher (treeviewMM);
 }
void
on_button4supptreeMM_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{ 
 GtkWidget *fenetre1, *fenetre_4;
 fenetre1 = lookup_widget(button,"mariem_1");
 gtk_widget_hide (fenetre1);
 fenetre_4 = create_mariem_4();
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
 b.NumBV=atoi(str);
 b.capacite_observateur= atoi(cp);
 strcpy(str,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(b.adresse,gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(b.capacite_electeur,gtk_entry_get_text(GTK_ENTRY(input3)));
 strcpy(cp,gtk_entry_get_text (GTK_ENTRY(input6)));
 strcpy(b.ID_agnet,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
 b.nbr_salle =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
 b.Etat=EtatSalle(etat);
 x=ajouter ("fich.txt",b );
 if (x==1)
       { gdk_color_parse ("green",&color);
        gtk_widget_modify_fg (sortie,GTK_STATE_NORMAL, &color );
        gtk_label_set_text(GTK_LABEL(sortie),"ajout d'un nouveau bureau du vote avec succés !");
        }
 else if (x==0)
        {gdk_color_parse ("red",&color);
         gtk_widget_modify_fg (sortie,GTK_STATE_NORMAL, &color );
         gtk_label_set_text(GTK_LABEL(sortie)," echec d'ajout!");
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
{ GtkWidget *p1,*p2,*p3,*p4,*p5,*p6 ,*p7,*p8,*p9,*p10 ;
  GtkWidget *sortiecher ;
  GdkColor color;
  BV b;
  char ch [50];
  
  p1 = lookup_widget(objet_graphique ,"entry4MM");
  sortiecher = lookup_widget (objet_graphique ,"label13msgreche");
  b.NumBV=atoi(ch);
  strcpy(ch,gtk_entry_get_text(GTK_ENTRY(p1)));
  b = chercher("fich.txt",b.NumBV);
  if (b.NumBV==-1)
    {    gdk_color_parse ("red",&color);
         gtk_widget_modify_fg (sortiecher,GTK_STATE_NORMAL, &color );
         gtk_label_set_text(GTK_LABEL(sortiecher)," Bureau du vote introuvable ***** verifier votre numero !");
    }
  // selction automatique 
  p2 = lookup_widget(objet_graphique ,"entry5MM");
  p3 = lookup_widget(objet_graphique ,"entry6MM");
  p4 = lookup_widget(objet_graphique ,"combobox4MM");
  p8 = lookup_widget (objet_graphique ,"radiobutton3MM");
  p9 = lookup_widget (objet_graphique ,"radiobutton4MM");
  p10 = lookup_widget (objet_graphique , "spinbutton2MM");
  
 
  
 
          
}


void
on_button7MM_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *p1,*p2,*p3,*p4,*p5,*p6 ,*p7,*p8,*p9,*p10 ;
  GtkWidget *sortie2 ;
  BV b;
  char ch [50];
  char cpo1[50];
  p1 = lookup_widget(objet_graphique ,"entry4MM");
  p2 = lookup_widget(objet_graphique ,"entry5MM");
  p3 = lookup_widget(objet_graphique ,"entry6MM");
  p4 = lookup_widget(objet_graphique ,"combobox4MM");
  p5 = lookup_widget(objet_graphique ,"entry1");
  p8 = lookup_widget (objet_graphique ,"radiobutton3MM");
  p9 = lookup_widget (objet_graphique ,"radiobutton4MM");
  p10 = lookup_widget (objet_graphique , "spinbutton2MM");
  sortie2 = lookup_widget (objet_graphique ,"label14msgmodf");
  b.NumBV=atoi(ch);
  strcpy(ch,gtk_entry_get_text(GTK_ENTRY(p1)));
  strcpy(b.adresse,gtk_entry_get_text(GTK_ENTRY(p2)));
  strcpy(b.capacite_electeur,gtk_entry_get_text(GTK_ENTRY(p3)));
  b.capacite_observateur= atoi(cpo1);
  strcpy(cpo1,gtk_entry_get_text (GTK_ENTRY(p5)));
  strcpy(b.ID_agnet,gtk_combo_box_get_active_text(GTK_COMBO_BOX(p4)));
  b.nbr_salle =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(p10));
  b.Etat=EtatSalle(etat);
  int x=modifier ("fich.txt" ,b,b.NumBV);
  if (x==1)
 
  gtk_label_set_text(GTK_LABEL(sortie2)," modification avec succés !");
}


void
on_button8MM_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{ GtkWidget *mariem_3;
  GtkWidget *mariem_1;
  mariem_1 = create_mariem_1();
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
 
 b.NumBV=atoi(ch);
 strcpy(ch,gtk_entry_get_text(GTK_ENTRY(inputsupp )));
 x=supprimer ("fich.txt", b.NumBV );
 if (x==1)
 {      gdk_color_parse ("green",&color);
        gtk_widget_modify_fg (sortie3,GTK_STATE_NORMAL, &color );
    gtk_label_set_text(GTK_LABEL(sortie3),"suppression avec succes !");
 }

 else 
 {     
        gdk_color_parse ("red",&color);
        gtk_widget_modify_fg (sortie3,GTK_STATE_NORMAL, &color );
        gtk_label_set_text (GTK_LABEL(sortie3)," echec de suppression !");
 }
 }
 
 void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
   test=1;

}
 


















