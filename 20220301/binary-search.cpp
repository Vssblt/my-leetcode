/*
 * binary-search.cpp
 * Copyright (C) 2022 vssblt <vssblt@vssblt-PC>
 *
 * Distributed under terms of the MIT license.
 */

#include "binary-search.h"
#include <algorithm>
int Solution::search(std::vector<int> &nums, int target) {
  int size = nums.size();
  int mid = size / 2;
  if (mid == 0) {
    for (int i = 0; i < nums.size(); i++) {
      if (target == nums[i]) {
        return 0;
      }
    }
    return -1;
  }
  if (target > nums[mid]) {
    std::vector<int> back;
    for (int i = mid; i < nums.size(); i++) {
      back.push_back(nums[i]);
    }
    int res = this->search(back, target);
    if (res == -1) {
      return -1;
    } else {
      return mid + res;
    }
  } else if (target < nums[mid]) {
    std::vector<int> front;
    for (int i = 0; i < mid; i++) {
      front.push_back(nums[i]);
    }
    int res = this->search(front, target);
    if (res == -1) {
      return -1;
    } else {
      return res;
    }

  } else {
    return mid;
  }
}
