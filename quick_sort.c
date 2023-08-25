/**
 * \file quick_sort.c
 * \brief Quick sort.
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
void echanger(long int* const t, size_t i,size_t j){ 
   size_t tmp;
   tmp=t[i];
   t[i]=t[j];
   t[j]=tmp;
}

size_t partition(long int* const t, size_t deb,size_t fin){ 
   size_t compt=deb; 
   size_t pivot=t[deb]; 
   size_t i; 
   for(i=deb+1;i<=fin;i++){ 
       if (t[i] < pivot){
           compt++;
           echanger(t,compt,i);
       }
   }
   echanger(t,compt,deb); 
   return (compt);
}

void tri_rapide_bis(long int* const t,size_t debut,size_t fin){ 
   if (debut < fin){ 
       int pivot=partition(t,debut,fin);
       tri_rapide_bis(t,debut,pivot-1);
       tri_rapide_bis(t,pivot+1,fin);
   }
}

void tri_rapide(long int* const t,size_t n){
   tri_rapide_bis(t,0,n-1);
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "quick_sort()";
}
