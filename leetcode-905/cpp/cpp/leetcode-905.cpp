#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		if (nums.size() == 0) return nums;

		auto head = nums.begin(), tail = nums.end() - 1;
		while (head < tail)
		{
			while (*head % 2 == 0 && head < tail) ++head;
			while (*tail % 2 == 1 && head < tail) --tail;
			int tmp = *head;
			*head = *tail;
			*tail = tmp;
		}

		return nums;
	}
};