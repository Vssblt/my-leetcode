class Solution {
public:
	string convert(string s, int numRows) {
		string ret = "";
		string *temp_str = new string[numRows];
		if (numRows == 1 || s.length() == 0)
			return s;
		int *f = new int[s.length()];
		memset(f, 0, sizeof(int) * s.length());
		int flag = 0;
		int index = 0;
		for (int i = 0; i < s.length(); i++)
		{
			f[i] = index;
			if (index + 1 == numRows)
			{
				flag = 1;
                        } else if (index == 0) {                            
                                flag = 0;                                   
                        }                                                   
                        if (flag == 1)                                      
                        {                                                   
                                index--;                                    
                        } else {                                            
                                index++;                      
                        }                                     
                }                                             
                                                              
                int n = -1;                                   
                for (int i = 0; i < s.length(); i++)          
                {                                                           
                        temp_str[f[i]] += s[i];                             
                                                                            
                }                                                           
                for (int i = 0; i < numRows; i++)                           
                {                                                           
                        ret += temp_str[i];                                 
		}
		delete[] f;
		delete[] temp_str;
		return ret;
	}

private:
};

