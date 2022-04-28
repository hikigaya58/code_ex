#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int max_len = 1;
	for (auto i = str.cbegin(); i != str.cend() - 1; ++i) {
		auto head = i, tail = i;
		while (head > str.cbegin() && tail < str.cend() - 1)
			if (*(head - 1) == *(tail + 1)) {
				--head; ++tail;
			}
			else
				break;
		max_len = tail - head + 1 > max_len ? tail - head + 1 : max_len;

		if (*i == *(i + 1)) {
			head = i; tail = i + 1;
			while (head > str.cbegin() && tail < str.cend() - 1)
				if (*(head - 1) == *(tail + 1)) {
					--head; ++tail;
				}
				else
					break;
			max_len = tail - head + 1 > max_len ? tail - head + 1 : max_len;
		}
	}
	cout << max_len;

	return 0;
}