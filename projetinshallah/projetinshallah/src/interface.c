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
create_Ajouter_fatma (void)
{
  GtkWidget *Ajouter_fatma;
  GtkWidget *fixeda_fatma;
  GtkObject *spin_jour_adj;
  GtkWidget *spin_jour;
  GtkObject *spin_mois_adj;
  GtkWidget *spin_mois;
  GtkObject *spin_annee_adj;
  GtkWidget *spin_annee;
  GtkWidget *entry_id;
  GtkWidget *entry_nbr_habitant;
  GtkWidget *label_jour;
  GtkWidget *label8;
  GtkWidget *label9;
  GtkWidget *Racheve;
  GSList *Racheve_group = NULL;
  GtkWidget *combo_muni;
  GtkWidget *retourf_1;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label20;
  GtkWidget *bajouter;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label21;
  GtkWidget *image14;
  GtkWidget *label_id;
  GtkWidget *label_municipalite;
  GtkWidget *label5;
  GtkWidget *label_date;
  GtkWidget *labelstatut;
  GtkWidget *Rcours;
  GtkWidget *label_ajout;
  GtkWidget *label_aff;

  Ajouter_fatma = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Ajouter_fatma), _("Ajouter \303\251lections"));

  fixeda_fatma = gtk_fixed_new ();
  gtk_widget_show (fixeda_fatma);
  gtk_container_add (GTK_CONTAINER (Ajouter_fatma), fixeda_fatma);

  spin_jour_adj = gtk_adjustment_new (12, 1, 31, 1, 10, 10);
  spin_jour = gtk_spin_button_new (GTK_ADJUSTMENT (spin_jour_adj), 1, 0);
  gtk_widget_show (spin_jour);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), spin_jour, 240, 248);
  gtk_widget_set_size_request (spin_jour, 60, 27);

  spin_mois_adj = gtk_adjustment_new (12, 1, 12, 1, 10, 10);
  spin_mois = gtk_spin_button_new (GTK_ADJUSTMENT (spin_mois_adj), 1, 0);
  gtk_widget_show (spin_mois);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), spin_mois, 368, 248);
  gtk_widget_set_size_request (spin_mois, 60, 27);

  spin_annee_adj = gtk_adjustment_new (2019, 1956, 2022, 1, 10, 10);
  spin_annee = gtk_spin_button_new (GTK_ADJUSTMENT (spin_annee_adj), 1, 0);
  gtk_widget_show (spin_annee);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), spin_annee, 512, 248);
  gtk_widget_set_size_request (spin_annee, 60, 27);

  entry_id = gtk_entry_new ();
  gtk_widget_show (entry_id);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), entry_id, 232, 72);
  gtk_widget_set_size_request (entry_id, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_id), 8226);

  entry_nbr_habitant = gtk_entry_new ();
  gtk_widget_show (entry_nbr_habitant);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), entry_nbr_habitant, 232, 176);
  gtk_widget_set_size_request (entry_nbr_habitant, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_nbr_habitant), 8226);

  label_jour = gtk_label_new (_("Jours"));
  gtk_widget_show (label_jour);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label_jour, 184, 256);
  gtk_widget_set_size_request (label_jour, 41, 17);

  label8 = gtk_label_new (_("Mois"));
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label8, 312, 256);
  gtk_widget_set_size_request (label8, 41, 17);

  label9 = gtk_label_new (_("Ann\303\251e"));
  gtk_widget_show (label9);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label9, 440, 256);
  gtk_widget_set_size_request (label9, 60, 17);

  Racheve = gtk_radio_button_new_with_mnemonic (NULL, _("achevee"));
  gtk_widget_show (Racheve);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), Racheve, 256, 352);
  gtk_widget_set_size_request (Racheve, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (Racheve), Racheve_group);
  Racheve_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (Racheve));

  combo_muni = gtk_combo_box_new_text ();
  gtk_widget_show (combo_muni);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), combo_muni, 232, 120);
  gtk_widget_set_size_request (combo_muni, 120, 31);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni), _("Tunis"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni), _("Manzah"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni), _("Manar"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni), _("Ariana"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni), _("Naceur"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni), _("Hammamet"));

  retourf_1 = gtk_button_new ();
  gtk_widget_show (retourf_1);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), retourf_1, 120, 520);
  gtk_widget_set_size_request (retourf_1, 100, 29);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (retourf_1), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label20 = gtk_label_new_with_mnemonic (_("<span foreground=\"red\" ><b>retour  </b></span>"));
  gtk_widget_show (label20);
  gtk_box_pack_start (GTK_BOX (hbox2), label20, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label20), TRUE);

  bajouter = gtk_button_new ();
  gtk_widget_show (bajouter);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), bajouter, 312, 520);
  gtk_widget_set_size_request (bajouter, 100, 29);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (bajouter), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label21 = gtk_label_new_with_mnemonic (_("<span foreground=\"green\" ><b>ajouter </b></span>"));
  gtk_widget_show (label21);
  gtk_box_pack_start (GTK_BOX (hbox3), label21, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label21), TRUE);

  image14 = create_pixmap (Ajouter_fatma, "Flag_of_Tunisia.svg.png");
  gtk_widget_show (image14);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), image14, 488, 8);
  gtk_widget_set_size_request (image14, 232, 104);

  label_id = gtk_label_new (_("<span foreground=\"black\" ><b>identifiant:  </b></span>"));
  gtk_widget_show (label_id);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label_id, 64, 72);
  gtk_widget_set_size_request (label_id, 80, 17);
  gtk_label_set_use_markup (GTK_LABEL (label_id), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label_id), 0.44, 0.5);

  label_municipalite = gtk_label_new (_("<span foreground=\"black\" ><b>Municipalite:  </b></span>"));
  gtk_widget_show (label_municipalite);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label_municipalite, 64, 128);
  gtk_widget_set_size_request (label_municipalite, 90, 17);
  gtk_label_set_use_markup (GTK_LABEL (label_municipalite), TRUE);

  label5 = gtk_label_new (_("<span foreground=\"black\" ><b>Nombre d'habitants:  </b></span>"));
  gtk_widget_show (label5);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label5, 64, 184);
  gtk_widget_set_size_request (label5, 150, 17);
  gtk_label_set_use_markup (GTK_LABEL (label5), TRUE);

  label_date = gtk_label_new (_("<span foreground=\"black\" ><b>Date:  </b></span>"));
  gtk_widget_show (label_date);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label_date, 48, 256);
  gtk_widget_set_size_request (label_date, 80, 17);
  gtk_label_set_use_markup (GTK_LABEL (label_date), TRUE);

  labelstatut = gtk_label_new (_("<span foreground=\"black\" ><b>Statut des elections:  </b></span>"));
  gtk_widget_show (labelstatut);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), labelstatut, 64, 344);
  gtk_widget_set_size_request (labelstatut, 150, 17);
  gtk_label_set_use_markup (GTK_LABEL (labelstatut), TRUE);

  Rcours = gtk_radio_button_new_with_mnemonic (NULL, _("encours"));
  gtk_widget_show (Rcours);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), Rcours, 256, 400);
  gtk_widget_set_size_request (Rcours, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (Rcours), Racheve_group);
  Racheve_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (Rcours));

  label_ajout = gtk_label_new (_("<span foreground=\"black\" ><b>**Ajouter une liste**  </b></span>"));
  gtk_widget_show (label_ajout);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label_ajout, 232, 24);
  gtk_widget_set_size_request (label_ajout, 180, 17);
  gtk_label_set_use_markup (GTK_LABEL (label_ajout), TRUE);

  label_aff = gtk_label_new (_("..."));
  gtk_widget_show (label_aff);
  gtk_fixed_put (GTK_FIXED (fixeda_fatma), label_aff, 208, 480);
  gtk_widget_set_size_request (label_aff, 150, 17);

  g_signal_connect ((gpointer) Racheve, "toggled",
                    G_CALLBACK (on_Racheve_toggled),
                    NULL);
  g_signal_connect ((gpointer) retourf_1, "clicked",
                    G_CALLBACK (on_retourf_1_clicked),
                    NULL);
  g_signal_connect ((gpointer) bajouter, "clicked",
                    G_CALLBACK (on_bajouter_clicked),
                    NULL);
  g_signal_connect ((gpointer) Rcours, "toggled",
                    G_CALLBACK (on_Rcours_toggled),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Ajouter_fatma, Ajouter_fatma, "Ajouter_fatma");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, fixeda_fatma, "fixeda_fatma");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, spin_jour, "spin_jour");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, spin_mois, "spin_mois");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, spin_annee, "spin_annee");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, entry_id, "entry_id");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, entry_nbr_habitant, "entry_nbr_habitant");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label_jour, "label_jour");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label8, "label8");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label9, "label9");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, Racheve, "Racheve");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, combo_muni, "combo_muni");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, retourf_1, "retourf_1");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, image2, "image2");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label20, "label20");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, bajouter, "bajouter");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, image3, "image3");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label21, "label21");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, image14, "image14");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label_id, "label_id");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label_municipalite, "label_municipalite");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label5, "label5");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label_date, "label_date");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, labelstatut, "labelstatut");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, Rcours, "Rcours");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label_ajout, "label_ajout");
  GLADE_HOOKUP_OBJECT (Ajouter_fatma, label_aff, "label_aff");

  return Ajouter_fatma;
}

