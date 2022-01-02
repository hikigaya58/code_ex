#include <vector>
#include <deque>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> multiLevelVals;
        deque<TreeNode *> nodePath;
        if (root)
            nodePath.push_back(root);
        else
            return multiLevelVals;
        while (nodePath.size() > 0)
        {
            vector<int> levelVals;
            int len = nodePath.size();
            for (int i = 0; i != len; ++i)
            {
                auto tmp = nodePath[0];
                levelVals.push_back(tmp->val);
                if (tmp->left)
                    nodePath.push_back(tmp->left);
                if (tmp->right)
                    nodePath.push_back(tmp->right);
                nodePath.pop_front();
            }
            multiLevelVals.push_back(levelVals);
        }
        return multiLevelVals;
    }
};