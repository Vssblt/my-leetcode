class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<char> str, tmp;
		int ret = 0;
		for (int i = 0; i < s.length(); i++)
		{
			tmp.clear();
			int repeat = -1;
			char c = s[i];
			for (int j = 0; j < str.size(); j ++)
			{
				if (str[j] == c)
				{
					repeat = j;
					break;
				}
			}
			if (repeat != -1)
			{
				for (int j = repeat + 1; j < str.size(); j++)
				{
					tmp.push_back(str[j]);
				}
				str = tmp;
			}
			str.push_back(c);
			if (str.size() > ret)
				ret = str.size();

		}
		return ret;
	}
};
