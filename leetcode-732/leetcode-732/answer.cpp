#include<unordered_map>

using namespace std;

class MyCalendarThree {
public:
	MyCalendarThree() {

	}

	int book(int start, int end) {
		update(start, end - 1, 0, 1e9, 1);
		return partMax[1];
	}

	void update(int start, int end, int left, int right, int idx) {
		if (start > right || end < left)
			return;
		if (start <= left && end >= right) {
			++partMax[idx];
			++spanMax[idx];
		}
		else {
			int mid = (left + right) >> 1;
			update(start, end, left, mid, idx << 1);
			update(start, end, mid + 1, right, idx << 1 | 1);
			partMax[idx] = spanMax[idx] + max(partMax[idx << 1], partMax[idx << 1 | 1]);
		}
	}

private:
	unordered_map<int, int> partMax;
	unordered_map<int, int> spanMax;
};