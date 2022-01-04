class Solution:
    def longestPalindrome(self, s: str) -> str:
        leng, head, tail = 0, 0, 0
        for i in range(len(s)):
            j, k = i, i
            while j-1 >= 0 and k+1 < len(s) and s[j-1] == s[k+1]:
                j -= 1
                k += 1
            if k-j > leng:
                leng = k-j
                head = j
                tail = k
            if i+1 < len(s) and s[i] == s[i+1]:
                j, k = i, i+1
                while j-1 >= 0 and k+1 < len(s) and s[j-1] == s[k+1]:
                    j -= 1
                    k += 1
                if k-j > leng:
                    leng = k-j
                    head = j
                    tail = k
        return s[head:tail+1]
