#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool oneEditAway(string first, string second) {

		auto m = first.size();
		vector<int> pre(m + 1, 0), curr(m + 1, 0);
		for (int i = 0; i != curr.size(); ++i) {
			curr[i] = i;
		}

		for (int i = 1; i <= second.size(); ++i) {
			pre[0] = i;
			swap(curr, pre);

			for (int j = 1; j <= first.size(); ++j)
				if (second[i - 1] == first[j - 1])
					curr[j] = pre[j - 1];
				else
					curr[j] = min({ curr[j - 1], pre[j], pre[j - 1] }) + 1;
		}

		return curr.back() < 2;
	}
};