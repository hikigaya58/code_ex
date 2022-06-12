#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		auto match = [](string& word, string& pattern) -> bool {
			unordered_map<char, char> letterMap;
			unordered_set<char> usedLetter;
			for (auto it1 = word.cbegin(), it2 = pattern.cbegin(); it1 != word.cend(); ++it1, ++it2) {
				if (letterMap.count(*it1) == 0)
					if (usedLetter.count(*it2) == 0)
					{
						letterMap[*it1] = *it2;
						usedLetter.insert(*it2);
					}
					else
						return false;
				else
					if (letterMap[*it1] != *it2)
						return false;

			}
			return true;
		};

		vector<string> ans;
		for (auto& word : words) {
			if (match(word, pattern))
				ans.push_back(word);
		}

		return ans;
	}
};