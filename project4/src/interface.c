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
create_windowfiltrage1 (void)
{
  GtkWidget *windowfiltrage1;
  GtkWidget *fixed1;
  GtkWidget *lbl1;
  GtkWidget *lbl2;
  GtkWidget *entryp;
  GtkObject *spnb_adj;
  GtkWidget *spnb;
  GtkWidget *lbl3;
  GtkWidget *lbl4;
  GtkWidget *btnfiltrage;

  windowfiltrage1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (windowfiltrage1), _("Filtrage"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (windowfiltrage1), fixed1);

  lbl1 = gtk_label_new (_("Pr\303\251nom :"));
  gtk_widget_show (lbl1);
  gtk_fixed_put (GTK_FIXED (fixed1), lbl1, 24, 32);
  gtk_widget_set_size_request (lbl1, 88, 40);

  lbl2 = gtk_label_new (_("Age :"));
  gtk_widget_show (lbl2);
  gtk_fixed_put (GTK_FIXED (fixed1), lbl2, 40, 120);
  gtk_widget_set_size_request (lbl2, 56, 24);

  entryp = gtk_entry_new ();
  gtk_widget_show (entryp);
  gtk_fixed_put (GTK_FIXED (fixed1), entryp, 120, 40);
  gtk_widget_set_size_request (entryp, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryp), 8226);

  spnb_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spnb = gtk_spin_button_new (GTK_ADJUSTMENT (spnb_adj), 1, 0);
  gtk_widget_show (spnb);
  gtk_fixed_put (GTK_FIXED (fixed1), spnb, 104, 120);
  gtk_widget_set_size_request (spnb, 60, 27);

  lbl3 = gtk_label_new (_("Nombre de personnes :"));
  gtk_widget_show (lbl3);
  gtk_fixed_put (GTK_FIXED (fixed1), lbl3, 32, 248);
  gtk_widget_set_size_request (lbl3, 208, 24);

  lbl4 = gtk_label_new ("");
  gtk_widget_show (lbl4);
  gtk_fixed_put (GTK_FIXED (fixed1), lbl4, 224, 248);
  gtk_widget_set_size_request (lbl4, 64, 32);

  btnfiltrage = gtk_button_new_with_mnemonic (_("Filtrer"));
  gtk_widget_show (btnfiltrage);
  gtk_fixed_put (GTK_FIXED (fixed1), btnfiltrage, 152, 184);
  gtk_widget_set_size_request (btnfiltrage, 104, 40);

  g_signal_connect ((gpointer) btnfiltrage, "clicked",
                    G_CALLBACK (on_btnfiltrage_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (windowfiltrage1, windowfiltrage1, "windowfiltrage1");
  GLADE_HOOKUP_OBJECT (windowfiltrage1, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (windowfiltrage1, lbl1, "lbl1");
  GLADE_HOOKUP_OBJECT (windowfiltrage1, lbl2, "lbl2");
  GLADE_HOOKUP_OBJECT (windowfiltrage1, entryp, "entryp");
  GLADE_HOOKUP_OBJECT (windowfiltrage1, spnb, "spnb");
  GLADE_HOOKUP_OBJECT (windowfiltrage1, lbl3, "lbl3");
  GLADE_HOOKUP_OBJECT (windowfiltrage1, lbl4, "lbl4");
  GLADE_HOOKUP_OBJECT (windowfiltrage1, btnfiltrage, "btnfiltrage");

  return windowfiltrage1;
}

GtkWidget*
create_windowfiltrage2 (void)
{
  GtkWidget *windowfiltrage2;
  GtkWidget *fixed2;
  GtkWidget *lblnom;
  GtkWidget *lbldeleg;
  GtkWidget *entryn;
  GtkWidget *btnfiltrage2;
  GtkWidget *label9;
  GtkWidget *combod;
  GtkWidget *lblcp;

  windowfiltrage2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (windowfiltrage2), _("Filtrage"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (windowfiltrage2), fixed2);

  lblnom = gtk_label_new (_("Nom :"));
  gtk_widget_show (lblnom);
  gtk_fixed_put (GTK_FIXED (fixed2), lblnom, 40, 32);
  gtk_widget_set_size_request (lblnom, 80, 32);

  lbldeleg = gtk_label_new (_("D\303\251l\303\251gation :"));
  gtk_widget_show (lbldeleg);
  gtk_fixed_put (GTK_FIXED (fixed2), lbldeleg, 32, 88);
  gtk_widget_set_size_request (lbldeleg, 104, 24);

  entryn = gtk_entry_new ();
  gtk_widget_show (entryn);
  gtk_fixed_put (GTK_FIXED (fixed2), entryn, 120, 40);
  gtk_widget_set_size_request (entryn, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryn), 8226);

  btnfiltrage2 = gtk_button_new_with_mnemonic (_("Filtrer"));
  gtk_widget_show (btnfiltrage2);
  gtk_fixed_put (GTK_FIXED (fixed2), btnfiltrage2, 144, 160);
  gtk_widget_set_size_request (btnfiltrage2, 104, 40);

  label9 = gtk_label_new (_("Nombre de personnes :"));
  gtk_widget_show (label9);
  gtk_fixed_put (GTK_FIXED (fixed2), label9, 40, 232);
  gtk_widget_set_size_request (label9, 184, 32);

  combod = gtk_combo_box_new_text ();
  gtk_widget_show (combod);
  gtk_fixed_put (GTK_FIXED (fixed2), combod, 136, 88);
  gtk_widget_set_size_request (combod, 160, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combod), _("Ariana"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combod), _("Tunis"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combod), _("BenArous"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combod), _("Manouba"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combod), _("Nabeul"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combod), _("Sfax"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combod), _("Gabes"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combod), _("Sousse"));

  lblcp = gtk_label_new ("");
  gtk_widget_show (lblcp);
  gtk_fixed_put (GTK_FIXED (fixed2), lblcp, 216, 232);
  gtk_widget_set_size_request (lblcp, 72, 32);

  g_signal_connect ((gpointer) btnfiltrage2, "clicked",
                    G_CALLBACK (on_btnfiltrage2_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (windowfiltrage2, windowfiltrage2, "windowfiltrage2");
  GLADE_HOOKUP_OBJECT (windowfiltrage2, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (windowfiltrage2, lblnom, "lblnom");
  GLADE_HOOKUP_OBJECT (windowfiltrage2, lbldeleg, "lbldeleg");
  GLADE_HOOKUP_OBJECT (windowfiltrage2, entryn, "entryn");
  GLADE_HOOKUP_OBJECT (windowfiltrage2, btnfiltrage2, "btnfiltrage2");
  GLADE_HOOKUP_OBJECT (windowfiltrage2, label9, "label9");
  GLADE_HOOKUP_OBJECT (windowfiltrage2, combod, "combod");
  GLADE_HOOKUP_OBJECT (windowfiltrage2, lblcp, "lblcp");

  return windowfiltrage2;
}

