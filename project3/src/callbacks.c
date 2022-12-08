#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


int check = 0;

void
on_rdb1_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		check = 15;
}


void
on_rdb2_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		check = 20;
}


void
on_rdb3_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
		check = 30;
}


void
on_btn1_clicked                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *inp1,*inp2,*inp3,*output;
int calc = 0;
char str[30];
char v[30] = "somme : ";
FILE *f = fopen("Test.txt","a+");
if (f != NULL)
{
	inp1 = lookup_widget(button,"entr1");
	inp2 = lookup_widget(button,"entr2");
	output = lookup_widget(button,"lbl4");
	calc = check * gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inp2));
	sprintf(str,"%d",calc);
	strcat(v,str);
	gtk_label_set_text(GTK_LABEL(output),v);
	fprintf(f,"%s Somme : %s \n",gtk_entry_get_text(GTK_ENTRY(inp1)),str);
	fclose(f);
}
}

