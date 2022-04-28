#include<iostream>

using namespace std;

int main()
{
	float h;
	cin >> h;

	float l = h;
	for (int i = 1; i != 5; ++i) {
		l += h;
		h /= 2;
	}

	cout << fixed << l << endl << h / 2;

	return 0;
}