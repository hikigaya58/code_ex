from typing import List
from random import randrange


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        self.quickSelect(nums, 0, len(nums)-1, k)
        return nums[k-1]

    def partition(self, _nums: List[int], _left: int, _right: int) -> int:
        randomInt = randrange(_left, _right+1)
        pivot = _nums[randomInt]
        _nums[randomInt] = _nums[_left]
        _nums[_left] = pivot
        while(_left < _right):
            while(_left < _right and _nums[_right] <= pivot):
                _right -= 1
            _nums[_left] = _nums[_right]
            while(_left < _right and _nums[_left] >= pivot):
                _left += 1
            _nums[_right] = _nums[_left]
        _nums[_left] = pivot
        return _left

    def quickSelect(self, _nums: List[int], _left: int, _right: int, index: int) -> None:
        n = self.partition(_nums, _left, _right)
        if n < index-1:
            self.quickSelect(_nums, n+1, _right, index)
        elif n > index-1:
            self.quickSelect(_nums, _left, n-1, index)
