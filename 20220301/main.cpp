/*
 * main.cpp
 * Copyright (C) 2022 vssblt <vssblt@vssblt-PC>
 *
 * Distributed under terms of the MIT license.
 */
#include "search-insert-position.h"
#include <iostream>
#include <string.h>
#include <vector>

int main(int argc, char *argv[]) {
  Solution s;
  std::vector<int> in = {1};
  int res = s.searchInsert(in, 0);
  std::cout << res << std::endl;
  return 0;
}
