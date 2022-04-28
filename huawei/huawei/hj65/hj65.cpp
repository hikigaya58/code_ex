#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> temp(s1.size(), vector<int>(s2.size(), 0));
	int max = 0;
	for (int i = 0; i != s1.size(); ++i)
		if (s1[i] == s2[0])
		{
			temp[i][0] = 1;
			max = 1;
		}


	for (int i = 0; i != s2.size(); ++i)
		if (s2[i] == s1[0])
		{
			max = 1;
			temp[0][i] = 1;
		}

	for (int i = 1; i != s1.size(); ++i)
		for (int j = 1; j != s2.size(); ++j)
			if (s1[i] == s2[j])
			{
				temp[i][j] = temp[i - 1][j - 1] + 1;
				max = max > temp[i][j] ? max : temp[i][j];
			}
			else
				temp[i][j] = 0;

	cout << max;

	return 0;
}