GtkWidget*
create_Modifier_fatma (void)
{
  GtkWidget *Modifier_fatma;
  GtkWidget *fixedm_fatma;
  GtkObject *spin_jour2_adj;
  GtkWidget *spin_jour2;
  GtkObject *spin_mois2_adj;
  GtkWidget *spin_mois2;
  GtkWidget *label_annee2;
  GtkObject *spin_annee2_adj;
  GtkWidget *spin_annee2;
  GtkWidget *entry_nb_h2;
  GtkWidget *entry_id2;
  GtkWidget *label_stat;
  GtkWidget *label_date;
  GtkWidget *label_mois2;
  GtkWidget *label_jour2;
  GtkWidget *label_nb_h2;
  GtkWidget *label_muni2;
  GtkWidget *label_id2;
  GtkWidget *label_modif;
  GtkWidget *Rachevee2;
  GSList *Rachevee2_group = NULL;
  GtkWidget *resultatf;
  GtkWidget *retourf2;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label18;
  GtkWidget *chercherf;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label23;
  GtkWidget *combo_muni2;
  GtkWidget *confirmerf;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label22;
  GtkWidget *Rcours_2;

  Modifier_fatma = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Modifier_fatma), _("Modifier l'election"));

  fixedm_fatma = gtk_fixed_new ();
  gtk_widget_show (fixedm_fatma);
  gtk_container_add (GTK_CONTAINER (Modifier_fatma), fixedm_fatma);

  spin_jour2_adj = gtk_adjustment_new (12, 1, 31, 1, 10, 10);
  spin_jour2 = gtk_spin_button_new (GTK_ADJUSTMENT (spin_jour2_adj), 1, 0);
  gtk_widget_show (spin_jour2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), spin_jour2, 240, 248);
  gtk_widget_set_size_request (spin_jour2, 60, 27);

  spin_mois2_adj = gtk_adjustment_new (12, 1, 12, 1, 10, 10);
  spin_mois2 = gtk_spin_button_new (GTK_ADJUSTMENT (spin_mois2_adj), 1, 0);
  gtk_widget_show (spin_mois2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), spin_mois2, 368, 248);
  gtk_widget_set_size_request (spin_mois2, 60, 27);

  label_annee2 = gtk_label_new (_("Ann\303\251e"));
  gtk_widget_show (label_annee2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_annee2, 440, 256);
  gtk_widget_set_size_request (label_annee2, 60, 17);

  spin_annee2_adj = gtk_adjustment_new (2019, 1956, 2022, 1, 10, 10);
  spin_annee2 = gtk_spin_button_new (GTK_ADJUSTMENT (spin_annee2_adj), 1, 0);
  gtk_widget_show (spin_annee2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), spin_annee2, 512, 248);
  gtk_widget_set_size_request (spin_annee2, 60, 27);

  entry_nb_h2 = gtk_entry_new ();
  gtk_widget_show (entry_nb_h2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), entry_nb_h2, 248, 176);
  gtk_widget_set_size_request (entry_nb_h2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_nb_h2), 8226);

  entry_id2 = gtk_entry_new ();
  gtk_widget_show (entry_id2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), entry_id2, 248, 64);
  gtk_widget_set_size_request (entry_id2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_id2), 8226);

  label_stat = gtk_label_new (_("statut des elections:"));
  gtk_widget_show (label_stat);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_stat, 64, 328);
  gtk_widget_set_size_request (label_stat, 140, 17);

  label_date = gtk_label_new (_("Date:"));
  gtk_widget_show (label_date);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_date, 40, 256);
  gtk_widget_set_size_request (label_date, 80, 17);

  label_mois2 = gtk_label_new (_("Mois"));
  gtk_widget_show (label_mois2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_mois2, 312, 256);
  gtk_widget_set_size_request (label_mois2, 41, 17);

  label_jour2 = gtk_label_new (_("Jours"));
  gtk_widget_show (label_jour2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_jour2, 184, 256);
  gtk_widget_set_size_request (label_jour2, 41, 17);

  label_nb_h2 = gtk_label_new (_("Nombre d'habitants:"));
  gtk_widget_show (label_nb_h2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_nb_h2, 56, 184);
  gtk_widget_set_size_request (label_nb_h2, 150, 17);

  label_muni2 = gtk_label_new (_("Municipalite:"));
  gtk_widget_show (label_muni2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_muni2, 64, 128);
  gtk_widget_set_size_request (label_muni2, 90, 17);

  label_id2 = gtk_label_new (_("Identifiant:"));
  gtk_widget_show (label_id2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_id2, 64, 72);
  gtk_widget_set_size_request (label_id2, 80, 17);

  label_modif = gtk_label_new (_("Modifier"));
  gtk_widget_show (label_modif);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), label_modif, 264, 24);
  gtk_widget_set_size_request (label_modif, 96, 16);

  Rachevee2 = gtk_radio_button_new_with_mnemonic (NULL, _("achevee"));
  gtk_widget_show (Rachevee2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), Rachevee2, 248, 320);
  gtk_widget_set_size_request (Rachevee2, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (Rachevee2), Rachevee2_group);
  Rachevee2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (Rachevee2));

  resultatf = gtk_label_new ("");
  gtk_widget_show (resultatf);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), resultatf, 208, 448);
  gtk_widget_set_size_request (resultatf, 170, 17);

  retourf2 = gtk_button_new ();
  gtk_widget_show (retourf2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), retourf2, 160, 472);
  gtk_widget_set_size_request (retourf2, 100, 29);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (retourf2), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label18 = gtk_label_new_with_mnemonic (_("retour"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox1), label18, FALSE, FALSE, 0);

  chercherf = gtk_button_new ();
  gtk_widget_show (chercherf);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), chercherf, 440, 64);
  gtk_widget_set_size_request (chercherf, 100, 29);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (chercherf), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-info", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label23 = gtk_label_new_with_mnemonic (_("chercher"));
  gtk_widget_show (label23);
  gtk_box_pack_start (GTK_BOX (hbox5), label23, FALSE, FALSE, 0);

  combo_muni2 = gtk_combo_box_new_text ();
  gtk_widget_show (combo_muni2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), combo_muni2, 256, 120);
  gtk_widget_set_size_request (combo_muni2, 120, 31);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni2), _("Tunis"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni2), _("Manzah"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni2), _("Manar"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni2), _("Ariana"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni2), _("Naceur"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combo_muni2), _("Hammamet"));

  confirmerf = gtk_button_new ();
  gtk_widget_show (confirmerf);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), confirmerf, 352, 472);
  gtk_widget_set_size_request (confirmerf, 100, 29);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (confirmerf), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label22 = gtk_label_new_with_mnemonic (_("confirmer"));
  gtk_widget_show (label22);
  gtk_box_pack_start (GTK_BOX (hbox4), label22, FALSE, FALSE, 0);

  Rcours_2 = gtk_radio_button_new_with_mnemonic (NULL, _("encours"));
  gtk_widget_show (Rcours_2);
  gtk_fixed_put (GTK_FIXED (fixedm_fatma), Rcours_2, 248, 376);
  gtk_widget_set_size_request (Rcours_2, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (Rcours_2), Rachevee2_group);
  Rachevee2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (Rcours_2));

  g_signal_connect ((gpointer) Rachevee2, "toggled",
                    G_CALLBACK (on_Rachevee2_toggled),
                    NULL);
  g_signal_connect ((gpointer) retourf2, "clicked",
                    G_CALLBACK (on_retourf2_clicked),
                    NULL);
  g_signal_connect ((gpointer) chercherf, "clicked",
                    G_CALLBACK (on_chercherf_clicked),
                    NULL);
  g_signal_connect ((gpointer) confirmerf, "clicked",
                    G_CALLBACK (on_confirmerf_clicked),
                    NULL);
  g_signal_connect ((gpointer) Rcours_2, "toggled",
                    G_CALLBACK (on_Rcours_2_toggled),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Modifier_fatma, Modifier_fatma, "Modifier_fatma");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, fixedm_fatma, "fixedm_fatma");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, spin_jour2, "spin_jour2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, spin_mois2, "spin_mois2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_annee2, "label_annee2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, spin_annee2, "spin_annee2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, entry_nb_h2, "entry_nb_h2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, entry_id2, "entry_id2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_stat, "label_stat");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_date, "label_date");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_mois2, "label_mois2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_jour2, "label_jour2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_nb_h2, "label_nb_h2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_muni2, "label_muni2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_id2, "label_id2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label_modif, "label_modif");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, Rachevee2, "Rachevee2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, resultatf, "resultatf");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, retourf2, "retourf2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, image1, "image1");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label18, "label18");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, chercherf, "chercherf");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, image5, "image5");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label23, "label23");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, combo_muni2, "combo_muni2");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, confirmerf, "confirmerf");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, image4, "image4");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, label22, "label22");
  GLADE_HOOKUP_OBJECT (Modifier_fatma, Rcours_2, "Rcours_2");

  return Modifier_fatma;
}

