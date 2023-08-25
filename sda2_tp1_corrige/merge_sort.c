/**
 * \file merge_sort.c
 * \brief Merge sort.
 * \date 2017
 * \author Harenome Ranaivoarivony-Razanajato
 * \copyright WTFPLv2
 */

/*
 * Copyright © 2017 Harenome Ranaivoarivony-Razanajato <hrazanajato@unistra.fr>
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

/**
 * \brief Merge sort a part of an array.
 * \param[în] src  Source array.
 * \param[in] tmp  Temporary array.
 * \param[in] size Size of the part to sort.
 * \return The resulting array.
 */
static long int* merge_sort(
    long int* const src, long int* const tmp, size_t size)
{
  /*
   * Algorithm
   * =========
   *
   * 1. Copy the input array into two smaller (size/2 (+1)) arrays.
   * 2. Recursively sort the aforementioned subarrays.
   * 3. Merge the two sorted arrays.
   */

  if (size >= 2)
  {
    const size_t middle = size / 2;
    /* These sizes will be used to sort only subparts of the array. */
    const size_t left_size = middle;
    const size_t right_size = size - middle;

    /* Sort the left hand array. */
    long int* left = tmp;
    array_copy_elements(src, left, left_size);
    left = merge_sort(left, src, left_size);

    /* Sort the right hand part of the array. */
    long int* right = tmp + left_size;
    array_copy_elements(src + left_size, right, right_size);
    right = merge_sort(right, src + left_size, right_size);

    /*
     * We need to choose where the new value must be picked until one of the
     * arrays is empty (li >= left_size || ri >= right_size).
     */
    size_t i = 0, li = 0, ri = 0;
    for (i = 0; li < left_size && ri < right_size; ++i)
      tmp[i] = left[li] < right[ri] ? left[li++] : right[ri++];

    /*
     * Once one of the arrays is empty, it is unnecessary to choose.
     * (Only one loop will be executed, since either li >= left_size or
     * ri >= right_size).
     */
    for ( ; li < left_size; ++i, ++li)
      tmp[i] = left[li];
    for ( ; ri < right_size; ++i, ++ri)
      tmp[i] = right[ri];

  }
  else
    array_copy_elements(src, tmp, size);

  return tmp;
}


long int* custom_sort(size_t size, long int* const array)
{
  long int* const tmp = malloc(size * sizeof *tmp);
  long int* const result = merge_sort(array, tmp, size);

  free(tmp == result ? array : result);
  return result;
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "merge_sort()";
}
