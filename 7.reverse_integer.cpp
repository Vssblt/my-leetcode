class Solution {
public:
	int reverse(int x) {
		if (x == 0)
			return 0;

		string ret_s;

		int sign = 0;
		if (x < 0)
		{
			sign = 0;
			ret_s = "-";
		} else {
			sign = 1;
		}
		int y = abs(x);
		long num = 1;
		long last = 0;
		int ret[10] = {0};
		memset(ret, 0, sizeof(int) * 10);
		int index = 0;
		int index_a = -1;
		for (int i = 0; i < 10; i++)
		{
			num *= 10;
			ret[i] = (y % num - last) / (num / 10);
			last = y % num;
			if (ret[i] != 0 && index_a == -1)
			{
                                index_a = i;            
                        }                               
                        if (ret[i] != 0)                              
                                index = i;                            
                }                                                     
                for (int i = index_a; i < index + 1; i++)             
                {                                                     
                        ret_s += std::to_string(ret[i]);              
                }                                                     

		long long l = stoll(ret_s);
		if (l > 2147483648 || l < -2147483648)
			return 0;

                return (int)l;
        }                                                             
};                                                             
