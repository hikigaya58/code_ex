#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> strList;
	string s;
	while (cin >> s)
		strList.push_back(s);

	for (auto i = strList.cbegin(); i != strList.cend(); ++i) {
		if (i->size() <= 8) {
			cout << "NG" << endl;
			continue;
		}

		int flag_upper = 0, flag_lower = 0, flag_num = 0, flag_other = 0;
		for (auto j = i->cbegin(); j != i->cend(); ++j) {
			if ((*j >= 'A') && (*j <= 'Z'))
				flag_upper = 1;
			else if ((*j >= 'a') && (*j <= 'z'))
				flag_lower = 1;
			else if ((*j >= '0') && (*j <= '9'))
				flag_num = 1;
			else if (flag_other == 0)
				flag_other = 1;
		}
		if (flag_lower + flag_upper + flag_num + flag_other < 3) {
			cout << "NG" << endl;
			continue;
		}

		bool flag_dup = false;
		for (auto j = i->cbegin(); j < (i->cend()) - 2; ++j) {
			auto temp = string(j, j + 3);
			for (auto k = j + 3; k < (i->cend()) - 2; ++k)
				if (temp == string(k, k + 3)) {
					flag_dup = true;
					break;
				}
			if (flag_dup)
				break;
		}
		if (flag_dup) {
			cout << "NG" << endl;
			continue;
		}

		cout << "OK" << endl;
	}

	return 0;
}