class Solution {
public:
	int myAtoi(string s) {                                              
		s = find_int(s);
		if (s.length() == 0)
			return 0;
		if (s.length() == 1 && (s[0] == '+' || s[0] == '-'))
			return 0;
		if (s.length() >= 12)
		{
			if (s[0] == '-')
				return INT32_MIN;
			else 
				return INT32_MAX;
		}
		long l = stoll(s);
		if (l >= INT32_MAX)
			return INT32_MAX;
		if (l <= INT32_MIN)
			return INT32_MIN;
		return (int)l;
	}                                                                   

	string find_int(string s)
	{
                char sign = '+';                                         
                if (s.length() == 0)                                     
                        return string("");                               
                int start_index = -1;                                    
                int end_index = -1;                                      
                char c = 0;                                              
                for (int i = 0; i < s.length(); i++)                     
		{
			if (s[i] == ' ')
			{
				continue;
			} else {
                                start_index = i;           
                                break;                     
                        }                                  
                }                                          
                if (start_index == -1)                     
                        return string("");                 
                else                                       
			s = s.substr(start_index, s.length() - start_index);
		start_index = -1;
		if (s.length() == 0)
			return string("");
		if (s.length() == 1 && (s[0] == '+' || s[0] == '-'))
			return string("");
		if (s[0] == '+' || s[0] == '-')
		{
			sign = s[0];
			s = s.substr(1, s.length() - 1);
		}
                for (int i = 0; i < s.length(); i++)                     
		{
			if (s[i] == '0')
			{
				continue;
			} else {
                                start_index = i;           
                                break;                     
                        }                                  
                }                                          
                if (start_index == -1)                     
                        return string("");                 
                else                                       
			s = s.substr(start_index, s.length() - start_index);
		start_index = -1;
		for (int i = 0; i < s.length(); i++)
		{
			c = s[i];
			if (!(c <= 0x39 && c >=0x30))
			{
				break;
			}
			if (start_index == -1)
			{
				start_index = i;
				end_index = i;
			} else {
				end_index = i;
			}
		}
		if (start_index == -1)
			return string("");
		else 
			return sign + s.substr(start_index, end_index - start_index + 1);
	}
};                                                             
