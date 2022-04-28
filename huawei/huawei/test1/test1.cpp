#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int num_hours; cin >> num_hours;
	int num_supermarkets; cin >> num_supermarkets;
	vector<vector<int>> tmp;
	for (int i = 0; i != num_supermarkets; ++i) {
		int a,b,c;
		cin >> a >> b >> c;
		tmp.push_back(vector<int>{a, b, c});
	}

	int cost = 0;
	for (int i = 1; i < num_hours+1; ++i) {
		int min = 1001;
		/*for (auto& supermarket : tmp) {
			if (i >= supermarket[0] && i <= supermarket[1] && min > supermarket[2])
				min = supermarket[2];
		}*/
		for (auto j = tmp.begin(); j < tmp.end(); ) {
			if (i > (*j)[1]) {
				j = tmp.erase(j);
			}
			else if (i >= (*j)[0] && min > (*j)[2]) {
				min = (*j)[2];
				++j;
			}
			else
			{
				++j;
			}
			//cout << j - tmp.begin();
		}
		cost += min;
	}

	cout << cost;

	return 0;
}