#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j ++)
			{
				if (nums[i] + nums[j] == target)
				{
					vector<int> a;		
					a.push_back(i);
					a.push_back(j);
					return a;
				}
			}
		}
		return vector<int>();
		
	}
};
