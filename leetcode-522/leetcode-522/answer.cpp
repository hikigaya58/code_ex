#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		sort(strs.begin(), strs.end(), [](string a, string b) {return a.size() > b.size(); });

		auto is_substr = [](string l, string r) {
			size_t p_l = 0, p_r = 0;
			while (p_l < l.size() && p_r < r.size()) {
				if (l[p_l] == r[p_r])
					++p_r;
				++p_l;
			}
			return p_r == r.size();
		};

		for (size_t i = 0; i != strs.size(); ++i) {
			auto flag = true;
			for (size_t j = 0; j != strs.size(); ++j) {
				if (i == j)
					continue;
				if (strs[i].size() > strs[j].size())
					break;
				if (is_substr(strs[j], strs[i])) {
					flag = false;
					break;
				}
			}
			if (flag)
				return strs[i].size();
		}

		return -1;
	}
};