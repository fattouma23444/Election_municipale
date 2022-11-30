#include "elections1.h"

int ajouter(char *filename, election elect)
{
    FILE * f;
    f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %s %ld %ld %d %d \n", elect.date.jour,elect.date.mois, elect.date.annee,elect.m,elect.id,elect.nb_habitant, elect.nb_conseiller, elect.statut);
        fclose(f);
        return 1;
    }
    else
	 return 0;
}
int modifier( char *filename, int id, election nouv )
{
    int tr=0;
    election elect;
    FILE *f=fopen(filename, "r");
    FILE *f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %ld %ld %d %d\n", &elect.date.jour,&elect.date.mois, &elect.date.annee,elect.m,&elect.id,&elect.nb_habitant, &elect.nb_conseiller, &elect.statut)!=EOF)
        {
            if(elect.id== id)
            {
                fprintf(f2,"%d %d %d %s %ld %ld %d %d \n",nouv.date.jour,nouv.date.mois,nouv.date.annee, nouv.m, nouv.id, nouv.nb_habitant, nouv.nb_conseiller, nouv.statut);
                tr=1;
            }
            else
               fprintf(f2,"%d %d %d %s %ld %ld %d %d \n", elect.date.jour,elect.date.mois, elect.date.annee,elect.m,elect.id,elect.nb_habitant, elect.nb_conseiller, elect.statut);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int id)
{
    int tr=0;
    election elect;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv1.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %ld %ld %d %d \n",&elect.date.jour,&elect.date.mois, &elect.date.annee, elect.m ,&elect.id,&elect.nb_habitant,&elect.nb_conseiller, &elect.statut)!=EOF)
        {
            if(elect.id==id)
                tr=1;
            else
                fprintf(f2,"%d %d %d %s %ld %ld %d %d \n",elect.date.jour,elect.date.mois, elect.date.annee,elect.m,elect.id,elect.nb_habitant, elect.nb_conseiller, elect.statut);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv1.txt", filename);
    return tr;
}
election chercher(char *filename, int id)
{
    election elect;
    int tr=0;
    FILE *f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %s %ld %ld %d %d \n",&elect.date.jour,&elect.date.mois, &elect.date.annee,elect.m,&elect.id,&elect.nb_habitant, &elect.nb_conseiller, &elect.statut)!=EOF)
        {
            if(elect.id==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        elect.id=-1;
    return elect;

}
