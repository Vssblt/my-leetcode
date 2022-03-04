/*
 * search-insert-position.cpp
 * Copyright (C) 2022 vssblt <vssblt@vssblt-A35R>
 *
 * Distributed under terms of the MIT license.
 */

#include "search-insert-position.h"

int Solution::searchInsert(std::vector<int> &nums, int target) {
  if (nums.size() < 2) {
    if (target > nums[0]) {
      return 1;
    } else {
      return 0;
    }
  }
  int mid = 0;
  int size = nums.size();
  mid = size / 2;
  std::vector<int> back, front;
  if (target > nums[mid]) {
    for (int i = mid; i < nums.size(); i++) {
      back.push_back(nums[i]);
    }
    return mid + this->searchInsert(back, target);
  } else {
    for (int i = 0; i < mid; i++) {
      front.push_back(nums[i]);
    }
    return this->searchInsert(front, target);
  }
}
