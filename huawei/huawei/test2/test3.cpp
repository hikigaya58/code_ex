#include<iostream>
#include<vector>

using namespace std;

int select(vector<vector<int>> remains, vector<int> vres, vector<int>& v);

int main()
{
	int num_project; cin >> num_project;
	int a, b, c; cin >> a >> b >> c;
	vector<int> groups{ a,b,c };
	vector<int> vs;
	for (int i = 0; i != num_project; ++i) {
		int j; cin >> j;
		vs.push_back(j);
	}
	vector<vector<int>> pro_num;
	for (int i = 0; i != num_project; ++i) {
		cin >> a >> b >> c;
		pro_num.push_back(vector<int>{a, b, c});
	}
	cout << select(pro_num,groups,vs);

	/*vector<int> m(groups[0]/10+1, 0);
	vector<vector<int>> n(groups[1] / 10+1, m);
	vector<vector<vector<int>>> dp(groups[2] / 10+1, n);

	for (int i = 0; i <= groups[0]; i += 10) {
		for (int j = 0; j <= groups[1]; j += 10) {
			for (int k = 0; k <= groups[2]; k += 10) {
				int max = 0;
				for (auto z = pro_num.begin(); z != pro_num.end(); ++z) {
					if (i >= (*z)[0] && j >= (*z)[1] && k >= (*z)[2])
						max = max > dp[(i - (*z)[0]) / 10][(j - (*z)[1]) / 10][(k - (*z)[2]) / 10] + vs[z - pro_num.begin()] ?
						max : dp[(i - (*z)[0]) / 10][(j - (*z)[1]) / 10][(k - (*z)[2]) / 10] + vs[z - pro_num.begin()];
				}
				dp[i/10][j/10][k/10] = max;
			}
		}
	}

	cout << dp[groups[0] / 10][groups[1] / 10][groups[2] / 10];*/

	return 0;
}

int select(vector<vector<int>> remains, vector<int> vres,vector<int>& v)
{
	bool flag = false;
	for (auto i = remains.begin(); i != remains.end(); ) {
		if (vres[0] >= (*i)[0] && vres[1] >= (*i)[1] && vres[2] >= (*i)[2]) {
			flag = true;
			int n = i - remains.begin();
			i = remains.erase(i);
			return v[n]+select(vector<vector<int>>(remains), vector<int>{vres[0] - (*i)[0], vres[1] - (*i)[1], vres[2] - (*i)[2]}, v);
		}
		else
		{
			++i;
		}
	
	}
	if (!flag) {
		return 0;
	}
}