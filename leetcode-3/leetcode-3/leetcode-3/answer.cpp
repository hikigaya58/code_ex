#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
			return 0;

		int head = 0, ans = 1;
		unordered_map<char, int> lastIndex;

		for (int i = 0; i != s.size(); ++i) {
			char curr = s[i];
			if (lastIndex.count(curr) == 0 || lastIndex[curr] < head) {
				lastIndex[curr] = i;
				ans = ans > i - head + 1 ? ans : i - head + 1;
			}
			else if (lastIndex[curr] >= head) {
				//ans = ans > i - head ? ans : i - head;
				head = lastIndex[curr] + 1;
				lastIndex[curr] = i;
			}
		}

		return ans;
	}
};