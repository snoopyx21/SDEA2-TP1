#include <stdio.h>

extern contact CVIDE;

typedef struct noeud {
   contact c;
   struct noeud *pre;
   struct noeud *succ;
} *carnet;

carnet adj(carnet ca, contact p){
   carnet n = (carnet) malloc(sizeof(struct noeud));
   n->c=p;
   n->succ=ca;
   n->pre=NULL;
   ca->pre=n;
   return n;
}

contact rechercher(carnet ca, char nom []){
   carnet x = rech(ca, nom);
   if (x==NULL) return CVIDE;
   return x->c;
}

carnet rech(carnet ca, char nom []){
   carnet s = ca;
   while(s!=NULL){
       if (strcmp(nom,s->c.nom) == 0)
           return s;
       s=s->succ;
   }
   return NULL;
}

carnet supprimer(carnet c, char nom []){
   carnet x=rech(c,nom);
   if (x==NULL) return c;
   if (x->pre != NULL) x->pre->succ=x->succ;
   if (x->succ != NULL) x->succ->pre=x->pre;
   if ((x->pre == NULL) && (x->succ==NULL)){
       free(x);
       return NULL;
   }
   if (x->pre == NULL){
       c=x->succ;
       free(x);
       return c;
   }
}
