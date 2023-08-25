/**
 * \file bubble_sort.c
 * \brief Bubble sort.
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

#include "array.h"

////////////////////////////////////////////////////////////////////////////////
// Your implementation.
////////////////////////////////////////////////////////////////////////////////

long int* custom_sort(size_t size, long int* const array)
{
  /*
   * Algorithm
   * =========
   *
   * Each iteration (outermost loop), move the biggest value to the "end" of the
   * array.
   *
   * #1: biggest value moved to position `size-1`
   *     > end = size-1
   *     >> i starts at 0; i < end => i <= size-2
   *     >> last swap: if a[i] > a[i+1] then swap(i=size-2, i+1=size-1)
   * #2: 2nd biggest value moved to position `size-2`.
   *     > end = size-2
   *     >> last swap: if a[i] > a[i+1] then swap(i=size-3, i+1 = size-2)
   * #end: and so on...
   * #last step: end = 1, i = 0, if a[0] > a[1] then swap(i=0, i+1=1)
   */

  /*
   * Most naive implementation:
   *
   *   for (size_t end = size - 1; end > 0; --end)
   *     for (size_t i = 0; i < end; ++i)
   *       if (array[i] > array[i+1])
   *         array_swap_elements(array, i, i+1);
   *   return array;
   */
  if (size == 0)
    return array;

  bool swapped = true;
  /* Stop if no value was swapped, move the "end" as values are swapped.  */
  for (size_t end = size - 1; swapped && end > 0; --end)
  {
    swapped = false;
    /* Move the highest value to the "end". */
    for (size_t i = 0; i < end; ++i)
      if (array[i] > array[i + 1])
      {
        array_swap_elements(array, i, i + 1);
        swapped = true;
      }
  }
  return array;

}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "bubble_sort()";
}

