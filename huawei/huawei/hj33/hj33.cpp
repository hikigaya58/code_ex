#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	unsigned long d = 0;
	s1.push_back('.');
	for (auto i = s1.cbegin(), temp = s1.cbegin(); i != s1.cend(); ++i)
		if (*i == '.') {
			d += stoul(string(temp, i));
			if (i + 1 != s1.cend()) {
				d <<= 8;
				temp = i + 1;
			}
		}
	cout << d << endl;

	d = stoul(s2);
	s1.clear();
	for (int i = 0; i != 4; ++i) {
		s1 = to_string(d & 255) + '.' + s1;
		d >>= 8;
	}
	s1.pop_back();
	cout << s1;

	return 0;
}