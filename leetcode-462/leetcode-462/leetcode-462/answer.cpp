#include<vector>
#include<random>
#include<ctime>
#include<cmath>

using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		default_random_engine e(time(0));
		int head = 0, tail = nums.size() - 1, midNum = 0;

		while (true) {

			uniform_int_distribution<int> u(head, tail);

			int tmp = u(e);
			swap(nums[head], nums[tmp]);
			int pivot = nums[head];

			while (head < tail) {
				while (head < tail && nums[tail] >= pivot) --tail;
				nums[head] = nums[tail];
				while (head < tail && nums[head] <= pivot) ++head;
				nums[tail] = nums[head];
			}
			nums[head] = pivot;

			if (head == floor(nums.size() / 2)) {
				midNum = pivot; break;
			}
			else if (head < floor(nums.size() / 2)) {
				head += 1;
				tail = nums.size() - 1;
				continue;
			}
			else if (head > floor(nums.size() / 2)) {
				head = 0;
				tail -= 1;
				continue;
			}
		}

		int count = 0;
		for (auto& a : nums)
			count += abs(a - midNum);

		return count;
	}
};