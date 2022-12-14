#include <gtk/gtk.h>





/////////////////////////////////////////////////////////// DHIA

void
on_button6_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);
void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);
void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button5_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ret_aj_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_button_mod_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data);



void
on_mod_re_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

/////////////////////////////////////////////////// FIN DHIA



void on_boutoncfrsuppr_clicked (GtkWidget *objet_graphique, gpointer user_data);

void on_boutonconfirmeraj_clicked(GtkWidget *objet_graphique, gpointer user_data);

void on_radiobuttonf_toggled (GtkToggleButton *togglebutton, gpointer user_data);

void on_radiobuttonm_toggled (GtkToggleButton *togglebutton, gpointer user_data);

void afficher_personne(GtkWidget *liste, char * filename);

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

void
on_btncrtr_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_crtr1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_crtr3_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_crtr2_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_crtr4_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_crtr5_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_crtr6_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confcrtr_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_annulercrtr_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_crtr7_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_boutonrecherchermodif_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_boutonrtrmodif_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_boutonconfmodif_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobuttonfmodif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonmmodif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_boutonmodifier_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_boutonretour_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_btncnxlo_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_montrercacher_clicked               (GtkWidget       *button,
                                        gpointer         user_data);



void
on_menuprincipalebtn2_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_menuprincipalebtn3_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_menuprincipalebtn1_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_menuprincipalebtn4_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_menuprincipaledex_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_menuelecteurbtn1_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_menuelecteurdex_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_menuobservateurbtn_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_menuobservateurdex_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_btnrtrelecvote_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_btnconfirmervoteelec_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_chkbtnvoteblnc_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_menuelecteurbtn2_clicked            (GtkWidget       *button,
                                        gpointer         user_data);
