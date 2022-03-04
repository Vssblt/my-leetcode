/*
 * regular-expression-matching.cpp
 * Copyright (C) 2022 vssblt <vssblt@vssblt-PC>
 *
 * Distributed under terms of the MIT license.
 */

#include "regular-expression-matching.h"
#include <iostream>
#include <string.h>

bool Solution::isMatch(std::string s, std::string p) {
  if (p.size() == 0)
    return !s.size();
  bool first_match = s.size() > 0 && (p[0] == '.' || p[0] == s[0]);
  if (p.size() >= 2 && p[1] == '*') {
    return this->isMatch(s, p.substr(2)) ||
           first_match && this->isMatch(s.substr(1), p);
  }
  if (first_match)
    return this->isMatch(s.substr(1), p.substr(1));
  return false;
}
