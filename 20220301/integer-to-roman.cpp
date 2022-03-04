/*
 * integer-to-roman.cpp
 * Copyright (C) 2022 vssblt <vssblt@vssblt-PC>
 *
 * Distributed under terms of the MIT license.
 */

#include "integer-to-roman.h"
#include <iostream>
#include <vector>
std::string Solution::intToRoman(int num) {
  std::vector<int> vector{1000, 500, 100, 50, 10, 5, 1};
  std::vector<int> count{0, 0, 0, 0, 0, 0, 0};
  std::vector<char> string{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
  std::string output = "";
  int last = 0;
  for (int i = 0; i < 7; i++) {
    num -= last;
    count[i] = num / vector[i];
    last = count[i] * vector[i];
  }
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < count[i]; j++) {
      output += string[i];
    }
  }
  std::cout << output << std::endl;
  return output;
}
