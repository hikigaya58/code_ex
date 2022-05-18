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
��⣺
 1. ����left��right�������������Ե�ѭ������ʱleft == right�������return left �� return right �ȼ�
 2. ����1������ֻ����right��right���Ǵ��ڵ��ڳ˷���������Ҫ�ҵ�answer
 3. ���https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/solution/guan-fang-ti-jie-yu-zi-ji-de-yi-wen-java-nxu8/��
 �����ڴ���answer����ʹcount == k - 1 ����
 4. �������right���ǵ���answer
*/