#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<char> tmp;
	for (int i = 0; i != 26; ++i)
		for (auto j = str.cbegin(); j != str.cend(); ++j)
			if (isalpha(*j) && (toupper(*j) - 'A' == i))
				tmp.push_back(*j);

	auto i = tmp.cbegin();
	for (auto j = str.begin(); i != tmp.cend() && j != str.end(); ++j)
		if (isalpha(*j))
			*j = *(i++);

	cout << str;

	return 0;
}