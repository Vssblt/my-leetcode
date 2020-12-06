class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size = nums1.size() + nums2.size();
		if (size == 0)
			return 0;

		int n1 = 0, n2 = 0;
		vector<int> nums;
		for (int i = 0; i < nums1.size() + nums2.size(); i++)
		{

			int val1 = 2147483647;
			int val2 = 2147483647;
			if (n1 != nums1.size())
			{
				val1 = nums1[n1];
			}
			if (n2 != nums2.size())
			{
				val2 = nums2[n2];
			}

			if (val1 < val2)
			{
				nums.push_back(val1);

				if (n1 != nums1.size())
					n1++;
			} else {
				nums.push_back(val2);

				if (n2 != nums2.size())
					n2++;
			}
		}

		int m1, m2;
		if (size % 2 != 1)
		{
			m1 = size / 2 - 1;
			m2 = m1 + 1;
		} else {
			m1 = size / 2;
			m2 = m1;
		}
		if (size == 1)
		{
			m1 = 0;
			m2 = 0;
		}

		return (nums[m1] + nums[m2]) / 2.0;

	}
};
