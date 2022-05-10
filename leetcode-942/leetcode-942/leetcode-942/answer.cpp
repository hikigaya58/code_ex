#include<iostream>
#include<string>
#include<vector>
#include<deque>

using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string s) {
		deque<int> index_sorted{ 0 };

		for (int i = 1; i != s.size() + 1; ++i) {
			s[i - 1] == 'I' ? index_sorted.push_back(i) : index_sorted.push_front(i);
		}

		vector<int> tmp(s.size() + 1, 0);
		for (auto i = index_sorted.cbegin(); i != index_sorted.cend(); ++i) {
			tmp[*i] = i - index_sorted.cbegin();
		}

		return tmp;
	}
};