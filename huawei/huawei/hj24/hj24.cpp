#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int len; vector<int> seq;
	cin >> len;
	for (int i = 0; i != len; ++i) {
		int b; cin >> b;
		seq.push_back(b);
	}

	vector<int> left(len, 1), right(len, 1);
	for (int i = 0; i != len; ++i) {
		int temp = 0;
		for (int j = 0; j != i; ++j)
			if (seq[j] < seq[i] && left[j] > temp)
				temp = left[j];
		left[i] = temp + 1;
	}

	for (int i = len - 1; i > 0; --i) {
		int temp = 0;
		for (int j = len - 1; j != i; --j)
			if (seq[i] > seq[j] && right[j] > temp)
				temp = right[j];
		right[i] = temp + 1;
	}

	int temp = 0;
	for (int i = 0; i != len; ++i)
		if (left[i] + right[i] > temp)
			temp = left[i] + right[i];

	cout << len - temp + 1;

	return 0;
}