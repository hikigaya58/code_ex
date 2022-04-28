#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

int main()
{
	string key, text;
	cin >> key >> text;

	vector<bool> alphabet(26, false);
	for (auto i = key.begin(); i != key.end();) {
		if (!alphabet[toupper(*i) - 'A']) {
			alphabet[toupper(*i) - 'A'] = true;
			++i;
		}
		else
		{
			i = key.erase(i);//?
		}
	}
	for (auto i = alphabet.cbegin(); i != alphabet.cend(); ++i) {
		if (!(*i))
			key += ('A' + (i - alphabet.cbegin()));
	}

	string ciphertext;
	for (auto i = text.cbegin(); i != text.cend(); ++i) {
		ciphertext.push_back(isupper(*i) ? toupper(key[(*i)-'A']) : tolower(key[(*i) - 'a']));
	}

	cout << ciphertext;

	return 0;
}