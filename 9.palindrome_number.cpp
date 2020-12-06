class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x < 10)
			return true;

		int *n = new int[10];

		memset(n, 0, sizeof(int) * 10);

		long ten = 10;

		long last = 0;

		int end_index = 0;

		for (int i = 0; ten / 10 <= x; ten *= 10, i++)
		{
			int current = (x % ten - last) / (ten / 10);
			last = x % ten;
			n[i] = current;
			if (current != 0)
				end_index = i;
		}
		for (int i = 0; i < (end_index + 1) / 2; i++)
		{
			int a = n[i];
			int b = n[end_index - i];
			if (a != b)
				return false;
		}

		return true;
	}
};
