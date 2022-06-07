#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int left = 1, right = *max_element(piles.begin(), piles.end());

		auto calculateTime = [&](int speed) {
			int sum = 0;
			for (auto& pile : piles)
				sum += floor((pile + speed - 1) / speed);
			return sum;
		};

		while (left < right) {
			int mid = (left + right) >> 1;
			if (calculateTime(mid) > h)
				left = mid + 1;
			else
				right = mid;
		}

		return right;
	}
};