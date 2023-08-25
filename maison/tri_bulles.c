// fichier tri_a_bulle.c
#include <stdio.h>
#define TRUE 1
#define FALSE 0

void tri_bulle(int *tab,int n)
{
   int i=0;
   int tmp=0;
   int en_desordre=0;
   while(en_desordre)
   {
       en_desordre=FALSE;
       for(i=0;i<n-1;i++)
       {
           if(tab[i] > t[i+])
           {
               tmp=t[i+1];
               t[i+1]=t[i];
               t[i]=tmp;
               en_desordre=TRUE;
           }
       }
   }
}
