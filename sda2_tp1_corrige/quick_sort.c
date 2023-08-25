/**
 * \file quick_sort.c
 * \brief Quick sort.
 * \date 2017
 * \author Harenome Ranaivoarivony-Razanajato
 * \copyright WTFPLv2
 */

/*
 * Copyright © 2017 YOU <you@etu.unistra.fr>
 *
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar.
 *
 * See http://www.wtfpl.net/ or read below for more details.
 */
/*
 * DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
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

/**
 * \brief Partition a part of an array and return the pivot's place.
 * \param[in,out] array Input array.
 * \param[in]     start Lower bound of the part to partition.
 * \param[in]     end   Upper bound of the part to partition.
 * \return Place of the pivot.
 */
size_t partition(long int* const array, size_t start, size_t end)
{
  /*
   * Algorithm
   * ---------
   * 1. Choose a pivot (various ways to do so, here we always choose the end).
   * 2. Move it to the end. Swap the elements, don't shift the whole array!
   * 3. Keep in memory the index of the "swapping" place (initialized with the
   *    start of the array).
   * 4. If the current value is smaller than the pivot swap it with the value
   *    at the "swapping" place and increment the index of the "swapping" place.
   * 5. At the end move the pivot to the "swapping" place.
   *    => values lower than pivot were moved in places before the swapping
   *       place, values higher than the pivot were moved after the swapping
   *       place.
   */
  const size_t pivot = end;
  const long int pivot_value = array[pivot];
  size_t swap_place = start;

  array_swap_elements(array, pivot, end);
  for (size_t i = start; i < end; ++i)
    if (array[i] <= pivot_value)
    {
      array_swap_elements(array, swap_place, i);
      swap_place++;
    }
  array_swap_elements(array, swap_place, end);
  return swap_place;
}

void quick_sort(long int* const array, size_t start, size_t end)
{
  /*
   * Algorithm
   * =========
   *
   * 1. Choose a pivot and move lower values to its left and higher values to
   *    its right (see partition()).
   * 2. Recurse on the left and right parts.
   */
  if (start >= end)
    return;

  size_t p = partition(array, start, end);
  quick_sort(array, start, p >= 1 ? p - 1 : 0);
  quick_sort(array, p + 1, end);
}

long int* custom_sort(size_t size, long int* const array)
{
  if (size != 0)
    quick_sort(array, 0, size - 1);
  return array;
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "quick_sort()";
}
