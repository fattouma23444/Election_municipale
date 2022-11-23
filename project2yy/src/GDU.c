#include "GDU.h"

int ajouter(char * filename, GDU s )
{ 
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,s.jour,s.mois,s.annee,s.Gender,s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,s.vote,s.NumBV);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, GDU nouv )
{ 
    int tr=0;
    GDU s;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
            if(s.N_CIN == id)
            {
                fprintf(f2,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",nouv.Nom,nouv.Prenom,nouv.jour,nouv.mois,nouv.annee,nouv.Gender,nouv.N_CIN,nouv.Id,nouv.Pass,nouv.TypeUtilisateur,nouv.vote,nouv.NumBV);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,s.jour,s.mois,s.annee,s.Gender,s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,s.vote,s.NumBV);

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
    GDU s;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
            if(s.N_CIN== id)
                tr=1;
            else
                fprintf(f2,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,s.jour,s.mois,s.annee,s.Gender,s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,s.vote,s.NumBV);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
GDU chercher(char * filename, int id)
{
    GDU s;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
            if(s.N_CIN== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        s.N_CIN=-1;
    return s;

}
float agemoyen(char * filename)
{
    GDU s;
    float am=0;
    int am2=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
	    if ( strcmp(s.TypeUtilisateur,"Electeur") == 0 && s.vote != -1 )
		{
            		am+= 2022-s.annee;
	   		am2++;
		} 
        }
    }
    fclose(f);
    return am/am2;

}


int TPHF( char * filename, int * f, int *h)
{
    GDU s;
    int nbvts = 0;
    FILE * ff=fopen(filename, "r");
    if(ff!=NULL)
    {
        while(fscanf(ff,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
	    if (strcmp(s.TypeUtilisateur,"Electeur") == 0 && s.vote != -1)
		{
			nbvts++;
			if (s.Gender == 'M')
				(*h)++;
			else
				(*f)++;
		}
        }
    }
    fclose(ff);
    return nbvts;
}


float TPE( char * filename)
{
    GDU s;
    int nbrelecv = 0,elec = 0;
    FILE * ff=fopen(filename, "r");
    if(ff!=NULL)
    {
        while(fscanf(ff,"%s %s %d/%d/%d %c %d %s %s %s %d %d\n",s.Nom,s.Prenom,&s.jour,&s.mois,&s.annee,&s.Gender,&s.N_CIN,s.Id,s.Pass,s.TypeUtilisateur,&s.vote,&s.NumBV)!=EOF)
        {
	    if (strcmp(s.TypeUtilisateur,"Electeur") == 0 && s.vote != -1)
		{
			nbrelecv++;
		}
	    if 	(strcmp(s.TypeUtilisateur,"Electeur") == 0)
			elec++;
        }
    }
    fclose(ff);
    return (float)nbrelecv/elec;
}







