#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct election
{
int id;
int ori;
int idt;
int id1;
int id2;
int id3;
}election;


void ajouterdhia(election u, char *fname);
void supprimerdhia(int id, char *fname);
void modifierdhia(election u, char *fname);
void afficherdhia(GtkWidget *liste, char *fname, int id);
election chercherdhia(int id, char *fname);
char* vote_liste(char *filename);

