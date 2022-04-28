#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int x = 0, y = 0;
	cin >> s;

	auto head = s.cbegin(), tail = s.cbegin() + 1;
	while (tail < s.cend())
	{

		if (*tail == ';') {
			if ((*head == 'W' || *head == 'A' || *head == 'S' || *head == 'D') && (tail - head > 1) && (tail - head < 4)) {
				int temp = 0;
				for (auto i = head + 1; i != tail; ++i)
					if ((*i >= '0') && (*i <= '9'))
						temp = temp * 10 + (*i - '0');
					else
					{
						temp = -1; break;
					}
				if (temp >= 0) {
					switch (*head)
					{
					case 'W':
						y += temp; break;
					case 'A':
						x -= temp; break;
					case 'S':
						y -= temp; break;
					case 'D':
						x += temp; break;
					default:
						cout << "something error" << endl;
						break;
					}
				}
				//cout << *head << temp << endl;
			}
			head = ++tail;
		}
		else
			++tail;
	}
	cout << x << ',' << y;
	return 0;
}