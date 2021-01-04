#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.length() == 0 && p.length() == 0)
			return true;
		if (s.length() != 0 && p.length() == 0)
			return false;
		if (s.length() == 0 && p.length() == 2)
		{
			if (p[1] == '*')
				return true;
			else 
				return false;
		}

		char last_char = 0;
		char next_char = 0;

		vector <char> str;
		
		vector <char> pv;

		init(str, pv, s, p);

		int i = 0;
                int j = 0;                                               
                                                                         
                while (i + j < str.size() + pv.size())                   
                {                                                        
			if (pv.size() - 1 < j)
			{
                                next_char = pv[j + 1];                   
                        }                                                
                                                                         
                        if (pv.size() == j && str.size() != i)           
                               return false;                             
                                                                         
                        if (str.size() == i && pv.size() == j)           
                        {                                                
                                return true;                             
                        } else if (str.size() == i && pv.size() != j) {  
                                if (next_char == '*' && j == pv.size() - 1)
                                        return true;                     
                                else                                     
                                        return false;                    
			}
                                                                         
                        int ret = check(str[i], pv[j], last_char, next_char);
                        if (!ret) {                                      
                                return false;                            
                        } else if (ret == 1) {                           
				i++;
			} else if (ret == 2) {
				j++;
			} else if (ret == 3) {
                                i++;                              
                                j++;                              
                        }                                         
                                                                  
                }                                                 
                return true;                                      
        }                                                         
                                                                  
	void init(vector<char> &str, vector<char> &pv, string s, string p)
	{
		for (auto c : s)
		{
			str.push_back(c);
		}
		for (auto c : p)
		{
			pv.push_back(c);
		}
	}

	int check(char c, char pc, char &lc, char nc)
	{
		if (c == pc)
		{
			lc = pc;
			return 3;
		}

		if (pc == '.')
		{
			lc = pc;
			return 3;
		}

		if (pc == '*')
		{
			if (lc == c)
				return 1;
			if (lc == '.')
				return 1;
			if (lc != c)
			{
				lc = pc;
				return 2;
			}
		}

		if (c != pc)
		{
			if (nc == '*')
			{
				lc = pc;
				return 2;
			}
			return 0;
		}
		return 0;
	}
};
