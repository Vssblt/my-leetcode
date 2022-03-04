/*
 * container-with-most-water.cpp
 * Copyright (C) 2022 vssblt <vssblt@vssblt-PC>
 *
 * Distributed under terms of the MIT license.
 */

#include "container-with-most-water.h"
#include <vector>

int Solution::maxArea(std::vector<int> &h) {
  int max = 0;
  int i = 0;
  int j = h.size() - 1;
  while (true) {
    if (i == j) {
      break;
    }
    int temp = 0;
    if (h[i] > h[j]) {
      temp = h[j] * (j - i);
      j--;
    } else {
      temp = h[i] * (j - i);
      i++;
    }
    if (temp > max)
      max = temp;
  }
  return max;
}
