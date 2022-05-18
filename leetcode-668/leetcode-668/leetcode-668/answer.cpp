#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int left = 0, right = m * n;
		while (left < right)
		{
			auto mid = left + (right - left) / 2;
			int loc = floor(mid / n) * n;
			for (auto i = floor(mid / n) + 1; i <= m; ++i)
				loc += floor(mid / i);
			if (loc >= k)
				right = mid;
			else
				left = mid + 1;
		}
		return right;
	}
};

/*
理解：
 1. 由于left与right都是整数，所以当循环结束时left == right。即最后return left 与 return right 等价
 2. 基于1，我们只考虑right。right总是大于等于乘法表中我们要找的answer
 3. 结合https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/solution/guan-fang-ti-jie-yu-zi-ji-de-yi-wen-java-nxu8/，
 不存在大于answer还能使count == k - 1 的数
 4. 所以最后right总是等于answer
*/