from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer: List[List[int]] = []
        nums.sort()
        i: int = 0
        while i < len(nums) - 2:
            j, k = i+1, len(nums)-1
            while(j < k):
                sum: int = nums[i]+nums[j]+nums[k]
                if sum == 0:
                    answer.append([nums[i], nums[j], nums[k]])
                    while(j+1 < k and nums[j] == nums[j+1]):
                        j += 1
                    j += 1
                    while(k-1 > j and nums[k] == nums[k-1]):
                        k -= 1
                    k -= 1
                elif sum < 0:
                    while(j+1 < k and nums[j] == nums[j+1]):
                        j += 1
                    j += 1
                elif sum > 0:
                    while(k-1 > j and nums[k] == nums[k-1]):
                        k -= 1
                    k -= 1
            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            i += 1
        return answer
