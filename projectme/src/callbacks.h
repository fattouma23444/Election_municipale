#include <gtk/gtk.h>


void on_boutoncfrsuppr_clicked (GtkWidget *objet_graphique, gpointer user_data);

void on_boutonconfirmeraj_clicked(GtkWidget *objet_graphique, gpointer user_data);

void on_radiobuttonf_toggled (GtkToggleButton *togglebutton, gpointer user_data);

void on_radiobuttonm_toggled (GtkToggleButton *togglebutton, gpointer user_data);

void afficher_personne(GtkWidget *liste);

void
on_boutonrtraj_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_btnrtrsuppr_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void on_checkbtn_toggled (GtkToggleButton *togglebutton, gpointer user_data);


void
on_boutonajouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_boutonsuppr_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);
