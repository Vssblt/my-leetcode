/*
 * main.cpp
 * Copyright (C) 2022 vssblt <vssblt@vssblt-PC>
 *
 * Distributed under terms of the MIT license.
 */
#include "first-bad-version.h"
#include <iostream>
#include <string.h>
#include <vector>

int main(int argc, char *argv[]) {
  Solution s;
  int res = s.firstBadVersion(100);
  std::cout << res << std::endl;
  return 0;
}
