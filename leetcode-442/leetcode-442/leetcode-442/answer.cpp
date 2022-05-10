#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> answer;

		for (auto& num : nums) {
			int i = abs(num) - 1;
			if (nums[i] < 0)
				answer.push_back(i + 1);
			else
				nums[i] = -nums[i];
		}

		return answer;
	}
};