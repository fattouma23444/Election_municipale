/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"
#include "callbacks.h"
#include "GDU.h"

int
main (int argc, char *argv[])
{
  GtkWidget *GDU1;
  GtkWidget *GDU2;
  GtkWidget *GDU4;
  GtkWidget *GDU3;
  GtkWidget *GDU5;
  GtkWidget *treeview3;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  GDU1 = create_GDU1 ();
  gtk_widget_show (GDU1);
  set_event_box_background(GDU1,"/home/lou/Projects/project2/src/Bkgrnd.jpg");
  treeview3 = lookup_widget(GDU1,"trvf1");
  afficher_personne(treeview3,"GDU.txt");
  /*GDU5 = create_GDU5 ();
  gtk_widget_show (GDU5);
  GDU2 = create_GDU2 ();
  gtk_widget_show (GDU2);
  GDU4 = create_GDU4 ();
  gtk_widget_show (GDU4);
  GDU3 = create_GDU3 ();
  gtk_widget_show (GDU3);*/
  gtk_main ();
  return 0;
}

