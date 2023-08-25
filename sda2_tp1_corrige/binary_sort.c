/**
 * \file binary_sort.c
 * \brief Binary sort.
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

#include <string.h>
#include "array.h"

////////////////////////////////////////////////////////////////////////////////
// Your implementation.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Search the correct place for a value using binary search.
 * \param[in] array Input array.
 * \param[in] value Considered value.
 * \param[in] a Lower boundary of the range.
 * \param[in] b Upper boundary of the range.
 */
static size_t binary_search(
        const long int* array, long int value, size_t a, size_t b)
{
  /*
   * Algorithm
   * =========
   *
   * 1. Determine a middle value ((a+b)/2).
   * 2. a >= b: in case of a recursive call binary_search(..., a=i+1, b)
   *    ==> in the parent call, a == b, i.e. one cell remaining in the
   *    range
   *    OR the very first time, a=0, b=0.
   * 3. If the value is bigger (respectively lower) than the value
   *    at the middle, search in the right (respectively left) part of
   *    the array.
   * 4. Otherwise, array[i] == value, i is a valid place.
   */

  const size_t i = (a + b) / 2;

  if (a >= b)
    return b;
  else if (array[i] < value)
    return binary_search(array, value, i+1, b);
  else if (array[i] > value)
    return binary_search(array, value, a, i);
  else
    return i;
}

long int* custom_sort(size_t size, long int* const array)
{
  /*
   * Algorithm
   * =========
   * 1. Assume the i-1 cells are already sorted
   *    => find the right place in the range [0, i[.
   * 2. Once the place is found, existing values must be shifted to
   *    free the target place: i-place values must be shifted.
   */
  for (size_t i = 0; i < size; ++i)
  {
    const size_t place = binary_search(array, array[i], 0, i);
    const size_t move = i - place;
    const long int value = array[i];

    memmove(array + place + 1, array + place, move * sizeof *array);
    array[place] = value;
  }

  return array;
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "binary_sort()";
}
