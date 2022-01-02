# better answer from others

from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        multiLevelVals: List[List[int]] = []
        if root:
            nodePath: List[TreeNode] = [root]
        else:
            return multiLevelVals
        while len(nodePath):
            levelVals: List[int] = []
            for i in range(len(nodePath)):  # remember level node number
                tmp = nodePath[0]
                levelVals.append(tmp.val)
                if tmp.left:
                    nodePath.append(tmp.left)
                if tmp.right:
                    nodePath.append(tmp.right)
                nodePath.pop(0)
            multiLevelVals.append(levelVals)
        return multiLevelVals
