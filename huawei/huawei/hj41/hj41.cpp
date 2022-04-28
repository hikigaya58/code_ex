#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
	int types;
	cin >> types;

	vector<int> weights;
	for (int i = 0; i != types; ++i) {
		int weight;
		cin >> weight;
		weights.push_back(weight);
	}
	vector<int> all_weights;
	for (int i = 0; i != types; ++i) {
		int num;
		cin >> num;
		for (int j = 0; j != num; ++j) {
			all_weights.push_back(weights[i]);
		}
	}

	set<int> no_dup{0};
	for (auto& i : all_weights) {
		auto tmp = no_dup;
		for (auto& j : tmp) {
			no_dup.insert(i + j);
		}
	}

	cout << no_dup.size();

	return 0;
}