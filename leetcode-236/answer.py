

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left: TreeNode
        self.right: TreeNode


class Solution:

    answer: TreeNode

    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        self.dfsSearch(root, p, q)
        return self.answer

    def dfsSearch(self, root: TreeNode, p: TreeNode, q: TreeNode) -> bool:
        if not root:
            return False
        current: bool = root.val == q.val or root.val == p.val
        left: bool = self.dfsSearch(root.left, p, q)
        right: bool = self.dfsSearch(root.right, p, q)
        if (left and right) or (current and left) or (current and right):
            self.answer = root
        return current or left or right
