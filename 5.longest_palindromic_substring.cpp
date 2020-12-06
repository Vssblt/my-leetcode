#ifndef COMMON_H
#define COMMON_H 
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;


class Solution {
public:
	Solution() : map_(nullptr), length_(0), s_(""), index_i_(0), index_j_(0), max_(1) {}
	~Solution() { this->clear(); }

	string longestPalindrome(string s) {
		if (s.length() == 0)
			return string("");

		this->clear();
		this->init(s);
		this->fill();

		return s.substr(this->index_j_, this->index_i_ - this->index_j_ + 1);
	}

	void clear() 
	{ 
		for (int i = 0; i < this->length_; i++)
		{
			if (*(this->map_) != nullptr) 
				delete[] this->map_[i]; 
		}
		if (this->map_ != nullptr)
			delete[] this->map_;
		this->map_ = nullptr; 
		this->s_.clear();
		this->index_i_ = 0;
		this->index_j_ = 0;
		this->max_ = 1;
		this->length_ = 0;
	}

	void init(const string &str) {
		this->s_ = str;
		this->length_ = this->s_.length();
		this->map_ = new int *[this->length_];

		for (int i = 0; i < this->length_ - 1; i++)
		{
			this->map_[i] = new int[this->length_];
			memset(this->map_[i], 0, this->length_ * sizeof(int));
			this->map_[i][i] = 1;
			if (this->s_[i] == this->s_[i + 1])
			{
				this->map_[i][i + 1] = 1;
				this->index_i_ = i + 1;
				this->index_j_ = i;
				this->max_ = 2;
			}
		}
		this->map_[this->length_ - 1] = new int[this->length_];
		memset(this->map_[this->length_ - 1], 0, this->length_ * sizeof(int));
		this->map_[this->length_ - 1][this->length_ - 1] = 1;
	}

	void fill()
	{
		for (int i = 1; i < this->length_; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (this->s_[i] == this->s_[j] 
						&& this->map_[j + 1][i - 1])
				{
					this->map_[j][i] = 1;
					abs(j - i) + 1 > this->max_ ? 
						this->index_i_ = i, this->index_j_ = j, this->max_ = abs(j - i) + 1: 0;
				}
			}	
		}	
	}

private:
	unsigned int length_;
	int **map_;
	string s_;
	int max_;
	int index_i_;
	int index_j_;
};

#endif
