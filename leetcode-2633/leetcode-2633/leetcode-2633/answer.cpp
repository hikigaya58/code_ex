#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	int findClosest(vector<string>& words, string word1, string word2) {
		int index1 = -1, index2 = -1, minLen = words.size();

		for (int i = 0; i != words.size(); ++i)
			if (words[i] == word1) {
				index1 = i;
				minLen = index2 > 0 ? min(minLen,abs(index2 - index1)) : minLen;
			}
			else if (words[i] == word2) {
				index2 = i;
				minLen = index1 > 0 ? min(minLen, abs(index2 - index1)) : minLen;
			}

		return minLen;
	}
};