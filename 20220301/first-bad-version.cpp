/*
 * first-bad-version.cpp
 * Copyright (C) 2022 vssblt <vssblt@vssblt-PC>
 *
 * Distributed under terms of the MIT license.
 */

#include "first-bad-version.h"

int Solution::firstBadVersion(int n) { return this->search(0, n); }

bool Solution::isBadVersion(int n) { return true; }

int Solution::search(int begin, int end) {
  int mid = (end - begin) / 2 + begin;
  if (end - begin == 1) {
    int res = isBadVersion(begin);
    if (res == false)
      return begin;
    res = isBadVersion(end);
    if (res == false)
      return end;
  }
  if (isBadVersion(mid)) {
    end = mid;
    return this->search(begin, end);
  } else {
    begin = mid;
    return this->search(begin, end);
  }
}
