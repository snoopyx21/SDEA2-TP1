/**
 * \file shaker_sort.c
 * \brief Shaker sort.
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

long int* custom_sort(size_t size, long int* const array)
{
  size_t i;
  long k=1;
  size_t b=size-1;
  long tmp =0;
  size_t a=0 ;
  while(k > 0 || a<b){
    k=0;
    for(i=a ; i<b ; i++){
      if (array[i] > array[i+1]){
        tmp=array[i];
        array[i]=array[i+1];
        array[i+1]=tmp;
        k++;
      }
    }
    if (k > 0){
      k=0;
      for(i=b ; i>a ; i--){
        if (array[i] < array[i-1]){
          tmp=array[i];
          array[i]=array[i-1];
          array[i-1]=tmp;
          k++;
        }
      }
    }
    a++;
  }
  return array;
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "shaker_sort()";
}
