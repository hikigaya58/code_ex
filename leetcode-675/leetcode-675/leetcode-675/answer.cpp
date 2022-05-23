#include<vector>
#include<unordered_set>
#include<deque>
#include<tuple>
#include<algorithm>
#include<utility>

using namespace std;

class Solution {
public:
	int cutOffTree(vector<vector<int>>& forest) {

		int m = forest.size();
		int n = forest[0].size();

		auto shortestPathLength = [&forest,&m,&n](int x_s, int y_s, int x_d, int y_d) -> int {

			deque<tuple<int, int, int>> qu{ {x_s, y_s, 0} };
			vector<vector<bool>> visited(m, vector<bool>(n, false));
			visited[x_s][y_s] = true;

			while (!qu.empty()) {
				tuple<int, int, int> tmp = qu.front();
				qu.pop_front();
				int x = get<0>(tmp), y = get<1>(tmp), step = get<2>(tmp);
				if (x == x_d && y == y_d)
					return step;

				vector<pair<int, int>> around{ {x - 1,y},{x,y - 1},{x + 1,y},{x,y + 1} };
				for (auto i = around.cbegin(); i < around.cend(); ++i) {
					auto& xx = i->first;
					auto& yy = i->second;
					if (xx >= 0 && xx < m && yy >= 0 && yy < n && visited[xx][yy] == false && forest[xx][yy] != 0)
					{
						visited[xx][yy] = true;
						qu.emplace_back(xx, yy, step + 1);
					}
				}
			}
			return -1;
		};

		vector<pair<int, int>> nodes;
		for (int i = 0; i != m; ++i)
			for (int j = 0; j != n; ++j) {
				if (forest[i][j] > 1) {
					nodes.emplace_back(i, j);
				}
			}
		sort(nodes.begin(), nodes.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {return forest[a.first][a.second] < forest[b.first][b.second]; });

		auto pre = make_pair(0, 0);
		int ans = 0;
		for (auto i = nodes.begin(); i < nodes.end(); ++i) {
			int d = shortestPathLength(pre.first, pre.second, i->first, i->second);
			if (d < 0)
				return -1;
			ans += d;
			pre = *i;
		}

		return ans;
	}
};