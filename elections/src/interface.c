/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1_fatma (void)
{
  GtkWidget *window1_fatma;
  GtkWidget *alignment1;
  GtkWidget *fixed1;
  GtkWidget *ajout_fatma;
  GtkWidget *modifier_fatma;
  GtkWidget *supprimer_fatma;
  GtkWidget *scrolledwindow2;
  GtkWidget *treeview_fatma;
  GtkWidget *label_election_fatma;

  window1_fatma = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1_fatma), _("Affichage"));

  alignment1 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (window1_fatma), alignment1);

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (alignment1), fixed1);

  ajout_fatma = gtk_button_new_with_mnemonic (_("ajouter"));
  gtk_widget_show (ajout_fatma);
  gtk_fixed_put (GTK_FIXED (fixed1), ajout_fatma, 88, 416);
  gtk_widget_set_size_request (ajout_fatma, 136, 32);

  modifier_fatma = gtk_button_new_with_mnemonic (_("modifier"));
  gtk_widget_show (modifier_fatma);
  gtk_fixed_put (GTK_FIXED (fixed1), modifier_fatma, 272, 416);
  gtk_widget_set_size_request (modifier_fatma, 136, 32);

  supprimer_fatma = gtk_button_new_with_mnemonic (_("supprimer"));
  gtk_widget_show (supprimer_fatma);
  gtk_fixed_put (GTK_FIXED (fixed1), supprimer_fatma, 456, 416);
  gtk_widget_set_size_request (supprimer_fatma, 136, 32);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow2);
  gtk_fixed_put (GTK_FIXED (fixed1), scrolledwindow2, 128, 136);
  gtk_widget_set_size_request (scrolledwindow2, 444, 224);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  treeview_fatma = gtk_tree_view_new ();
  gtk_widget_show (treeview_fatma);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), treeview_fatma);
  gtk_widget_set_size_request (treeview_fatma, 444, 224);
  gtk_container_set_border_width (GTK_CONTAINER (treeview_fatma), 50);
  gtk_tree_view_set_hover_selection (GTK_TREE_VIEW (treeview_fatma), TRUE);

  label_election_fatma = gtk_label_new (_("Election municipale"));
  gtk_widget_show (label_election_fatma);
  gtk_fixed_put (GTK_FIXED (fixed1), label_election_fatma, 0, 0);
  gtk_widget_set_size_request (label_election_fatma, 0, 0);
  gtk_label_set_justify (GTK_LABEL (label_election_fatma), GTK_JUSTIFY_CENTER);
  gtk_misc_set_alignment (GTK_MISC (label_election_fatma), 0.5, 0.41);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1_fatma, window1_fatma, "window1_fatma");
  GLADE_HOOKUP_OBJECT (window1_fatma, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (window1_fatma, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window1_fatma, ajout_fatma, "ajout_fatma");
  GLADE_HOOKUP_OBJECT (window1_fatma, modifier_fatma, "modifier_fatma");
  GLADE_HOOKUP_OBJECT (window1_fatma, supprimer_fatma, "supprimer_fatma");
  GLADE_HOOKUP_OBJECT (window1_fatma, scrolledwindow2, "scrolledwindow2");
  GLADE_HOOKUP_OBJECT (window1_fatma, treeview_fatma, "treeview_fatma");
  GLADE_HOOKUP_OBJECT (window1_fatma, label_election_fatma, "label_election_fatma");

  return window1_fatma;
}

