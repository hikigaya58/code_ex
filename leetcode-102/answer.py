# self work out answer, recursion, not very efficient
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        path: List[List[int]] = []
        if root:
            self.levelTravel([root], path)
        return path

    def levelTravel(self, levelNodes: List[TreeNode], path: List[List[int]]) -> None:
        if not len(levelNodes):
            return
        vals: List[int] = []
        nextLevelNodes: List[TreeNode] = []
        for node in levelNodes:
            vals.append(node.val)
            if node.left:
                nextLevelNodes.append(node.left)
            if node.right:
                nextLevelNodes.append(node.right)
        path.append(vals)
        self.levelTravel(nextLevelNodes, path)
