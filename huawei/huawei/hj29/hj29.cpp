#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	for (char& ch : s1)
		if (isalpha(ch))
			switch (isupper(ch) > 0)
			{
			case true:
				ch = 'a' + (ch - 'A' + 1) % 26;
				break;
			case false:
				ch = 'A' + (ch - 'a' + 1) % 26;
				break;
			default:
				cout << "something error" << endl;
				break;
			}
		else if (isdigit(ch))
			ch = '0' + (ch - '0' + 1) % 10;

	for (char& ch : s2)
		if (isalpha(ch))
			switch (isupper(ch) > 0)
			{
			case true:
				ch = 'a' + (ch - 'A' + 25) % 26;
				break;
			case false:
				ch = 'A' + (ch - 'a' + 25) % 26;
				break;
			default:
				cout << "something error" << endl;
				break;
			}
		else if (isdigit(ch))
			ch = '0' + (ch - '0' + 9) % 10;

	cout << s1 << endl << s2;

	return 0;

}