GtkWidget*
create_modifier_fatma (void)
{
  GtkWidget *modifier_fatma;
  GtkWidget *fixed_2_fatma;
  GtkObject *spin_jour2_fatma_adj;
  GtkWidget *spin_jour2_fatma;
  GtkObject *spin_mois_2_fatma_adj;
  GtkWidget *spin_mois_2_fatma;
  GtkWidget *label1;
  GtkWidget *entry_idm_fatma;
  GtkWidget *entry_municipalite2_fatma;
  GtkWidget *indentifiant_fatma;
  GtkWidget *date2_fatma;
  GtkWidget *jour2_fatma;
  GtkWidget *mois2_fatma;
  GtkObject *spin_annee_2_fatma_adj;
  GtkWidget *spin_annee_2_fatma;
  GtkWidget *annee2_fatma;
  GtkWidget *municipalite2_fatma;
  GtkWidget *nbre_hbt_2_fatma;
  GtkWidget *jsq_5000_2_fatma;
  GSList *jsq_5000_2_fatma_group = NULL;
  GtkWidget *_5001_2_fatma;
  GtkWidget *_10001_2_fatma;
  GtkWidget *_25001_2_fatma;
  GtkWidget *_100001_2_fatma;
  GtkWidget *_50001_2_fatma;
  GtkWidget *chercher_fatma;
  GtkWidget *nbr_conseil_2_fatma;
  GtkWidget *combo_nbr_cons_2_fatma;
  GtkWidget *statut_2_fatma;
  GtkWidget *achevee_2_fatma;
  GtkWidget *cours_2_fatma;
  GtkWidget *confirmer_2_fatma;
  GtkWidget *annuler_2_fatma;
  GtkWidget *plus_500k_2_fatma;

  modifier_fatma = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (modifier_fatma), _("Modifier"));

  fixed_2_fatma = gtk_fixed_new ();
  gtk_widget_show (fixed_2_fatma);
  gtk_container_add (GTK_CONTAINER (modifier_fatma), fixed_2_fatma);

  spin_jour2_fatma_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  spin_jour2_fatma = gtk_spin_button_new (GTK_ADJUSTMENT (spin_jour2_fatma_adj), 1, 0);
  gtk_widget_show (spin_jour2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), spin_jour2_fatma, 232, 256);
  gtk_widget_set_size_request (spin_jour2_fatma, 60, 27);

  spin_mois_2_fatma_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  spin_mois_2_fatma = gtk_spin_button_new (GTK_ADJUSTMENT (spin_mois_2_fatma_adj), 1, 0);
  gtk_widget_show (spin_mois_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), spin_mois_2_fatma, 384, 256);
  gtk_widget_set_size_request (spin_mois_2_fatma, 60, 27);

  label1 = gtk_label_new (_("modifier"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), label1, 224, 48);
  gtk_widget_set_size_request (label1, 152, 48);
  gtk_label_set_justify (GTK_LABEL (label1), GTK_JUSTIFY_CENTER);

  entry_idm_fatma = gtk_entry_new ();
  gtk_widget_show (entry_idm_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), entry_idm_fatma, 192, 160);
  gtk_widget_set_size_request (entry_idm_fatma, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_idm_fatma), 8226);

  entry_municipalite2_fatma = gtk_entry_new ();
  gtk_widget_show (entry_municipalite2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), entry_municipalite2_fatma, 232, 328);
  gtk_widget_set_size_request (entry_municipalite2_fatma, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_municipalite2_fatma), 8226);

  indentifiant_fatma = gtk_label_new (_("Identifiant :"));
  gtk_widget_show (indentifiant_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), indentifiant_fatma, 72, 160);
  gtk_widget_set_size_request (indentifiant_fatma, 80, 24);

  date2_fatma = gtk_label_new (_("Date:"));
  gtk_widget_show (date2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), date2_fatma, 64, 256);
  gtk_widget_set_size_request (date2_fatma, 64, 24);

  jour2_fatma = gtk_label_new (_("jour"));
  gtk_widget_show (jour2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), jour2_fatma, 176, 256);
  gtk_widget_set_size_request (jour2_fatma, 49, 24);

  mois2_fatma = gtk_label_new (_("mois"));
  gtk_widget_show (mois2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), mois2_fatma, 320, 256);
  gtk_widget_set_size_request (mois2_fatma, 49, 24);

  spin_annee_2_fatma_adj = gtk_adjustment_new (1, 1970, 2022, 1, 10, 10);
  spin_annee_2_fatma = gtk_spin_button_new (GTK_ADJUSTMENT (spin_annee_2_fatma_adj), 1, 0);
  gtk_widget_show (spin_annee_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), spin_annee_2_fatma, 520, 256);
  gtk_widget_set_size_request (spin_annee_2_fatma, 60, 27);

  annee2_fatma = gtk_label_new (_("ann\303\251e"));
  gtk_widget_show (annee2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), annee2_fatma, 456, 256);
  gtk_widget_set_size_request (annee2_fatma, 60, 27);

  municipalite2_fatma = gtk_label_new (_("Municipalit\303\251 :"));
  gtk_widget_show (municipalite2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), municipalite2_fatma, 40, 328);
  gtk_widget_set_size_request (municipalite2_fatma, 153, 24);

  nbre_hbt_2_fatma = gtk_label_new (_("Nombre d'habitant :"));
  gtk_widget_show (nbre_hbt_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), nbre_hbt_2_fatma, 64, 384);
  gtk_widget_set_size_request (nbre_hbt_2_fatma, 144, 24);
  gtk_label_set_justify (GTK_LABEL (nbre_hbt_2_fatma), GTK_JUSTIFY_CENTER);

  jsq_5000_2_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("jusqu'\303\240 5000"));
  gtk_widget_show (jsq_5000_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), jsq_5000_2_fatma, 232, 384);
  gtk_widget_set_size_request (jsq_5000_2_fatma, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (jsq_5000_2_fatma), jsq_5000_2_fatma_group);
  jsq_5000_2_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (jsq_5000_2_fatma));

  _5001_2_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("5001-10000"));
  gtk_widget_show (_5001_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), _5001_2_fatma, 232, 432);
  gtk_widget_set_size_request (_5001_2_fatma, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_5001_2_fatma), jsq_5000_2_fatma_group);
  jsq_5000_2_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_5001_2_fatma));

  _10001_2_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("10001-25000"));
  gtk_widget_show (_10001_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), _10001_2_fatma, 232, 480);
  gtk_widget_set_size_request (_10001_2_fatma, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_10001_2_fatma), jsq_5000_2_fatma_group);
  jsq_5000_2_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_10001_2_fatma));

  _25001_2_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("25001-50000"));
  gtk_widget_show (_25001_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), _25001_2_fatma, 232, 528);
  gtk_widget_set_size_request (_25001_2_fatma, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_25001_2_fatma), jsq_5000_2_fatma_group);
  jsq_5000_2_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_25001_2_fatma));

  _100001_2_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("100001-500000"));
  gtk_widget_show (_100001_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), _100001_2_fatma, 424, 440);
  gtk_widget_set_size_request (_100001_2_fatma, 150, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_100001_2_fatma), jsq_5000_2_fatma_group);
  jsq_5000_2_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_100001_2_fatma));

  _50001_2_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("50001-100000"));
  gtk_widget_show (_50001_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), _50001_2_fatma, 424, 384);
  gtk_widget_set_size_request (_50001_2_fatma, 140, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_50001_2_fatma), jsq_5000_2_fatma_group);
  jsq_5000_2_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_50001_2_fatma));

  chercher_fatma = gtk_button_new_with_mnemonic (_("chercher"));
  gtk_widget_show (chercher_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), chercher_fatma, 384, 160);
  gtk_widget_set_size_request (chercher_fatma, 136, 32);

  nbr_conseil_2_fatma = gtk_label_new (_("Nombre de conseillers :"));
  gtk_widget_show (nbr_conseil_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), nbr_conseil_2_fatma, 56, 576);
  gtk_widget_set_size_request (nbr_conseil_2_fatma, 152, 24);
  gtk_label_set_justify (GTK_LABEL (nbr_conseil_2_fatma), GTK_JUSTIFY_CENTER);

  combo_nbr_cons_2_fatma = gtk_combo_box_new_text ();
  gtk_widget_show (combo_nbr_cons_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), combo_nbr_cons_2_fatma, 264, 576);
  gtk_widget_set_size_request (combo_nbr_cons_2_fatma, 33, 31);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_nbr_cons_2_fatma), _("10"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_nbr_cons_2_fatma), _("12"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_nbr_cons_2_fatma), _("16"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_nbr_cons_2_fatma), _("22"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_nbr_cons_2_fatma), _("30"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_nbr_cons_2_fatma), _("40"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_nbr_cons_2_fatma), _("60"));

  statut_2_fatma = gtk_label_new (_("Satut des \303\251lections :"));
  gtk_widget_show (statut_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), statut_2_fatma, 56, 640);
  gtk_widget_set_size_request (statut_2_fatma, 128, 17);

  achevee_2_fatma = gtk_check_button_new_with_mnemonic (_("achev\303\251e"));
  gtk_widget_show (achevee_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), achevee_2_fatma, 216, 640);
  gtk_widget_set_size_request (achevee_2_fatma, 118, 24);

  cours_2_fatma = gtk_check_button_new_with_mnemonic (_("en cours"));
  gtk_widget_show (cours_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), cours_2_fatma, 368, 640);
  gtk_widget_set_size_request (cours_2_fatma, 118, 24);

  confirmer_2_fatma = gtk_button_new_with_mnemonic (_("confirmer"));
  gtk_widget_show (confirmer_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), confirmer_2_fatma, 96, 752);
  gtk_widget_set_size_request (confirmer_2_fatma, 136, 32);

  annuler_2_fatma = gtk_button_new_with_mnemonic (_("annuler"));
  gtk_widget_show (annuler_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), annuler_2_fatma, 360, 752);
  gtk_widget_set_size_request (annuler_2_fatma, 136, 32);

  plus_500k_2_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("plus de 500001"));
  gtk_widget_show (plus_500k_2_fatma);
  gtk_fixed_put (GTK_FIXED (fixed_2_fatma), plus_500k_2_fatma, 424, 496);
  gtk_widget_set_size_request (plus_500k_2_fatma, 150, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (plus_500k_2_fatma), jsq_5000_2_fatma_group);
  jsq_5000_2_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (plus_500k_2_fatma));

  g_signal_connect ((gpointer) jsq_5000_2_fatma, "toggled",
                    G_CALLBACK (on_jsq_5000_2_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) _5001_2_fatma, "toggled",
                    G_CALLBACK (on_5001_2_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) _10001_2_fatma, "toggled",
                    G_CALLBACK (on_10001_2_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) _25001_2_fatma, "toggled",
                    G_CALLBACK (on_25_001_2_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) _100001_2_fatma, "toggled",
                    G_CALLBACK (on_100_001_2_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) _50001_2_fatma, "toggled",
                    G_CALLBACK (on_radiobutton4_toggled),
                    NULL);
  g_signal_connect ((gpointer) chercher_fatma, "clicked",
                    G_CALLBACK (on_chercher_fatma_clicked),
                    NULL);
  g_signal_connect ((gpointer) achevee_2_fatma, "toggled",
                    G_CALLBACK (on_achevee_2_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) cours_2_fatma, "toggled",
                    G_CALLBACK (on_cours_2_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) confirmer_2_fatma, "clicked",
                    G_CALLBACK (on_confirmer_fatma_clicked),
                    NULL);
  g_signal_connect ((gpointer) annuler_2_fatma, "clicked",
                    G_CALLBACK (on_annuler_2_fatma_clicked),
                    NULL);
  g_signal_connect ((gpointer) plus_500k_2_fatma, "toggled",
                    G_CALLBACK (on_plus_500k_2_fatma_toggled),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (modifier_fatma, modifier_fatma, "modifier_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, fixed_2_fatma, "fixed_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, spin_jour2_fatma, "spin_jour2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, spin_mois_2_fatma, "spin_mois_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, label1, "label1");
  GLADE_HOOKUP_OBJECT (modifier_fatma, entry_idm_fatma, "entry_idm_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, entry_municipalite2_fatma, "entry_municipalite2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, indentifiant_fatma, "indentifiant_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, date2_fatma, "date2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, jour2_fatma, "jour2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, mois2_fatma, "mois2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, spin_annee_2_fatma, "spin_annee_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, annee2_fatma, "annee2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, municipalite2_fatma, "municipalite2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, nbre_hbt_2_fatma, "nbre_hbt_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, jsq_5000_2_fatma, "jsq_5000_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, _5001_2_fatma, "_5001_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, _10001_2_fatma, "_10001_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, _25001_2_fatma, "_25001_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, _100001_2_fatma, "_100001_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, _50001_2_fatma, "_50001_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, chercher_fatma, "chercher_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, nbr_conseil_2_fatma, "nbr_conseil_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, combo_nbr_cons_2_fatma, "combo_nbr_cons_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, statut_2_fatma, "statut_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, achevee_2_fatma, "achevee_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, cours_2_fatma, "cours_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, confirmer_2_fatma, "confirmer_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, annuler_2_fatma, "annuler_2_fatma");
  GLADE_HOOKUP_OBJECT (modifier_fatma, plus_500k_2_fatma, "plus_500k_2_fatma");

  return modifier_fatma;
}

GtkWidget*
create_ajouter_fatma (void)
{
  GtkWidget *ajouter_fatma;
  GtkWidget *fixed3;
  GtkObject *spin_mois_fatma_adj;
  GtkWidget *spin_mois_fatma;
  GtkObject *spin_jour_fatma_adj;
  GtkWidget *spin_jour_fatma;
  GtkObject *spin_annee_fatma_adj;
  GtkWidget *spin_annee_fatma;
  GtkWidget *entry2;
  GtkWidget *label16;
  GtkWidget *entry6;
  GtkWidget *identifiant_fatma;
  GtkWidget *municipalite_fatma;
  GtkWidget *nbr_hbt_fatma;
  GtkWidget *nbr_conseil_fatma;
  GtkWidget *date_fatma;
  GtkWidget *jour_fatma;
  GtkWidget *combobox2;
  GtkWidget *mois_fatma;
  GtkWidget *annee_fatma;
  GtkWidget *statut_fatma;
  GtkWidget *_25001_fatma;
  GSList *_25001_fatma_group = NULL;
  GtkWidget *plus_500001_fatma;
  GtkWidget *_100001_fatma;
  GtkWidget *_50001_fatma;
  GtkWidget *_10001_fatma;
  GtkWidget *_5001_fatma;
  GtkWidget *jsq_5000_fatma;
  GtkWidget *achevee_fatma;
  GtkWidget *cours_fatma;
  GtkWidget *annuler_fatma;
  GtkWidget *confirmer_fatma;

  ajouter_fatma = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (ajouter_fatma), _("ajouter"));

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (ajouter_fatma), fixed3);

  spin_mois_fatma_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  spin_mois_fatma = gtk_spin_button_new (GTK_ADJUSTMENT (spin_mois_fatma_adj), 1, 0);
  gtk_widget_show (spin_mois_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), spin_mois_fatma, 344, 512);
  gtk_widget_set_size_request (spin_mois_fatma, 60, 27);

  spin_jour_fatma_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  spin_jour_fatma = gtk_spin_button_new (GTK_ADJUSTMENT (spin_jour_fatma_adj), 1, 0);
  gtk_widget_show (spin_jour_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), spin_jour_fatma, 200, 512);
  gtk_widget_set_size_request (spin_jour_fatma, 60, 27);

  spin_annee_fatma_adj = gtk_adjustment_new (1, 1970, 2022, 1, 10, 10);
  spin_annee_fatma = gtk_spin_button_new (GTK_ADJUSTMENT (spin_annee_fatma_adj), 1, 0);
  gtk_widget_show (spin_annee_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), spin_annee_fatma, 496, 512);
  gtk_widget_set_size_request (spin_annee_fatma, 60, 27);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_fixed_put (GTK_FIXED (fixed3), entry2, 264, 88);
  gtk_widget_set_size_request (entry2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry2), 8226);

  label16 = gtk_label_new (_("Ajout"));
  gtk_widget_show (label16);
  gtk_fixed_put (GTK_FIXED (fixed3), label16, 256, 8);
  gtk_widget_set_size_request (label16, 152, 48);
  gtk_label_set_justify (GTK_LABEL (label16), GTK_JUSTIFY_CENTER);

  entry6 = gtk_entry_new ();
  gtk_widget_show (entry6);
  gtk_fixed_put (GTK_FIXED (fixed3), entry6, 264, 152);
  gtk_widget_set_size_request (entry6, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry6), 8226);

  identifiant_fatma = gtk_label_new (_("identifiant :"));
  gtk_widget_show (identifiant_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), identifiant_fatma, 88, 88);
  gtk_widget_set_size_request (identifiant_fatma, 80, 24);

  municipalite_fatma = gtk_label_new (_("Municipalit\303\251 :"));
  gtk_widget_show (municipalite_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), municipalite_fatma, 56, 152);
  gtk_widget_set_size_request (municipalite_fatma, 153, 24);

  nbr_hbt_fatma = gtk_label_new (_("Nombre d'habitants :"));
  gtk_widget_show (nbr_hbt_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), nbr_hbt_fatma, 72, 224);
  gtk_widget_set_size_request (nbr_hbt_fatma, 144, 24);
  gtk_label_set_justify (GTK_LABEL (nbr_hbt_fatma), GTK_JUSTIFY_CENTER);

  nbr_conseil_fatma = gtk_label_new (_("Nombre de conseillers:"));
  gtk_widget_show (nbr_conseil_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), nbr_conseil_fatma, 72, 448);
  gtk_widget_set_size_request (nbr_conseil_fatma, 154, 16);

  date_fatma = gtk_label_new (_("Date:"));
  gtk_widget_show (date_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), date_fatma, 64, 512);
  gtk_widget_set_size_request (date_fatma, 64, 24);

  jour_fatma = gtk_label_new (_("jour"));
  gtk_widget_show (jour_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), jour_fatma, 144, 512);
  gtk_widget_set_size_request (jour_fatma, 56, 24);

  combobox2 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox2);
  gtk_fixed_put (GTK_FIXED (fixed3), combobox2, 264, 440);
  gtk_widget_set_size_request (combobox2, 60, 31);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("10"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("12"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("16"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("22"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("30"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("40"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("60"));

  mois_fatma = gtk_label_new (_("mois"));
  gtk_widget_show (mois_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), mois_fatma, 272, 512);
  gtk_widget_set_size_request (mois_fatma, 49, 24);

  annee_fatma = gtk_label_new (_("ann\303\251e"));
  gtk_widget_show (annee_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), annee_fatma, 424, 512);
  gtk_widget_set_size_request (annee_fatma, 60, 27);

  statut_fatma = gtk_label_new (_("Satut des \303\251lections :"));
  gtk_widget_show (statut_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), statut_fatma, 64, 608);
  gtk_widget_set_size_request (statut_fatma, 128, 17);

  _25001_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("25001-50000"));
  gtk_widget_show (_25001_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), _25001_fatma, 248, 392);
  gtk_widget_set_size_request (_25001_fatma, 124, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_25001_fatma), _25001_fatma_group);
  _25001_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_25001_fatma));

  plus_500001_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("plus 500001"));
  gtk_widget_show (plus_500001_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), plus_500001_fatma, 400, 336);
  gtk_widget_set_size_request (plus_500001_fatma, 124, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (plus_500001_fatma), _25001_fatma_group);
  _25001_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (plus_500001_fatma));

  _100001_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("100001-500000"));
  gtk_widget_show (_100001_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), _100001_fatma, 400, 280);
  gtk_widget_set_size_request (_100001_fatma, 126, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_100001_fatma), _25001_fatma_group);
  _25001_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_100001_fatma));

  _50001_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("50001-100000"));
  gtk_widget_show (_50001_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), _50001_fatma, 400, 224);
  gtk_widget_set_size_request (_50001_fatma, 124, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_50001_fatma), _25001_fatma_group);
  _25001_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_50001_fatma));

  _10001_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("10001-25000"));
  gtk_widget_show (_10001_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), _10001_fatma, 248, 336);
  gtk_widget_set_size_request (_10001_fatma, 124, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_10001_fatma), _25001_fatma_group);
  _25001_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_10001_fatma));

  _5001_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("5001-10000"));
  gtk_widget_show (_5001_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), _5001_fatma, 248, 280);
  gtk_widget_set_size_request (_5001_fatma, 124, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (_5001_fatma), _25001_fatma_group);
  _25001_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (_5001_fatma));

  jsq_5000_fatma = gtk_radio_button_new_with_mnemonic (NULL, _("jusqu'\303\240 5000"));
  gtk_widget_show (jsq_5000_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), jsq_5000_fatma, 248, 224);
  gtk_widget_set_size_request (jsq_5000_fatma, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (jsq_5000_fatma), _25001_fatma_group);
  _25001_fatma_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (jsq_5000_fatma));

  achevee_fatma = gtk_check_button_new_with_mnemonic (_("achev\303\251e"));
  gtk_widget_show (achevee_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), achevee_fatma, 216, 600);
  gtk_widget_set_size_request (achevee_fatma, 118, 24);

  cours_fatma = gtk_check_button_new_with_mnemonic (_("en cours"));
  gtk_widget_show (cours_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), cours_fatma, 360, 600);
  gtk_widget_set_size_request (cours_fatma, 118, 24);

  annuler_fatma = gtk_button_new_with_mnemonic (_("annuler"));
  gtk_widget_show (annuler_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), annuler_fatma, 368, 688);
  gtk_widget_set_size_request (annuler_fatma, 136, 32);

  confirmer_fatma = gtk_button_new_with_mnemonic (_("confirmer"));
  gtk_widget_show (confirmer_fatma);
  gtk_fixed_put (GTK_FIXED (fixed3), confirmer_fatma, 120, 688);
  gtk_widget_set_size_request (confirmer_fatma, 136, 32);

  g_signal_connect ((gpointer) _25001_fatma, "toggled",
                    G_CALLBACK (on_25001_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) plus_500001_fatma, "toggled",
                    G_CALLBACK (on_plus_500001_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) _100001_fatma, "toggled",
                    G_CALLBACK (on_100001_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) _50001_fatma, "toggled",
                    G_CALLBACK (on_radiobutton17_toggled),
                    NULL);
  g_signal_connect ((gpointer) _10001_fatma, "toggled",
                    G_CALLBACK (on_10001_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) _5001_fatma, "toggled",
                    G_CALLBACK (on_5001_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) jsq_5000_fatma, "toggled",
                    G_CALLBACK (on_jsq_5000_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) achevee_fatma, "toggled",
                    G_CALLBACK (on_achevee_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) cours_fatma, "toggled",
                    G_CALLBACK (on_cours_fatma_toggled),
                    NULL);
  g_signal_connect ((gpointer) annuler_fatma, "clicked",
                    G_CALLBACK (on_annuler_fatma_clicked),
                    NULL);
  g_signal_connect ((gpointer) confirmer_fatma, "clicked",
                    G_CALLBACK (on_button11_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (ajouter_fatma, ajouter_fatma, "ajouter_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, spin_mois_fatma, "spin_mois_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, spin_jour_fatma, "spin_jour_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, spin_annee_fatma, "spin_annee_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, label16, "label16");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, entry6, "entry6");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, identifiant_fatma, "identifiant_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, municipalite_fatma, "municipalite_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, nbr_hbt_fatma, "nbr_hbt_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, nbr_conseil_fatma, "nbr_conseil_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, date_fatma, "date_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, jour_fatma, "jour_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, combobox2, "combobox2");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, mois_fatma, "mois_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, annee_fatma, "annee_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, statut_fatma, "statut_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, _25001_fatma, "_25001_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, plus_500001_fatma, "plus_500001_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, _100001_fatma, "_100001_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, _50001_fatma, "_50001_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, _10001_fatma, "_10001_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, _5001_fatma, "_5001_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, jsq_5000_fatma, "jsq_5000_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, achevee_fatma, "achevee_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, cours_fatma, "cours_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, annuler_fatma, "annuler_fatma");
  GLADE_HOOKUP_OBJECT (ajouter_fatma, confirmer_fatma, "confirmer_fatma");

  return ajouter_fatma;
}

