#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BV.h"
int main()
{ int x, choix, N ;
 float t;
 
BV b1={23456,"ARIANNA SOGHRA","1500",10,3,1,"1234AG"},
   b2 ={32456,"TUNIS","3000",30,5,1,"1456AG"},
   b3={87689,"MANOUBA","900",10,3,1,"1235AG"},b4;
do 
{ 
  do   
    { printf(" 1.ajouter un bureau du vote \n");
      printf (" 2.modifier un bureau du  vote \n ");
      printf ("3.supprimer un bureau du vote \n ");
      printf ("4. chercher un bureau du vote \n ");
      printf ("5. taux de participation des electeurs \n ");
      printf ("6. nombre des electeurs par bureau de vote \n ");
      printf ("0.quitter \n");
      scanf("%d",&choix);

     }
  while (choix <0 || choix>6);
 switch (choix )
{ case 1 :
          x=ajouter("BV.txt",b2);
          if(x==1)
          	printf("\n ajout d'un nouveau bureau du vote avec succés !\n");
          else printf ("\n echec ajout ");
          break ;
case 2:
         x=modifier ("BV.txt",b2,23456);
         if (x==1)
         	printf ("\n modification d'un bureau du votes avec succés !\n");
         else printf ("\n echec modification ");
         break;
case 3:
 x=supprimer("BV.txt",32456);
        if(x==1)
             printf("\n suppression d' un bureau du votes avec succés !\n");
        else printf ("\n echec suppression ");
        break;

case 4:

       b4=chercher("BV.txt",1234);
       if(b4.NumBV==-1)
        printf("introuvable !");
        else printf("%d\n",b4.NumBV);

       break;
case 5:

     t=TPE("user.txt");
     printf("taux de participation des electeurs : %f %% \n ",t*100);
     break ;
case 6:

      N=NBE("user.txt", 23456);
      printf ("nombre des electeurs par bureau de vote : %d \n", N );
      break;
}
}
while (choix !=0);
       
return 0;
}
