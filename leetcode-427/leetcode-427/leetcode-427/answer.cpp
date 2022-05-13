#include<iostream>
#include<vector>
#include<memory>
#include <functional>

using namespace std;

class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {
		val = false;
		isLeaf = false;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
public:
	Node* construct(vector<vector<int>>& grid) {

		int n = grid.size();
		vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i != n + 1; ++i)
			for (int j = 1; j != n + 1; ++j)
				pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];

		auto getSum = [&](int r0, int r1, int c0, int c1) {
			return pre[r1][c1] - pre[r1][c0] - pre[r0][c1] + pre[r0][c0];
		};

		function<Node* (int, int, int, int)> dfs = [&](int r0, int r1, int c0, int c1) {
			int sum = getSum(r0, r1, c0, c1);
			if (sum == 0)
				return new Node(false, true);
			else if (sum == (r1 - r0) * (c1 - c0))
				return new Node(true, true);
			else
				return new Node(false, false, dfs(r0, (r0 + r1) / 2, c0, (c0 + c1) / 2),
					dfs(r0, (r0 + r1) / 2, (c0 + c1) / 2, c1),
					dfs((r0 + r1) / 2, r1, c0, (c0 + c1) / 2),
					dfs((r0 + r1) / 2, r1, (c0 + c1) / 2, c1));
		};

		return dfs(0, n, 0, n);
	}
};