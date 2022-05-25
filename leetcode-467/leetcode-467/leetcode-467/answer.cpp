#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		unordered_map<char, int> charToMaxLenMap;

		int tmpLen = 1;
		charToMaxLenMap.insert({ p.front(), tmpLen });
		for (auto it = p.cbegin() + 1; it != p.cend(); ++it) {
			if ((*it - *(it - 1) + 26) % 26 == 1)
				++tmpLen;
			else
				tmpLen = 1;

			if (charToMaxLenMap.count(*it) == 0)
				charToMaxLenMap.insert({ *it, tmpLen });
			else
				charToMaxLenMap[*it] = max(charToMaxLenMap[*it], tmpLen);
		}

		int ans = 0;
		for (auto& i : charToMaxLenMap)
			ans += i.second;

		return ans;
	}
};