#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>

using namespace std;


bool checkBrother(string s1, string s2)
{
	vector<int> test(26, 0);
	for (auto i = s1.cbegin(), j = s2.cbegin(); i != s1.cend() && j != s2.cend(); ++i, ++j) {
		++test[tolower(*i) - 'a'];
		--test[tolower(*j) - 'a'];
	}
	for (auto& i : test)
		if (i != 0)
			return false;

	return true;
}

int main()
{
	int num; cin >> num;

	vector<string> dict;
	for (int i = 0; i != num; ++i) {
		string s; cin >> s;
		dict.push_back(s);
	}

	string word; cin >> word;

	int idx; cin >> idx;

	vector<string> words;
	for (auto& i : dict) {
		if ((i.size() == word.size()) && (i != word) && checkBrother(i, word))
			words.push_back(i);
	}

	cout << words.size() << endl;

	sort(words.begin(), words.end());
	if (words.size() >= idx)
		cout << words[idx - 1] << endl;

	return 0;
}