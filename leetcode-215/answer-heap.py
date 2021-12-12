from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.insert(0, 0)  # for later index convient
        self.makeMinHeap(nums, k)
        for i in range(k+1, len(nums)):
            if nums[i] > nums[1]:
                nums[1] = nums[i]
                self.adjustDown(nums, 1, k)
        return nums[1]

    def makeMinHeap(self, _nums: List[int], k: int) -> None:
        for i in range(k//2, 0, -1):
            self.adjustDown(_nums, i, k)

    def adjustDown(self, _nums: List[int], _start: int, _end: int) -> None:
        _nums[0] = _nums[_start]
        loc = _start * 2
        while loc <= _end:  # '=' is neccessary, considerd the situation only two elements and the first is great than the second
            while loc < _end and _nums[loc] > _nums[loc+1]:
                loc += 1
            if _nums[0] <= _nums[loc]:
                break
            else:
                _nums[_start] = _nums[loc]
                _start = loc
                loc *= 2
        _nums[_start] = _nums[0]
