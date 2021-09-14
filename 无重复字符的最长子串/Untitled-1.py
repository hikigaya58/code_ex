def len_bewteen_index(head, tail):  # 计算以相应index为头尾的子串的长度
    return tail - head + 1


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        head, maxSubStrLen, index_dict = 0, 0, {}  # index_dict记忆每个字符最近一次出现的index
        for i, c in enumerate(s):
            if c in index_dict and head <= index_dict[c]:
                head = index_dict[c] + 1  # 当发现一对重复字符后，直接跳到前一个字符的后一个字符处
                index_dict[c] = i
            else:
                index_dict[c] = i
                maxSubStrLen = max(maxSubStrLen, len_bewteen_index(head, i))
        return maxSubStrLen


solution = Solution()
print(solution.lengthOfLongestSubstring(""))
