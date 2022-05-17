#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		unordered_map<char, int> alphabetMap;
		for (int i = 0; i != order.size(); ++i)
			alphabetMap.insert({ order[i], i });

		auto isEqualOrUpper = [&](string& lhs, string& rhs) -> bool {
			for (int i = 0, j = 0; i != lhs.size() && j != rhs.size(); ++i, ++j)
				if (alphabetMap[lhs[i]] < alphabetMap[rhs[i]])
					return true;
				else if (alphabetMap[lhs[i]] > alphabetMap[rhs[i]])
					return false;

			if (lhs.size() <= rhs.size())
				return true;
			else
				return false;
		};

		for (auto i = words.begin() + 1; i != words.end(); ++i)
			if (!isEqualOrUpper(*(i - 1), *i))
				return false;

		return true;
	}
};