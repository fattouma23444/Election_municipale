#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"




typedef struct
{
	char cin[15];
	char nom[15];
	char prenom[15];
	char delegation[15];
	int age;
} Personne;



void
on_btnfiltrage_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *i1 , *i2 ,*o1;
Personne k;
int c=0;
char s[20];
i1 = lookup_widget(button,"entryp");
i2 = lookup_widget(button,"spnb");
o1 = lookup_widget(button,"lbl4");
FILE *f = fopen("personnes.txt","r");
if ( f != NULL )
{
	while(fscanf(f,"%s %s %s %s %d \n",k.cin,k.nom,k.prenom,k.delegation,&k.age) != EOF )
		{
			if ( strcmp(k.prenom,gtk_entry_get_text(GTK_ENTRY(i1))) == 0 && gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(i2)) == k.age ) 
				c++;
		}
	fclose(f);
	sprintf(s,"%d",c);
	gtk_label_set_text(GTK_LABEL(o1),s);
}
}


void
on_btnfiltrage2_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w1 , *w2 , *o2;
Personne k;
int cp=0;
char s[20];
w1 = lookup_widget(button,"entryn");
w2 = lookup_widget(button,"combod");
o2 = lookup_widget(button,"lblcp");
FILE *f = fopen("personnes.txt","r");
if ( f != NULL )
{
	while(fscanf(f,"%s %s %s %s %d \n",k.cin,k.nom,k.prenom,k.delegation,&k.age) != EOF )
		{
			if ( strcmp(k.nom,gtk_entry_get_text(GTK_ENTRY(w1))) == 0 && strcmp(k.delegation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(w2))) == 0) 
				cp++;
		}
	fclose(f);
	sprintf(s,"%d",cp);
	gtk_label_set_text(GTK_LABEL(o2),s);
}
}

