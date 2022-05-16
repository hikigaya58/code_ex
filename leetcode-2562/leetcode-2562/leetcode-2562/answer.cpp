#include<vector>
#include<string>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (p->right) {
			auto ans = p->right;
			while (ans->left)
				ans = ans->left;
			return ans;
		}
		else {
			auto curr = root;
			TreeNode* ans = nullptr;
			while (curr)
				if (curr->val > p->val) {
					ans = curr;
					curr = curr->left;
				}
				else
					curr = curr->right;
			return ans;
		}
	}
};