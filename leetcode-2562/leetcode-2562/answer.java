class Solution {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if (p.right != null) {
            TreeNode ans = p.right;
            while (ans.left != null)
                ans = ans.left;
            return ans;
        } else {
            TreeNode curr = root, ans = null;
            while (curr != null)
                if (curr.val > p.val) {
                    ans = curr;
                    curr = curr.left;
                } else
                    curr = curr.right;
            return ans;
        }
    }
}