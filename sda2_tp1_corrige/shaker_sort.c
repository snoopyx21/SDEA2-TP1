/**
 * \file shaker_sort.c
 * \brief Shaker sort.
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
   * Akin to the bubble sort algorithm. Each iteration, move the biggest value
   * (respectively the lowest value) to the "end" (respectively to the "start")
   * of the array.
   */

  if (size == 0)
    return array;

  bool swapped = true;
  for (size_t end = size - 1, start = 0; swapped && end > start; --end, ++start)
  {
    swapped = false;
    /* Move the highest value. */
    for (size_t i = start; i < end; ++i)
      if (array[i] > array[i + 1])
      {
        array_swap_elements(array, i, i + 1);
        swapped = true;
      }
    /* Move the lowest value. */
    for (size_t i = end - 1; swapped && i > start; --i)
      if (array[i] < array[i - 1])
        array_swap_elements(array, i, i - 1);
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
