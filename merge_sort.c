/**
 * \file merge_sort.c
 * \brief Merge sort.
 * \date 2017
 * \author YOU
 * \copyright WTFPLv2
 */

/* Copyright © 2017 YOU <you@etu.unistra.fr>
 *
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar.
 *
 * See http://www.wtfpl.net/ or read below for more details.
 */
/* DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 */
#include "custom_sort.h"

#include "array.h"

////////////////////////////////////////////////////////////////////////////////
// Your implementation.
////////////////////////////////////////////////////////////////////////////////
void fusion(long int* const t,int deb1, size_t fin1, size_t fin2){
    
   long int* table1; 
   size_t deb2=fin1+1; 
   size_t compt1=deb1; 
   size_t compt2=deb2; 
   size_t i;
   table1=(int*)malloc((fin1-deb1+1)*sizeof(int)); 
   for(i=deb1;i<=fin1;i++)
       table1[i-deb1]=t[i]; 
   for(i=deb1;i<=fin2;i++){
       if(compt1==deb2)
           break;
       else if (compt2==(fin2+1)){
           t[i]=table1[compt1-deb1];
            compt1++;
       } 
       else if (table1[compt1-deb1]<t[compt2]){
           t[i]=table1[compt1-deb1];
           compt1++;
       } 
       else{
           t[i]=t[compt2];
           compt2++;
       }
   }
   free(table1);
}


void tri_fusion(long int* const t,size_t debut, size_t fin){
   if(debut != fin){
       size_t milieu=(fin+debut)/2;
       tri_fusion2(t,debut,milieu);
       tri_fusion2(t,milieu+1,fin);
       fusion(t,debut,milieu,fin);
       }
}
void tri_fusion2(long int* const t,int n){
   if(n>0) tri_fusion(t,0,n-1);
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "merge_sort()";
}