GtkWidget*
create_afficher_fatma (void)
{
  GtkWidget *afficher_fatma;
  GtkWidget *fixed1;
  GtkWidget *tree_fatma;
  GtkWidget *label19;
  GtkWidget *modifiertf;
  GtkWidget *alignment7;
  GtkWidget *hbox7;
  GtkWidget *image7;
  GtkWidget *label25;
  GtkWidget *ajouterf;
  GtkWidget *alignment6;
  GtkWidget *hbox6;
  GtkWidget *image6;
  GtkWidget *label24;
  GtkWidget *supprimerft;
  GtkWidget *alignment8;
  GtkWidget *hbox8;
  GtkWidget *image8;
  GtkWidget *label26;
  GtkWidget *actualisertf;
  GtkWidget *alignment9;
  GtkWidget *hbox9;
  GtkWidget *image9;
  GtkWidget *label27;
  GtkWidget *retourprincipal_fatma;
  GtkWidget *alignment10;
  GtkWidget *hbox10;
  GtkWidget *image10;
  GtkWidget *label28;

  afficher_fatma = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (afficher_fatma), _("Affichage des \303\251lections"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (afficher_fatma), fixed1);

  tree_fatma = gtk_tree_view_new ();
  gtk_widget_show (tree_fatma);
  gtk_fixed_put (GTK_FIXED (fixed1), tree_fatma, 40, 80);
  gtk_widget_set_size_request (tree_fatma, 590, 200);

  label19 = gtk_label_new (_("afficher"));
  gtk_widget_show (label19);
  gtk_fixed_put (GTK_FIXED (fixed1), label19, 216, 32);
  gtk_widget_set_size_request (label19, 100, 17);

  modifiertf = gtk_button_new ();
  gtk_widget_show (modifiertf);
  gtk_fixed_put (GTK_FIXED (fixed1), modifiertf, 240, 344);
  gtk_widget_set_size_request (modifiertf, 100, 29);

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (modifiertf), alignment7);

  hbox7 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox7);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox7);

  image7 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image7);
  gtk_box_pack_start (GTK_BOX (hbox7), image7, FALSE, FALSE, 0);

  label25 = gtk_label_new_with_mnemonic (_("modifier"));
  gtk_widget_show (label25);
  gtk_box_pack_start (GTK_BOX (hbox7), label25, FALSE, FALSE, 0);

  ajouterf = gtk_button_new ();
  gtk_widget_show (ajouterf);
  gtk_fixed_put (GTK_FIXED (fixed1), ajouterf, 376, 344);
  gtk_widget_set_size_request (ajouterf, 100, 29);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (ajouterf), alignment6);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox6);

  image6 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox6), image6, FALSE, FALSE, 0);

  label24 = gtk_label_new_with_mnemonic (_("ajouter"));
  gtk_widget_show (label24);
  gtk_box_pack_start (GTK_BOX (hbox6), label24, FALSE, FALSE, 0);

  supprimerft = gtk_button_new ();
  gtk_widget_show (supprimerft);
  gtk_fixed_put (GTK_FIXED (fixed1), supprimerft, 104, 344);
  gtk_widget_set_size_request (supprimerft, 100, 29);

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (supprimerft), alignment8);

  hbox8 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox8);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox8);

  image8 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image8);
  gtk_box_pack_start (GTK_BOX (hbox8), image8, FALSE, FALSE, 0);

  label26 = gtk_label_new_with_mnemonic (_("supprimer"));
  gtk_widget_show (label26);
  gtk_box_pack_start (GTK_BOX (hbox8), label26, FALSE, FALSE, 0);

  actualisertf = gtk_button_new ();
  gtk_widget_show (actualisertf);
  gtk_fixed_put (GTK_FIXED (fixed1), actualisertf, 224, 296);
  gtk_widget_set_size_request (actualisertf, 104, 29);

  alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment9);
  gtk_container_add (GTK_CONTAINER (actualisertf), alignment9);

  hbox9 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox9);
  gtk_container_add (GTK_CONTAINER (alignment9), hbox9);

  image9 = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image9);
  gtk_box_pack_start (GTK_BOX (hbox9), image9, FALSE, FALSE, 0);

  label27 = gtk_label_new_with_mnemonic (_("actualiser"));
  gtk_widget_show (label27);
  gtk_box_pack_start (GTK_BOX (hbox9), label27, FALSE, FALSE, 0);

  retourprincipal_fatma = gtk_button_new ();
  gtk_widget_show (retourprincipal_fatma);
  gtk_fixed_put (GTK_FIXED (fixed1), retourprincipal_fatma, 40, 16);
  gtk_widget_set_size_request (retourprincipal_fatma, 100, 29);

  alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment10);
  gtk_container_add (GTK_CONTAINER (retourprincipal_fatma), alignment10);

  hbox10 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox10);
  gtk_container_add (GTK_CONTAINER (alignment10), hbox10);

  image10 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image10);
  gtk_box_pack_start (GTK_BOX (hbox10), image10, FALSE, FALSE, 0);

  label28 = gtk_label_new_with_mnemonic (_("retour"));
  gtk_widget_show (label28);
  gtk_box_pack_start (GTK_BOX (hbox10), label28, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) modifiertf, "clicked",
                    G_CALLBACK (on_modifiertf_clicked),
                    NULL);
  g_signal_connect ((gpointer) ajouterf, "clicked",
                    G_CALLBACK (on_ajouterf_clicked),
                    NULL);
  g_signal_connect ((gpointer) supprimerft, "clicked",
                    G_CALLBACK (on_supprimerft_clicked),
                    NULL);
  g_signal_connect ((gpointer) actualisertf, "clicked",
                    G_CALLBACK (on_actualisertf_clicked),
                    NULL);
  g_signal_connect ((gpointer) retourprincipal_fatma, "clicked",
                    G_CALLBACK (on_retourprincipal_fatma_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (afficher_fatma, afficher_fatma, "afficher_fatma");
  GLADE_HOOKUP_OBJECT (afficher_fatma, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (afficher_fatma, tree_fatma, "tree_fatma");
  GLADE_HOOKUP_OBJECT (afficher_fatma, label19, "label19");
  GLADE_HOOKUP_OBJECT (afficher_fatma, modifiertf, "modifiertf");
  GLADE_HOOKUP_OBJECT (afficher_fatma, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (afficher_fatma, hbox7, "hbox7");
  GLADE_HOOKUP_OBJECT (afficher_fatma, image7, "image7");
  GLADE_HOOKUP_OBJECT (afficher_fatma, label25, "label25");
  GLADE_HOOKUP_OBJECT (afficher_fatma, ajouterf, "ajouterf");
  GLADE_HOOKUP_OBJECT (afficher_fatma, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (afficher_fatma, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (afficher_fatma, image6, "image6");
  GLADE_HOOKUP_OBJECT (afficher_fatma, label24, "label24");
  GLADE_HOOKUP_OBJECT (afficher_fatma, supprimerft, "supprimerft");
  GLADE_HOOKUP_OBJECT (afficher_fatma, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (afficher_fatma, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (afficher_fatma, image8, "image8");
  GLADE_HOOKUP_OBJECT (afficher_fatma, label26, "label26");
  GLADE_HOOKUP_OBJECT (afficher_fatma, actualisertf, "actualisertf");
  GLADE_HOOKUP_OBJECT (afficher_fatma, alignment9, "alignment9");
  GLADE_HOOKUP_OBJECT (afficher_fatma, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (afficher_fatma, image9, "image9");
  GLADE_HOOKUP_OBJECT (afficher_fatma, label27, "label27");
  GLADE_HOOKUP_OBJECT (afficher_fatma, retourprincipal_fatma, "retourprincipal_fatma");
  GLADE_HOOKUP_OBJECT (afficher_fatma, alignment10, "alignment10");
  GLADE_HOOKUP_OBJECT (afficher_fatma, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (afficher_fatma, image10, "image10");
  GLADE_HOOKUP_OBJECT (afficher_fatma, label28, "label28");

  return afficher_fatma;
}

GtkWidget*
create_supprimer_fatma (void)
{
  GtkWidget *supprimer_fatma;
  GtkWidget *fixed2;
  GtkWidget *label_sup;
  GtkWidget *entry_id_suppf;
  GtkWidget *chercher_suppf;
  GtkWidget *alignment11;
  GtkWidget *hbox11;
  GtkWidget *image11;
  GtkWidget *label29;
  GtkWidget *result_supf;
  GtkWidget *check_robotf;
  GtkWidget *resultat_chersf;
  GtkWidget *label_sup_fatma;
  GtkWidget *bconf_supf;
  GtkWidget *alignment12;
  GtkWidget *hbox12;
  GtkWidget *image12;
  GtkWidget *label30;
  GtkWidget *bannuler_supf;
  GtkWidget *alignment13;
  GtkWidget *hbox13;
  GtkWidget *image13;
  GtkWidget *label31;

  supprimer_fatma = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (supprimer_fatma), _("supprimer une election"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (supprimer_fatma), fixed2);

  label_sup = gtk_label_new (_("Supprimer"));
  gtk_widget_show (label_sup);
  gtk_fixed_put (GTK_FIXED (fixed2), label_sup, 240, 40);
  gtk_widget_set_size_request (label_sup, 136, 24);

  entry_id_suppf = gtk_entry_new ();
  gtk_widget_show (entry_id_suppf);
  gtk_fixed_put (GTK_FIXED (fixed2), entry_id_suppf, 224, 112);
  gtk_widget_set_size_request (entry_id_suppf, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_id_suppf), 8226);

  chercher_suppf = gtk_button_new ();
  gtk_widget_show (chercher_suppf);
  gtk_fixed_put (GTK_FIXED (fixed2), chercher_suppf, 424, 104);
  gtk_widget_set_size_request (chercher_suppf, 96, 32);

  alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment11);
  gtk_container_add (GTK_CONTAINER (chercher_suppf), alignment11);

  hbox11 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox11);
  gtk_container_add (GTK_CONTAINER (alignment11), hbox11);

  image11 = gtk_image_new_from_stock ("gtk-dialog-info", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image11);
  gtk_box_pack_start (GTK_BOX (hbox11), image11, FALSE, FALSE, 0);

  label29 = gtk_label_new_with_mnemonic (_("chercher"));
  gtk_widget_show (label29);
  gtk_box_pack_start (GTK_BOX (hbox11), label29, FALSE, FALSE, 0);

  result_supf = gtk_label_new (_("...."));
  gtk_widget_show (result_supf);
  gtk_fixed_put (GTK_FIXED (fixed2), result_supf, 184, 376);
  gtk_widget_set_size_request (result_supf, 200, 17);

  check_robotf = gtk_check_button_new_with_mnemonic (_("Est-ce que vous etes sur ?"));
  gtk_widget_show (check_robotf);
  gtk_fixed_put (GTK_FIXED (fixed2), check_robotf, 184, 296);
  gtk_widget_set_size_request (check_robotf, 194, 24);

  resultat_chersf = gtk_label_new (_("..."));
  gtk_widget_show (resultat_chersf);
  gtk_fixed_put (GTK_FIXED (fixed2), resultat_chersf, 184, 216);
  gtk_widget_set_size_request (resultat_chersf, 200, 17);

  label_sup_fatma = gtk_label_new (_("Identifiant:"));
  gtk_widget_show (label_sup_fatma);
  gtk_fixed_put (GTK_FIXED (fixed2), label_sup_fatma, 64, 120);
  gtk_widget_set_size_request (label_sup_fatma, 96, 16);

  bconf_supf = gtk_button_new ();
  gtk_widget_show (bconf_supf);
  gtk_fixed_put (GTK_FIXED (fixed2), bconf_supf, 376, 440);
  gtk_widget_set_size_request (bconf_supf, 112, 32);

  alignment12 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment12);
  gtk_container_add (GTK_CONTAINER (bconf_supf), alignment12);

  hbox12 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox12);
  gtk_container_add (GTK_CONTAINER (alignment12), hbox12);

  image12 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image12);
  gtk_box_pack_start (GTK_BOX (hbox12), image12, FALSE, FALSE, 0);

  label30 = gtk_label_new_with_mnemonic (_("confirmer"));
  gtk_widget_show (label30);
  gtk_box_pack_start (GTK_BOX (hbox12), label30, FALSE, FALSE, 0);

  bannuler_supf = gtk_button_new ();
  gtk_widget_show (bannuler_supf);
  gtk_fixed_put (GTK_FIXED (fixed2), bannuler_supf, 112, 440);
  gtk_widget_set_size_request (bannuler_supf, 112, 32);

  alignment13 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment13);
  gtk_container_add (GTK_CONTAINER (bannuler_supf), alignment13);

  hbox13 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox13);
  gtk_container_add (GTK_CONTAINER (alignment13), hbox13);

  image13 = gtk_image_new_from_stock ("gtk-stop", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image13);
  gtk_box_pack_start (GTK_BOX (hbox13), image13, FALSE, FALSE, 0);

  label31 = gtk_label_new_with_mnemonic (_("annuler"));
  gtk_widget_show (label31);
  gtk_box_pack_start (GTK_BOX (hbox13), label31, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) chercher_suppf, "clicked",
                    G_CALLBACK (on_chercher_suppf_clicked),
                    NULL);
  g_signal_connect ((gpointer) check_robotf, "toggled",
                    G_CALLBACK (on_check_robotf_toggled),
                    NULL);
  g_signal_connect ((gpointer) bconf_supf, "clicked",
                    G_CALLBACK (on_bconf_supf_clicked),
                    NULL);
  g_signal_connect ((gpointer) bannuler_supf, "clicked",
                    G_CALLBACK (on_bannuler_supf_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (supprimer_fatma, supprimer_fatma, "supprimer_fatma");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, label_sup, "label_sup");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, entry_id_suppf, "entry_id_suppf");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, chercher_suppf, "chercher_suppf");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, alignment11, "alignment11");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, image11, "image11");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, label29, "label29");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, result_supf, "result_supf");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, check_robotf, "check_robotf");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, resultat_chersf, "resultat_chersf");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, label_sup_fatma, "label_sup_fatma");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, bconf_supf, "bconf_supf");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, alignment12, "alignment12");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, hbox12, "hbox12");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, image12, "image12");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, label30, "label30");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, bannuler_supf, "bannuler_supf");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, alignment13, "alignment13");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, hbox13, "hbox13");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, image13, "image13");
  GLADE_HOOKUP_OBJECT (supprimer_fatma, label31, "label31");

  return supprimer_fatma;
}
