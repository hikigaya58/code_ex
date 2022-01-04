#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string::difference_type len = 0;
        string::iterator head = s.begin(), tail = s.begin();
        for (auto i = s.begin(); i != s.end(); ++i)
        {
            auto j = i, k = i;
            while (j - 1 >= s.begin() && k + 1 < s.end() && *(j - 1) == *(k + 1))
            {
                --j;
                ++k;
            }
            if (len < k - j)
            {
                len = k - j;
                head = j;
                tail = k;
            }
            if (i + 1 < s.end() && *i == *(i + 1))
            {
                j = i;
                k = i + 1;
                while (j - 1 >= s.begin() && k + 1 < s.end() && *(j - 1) == *(k + 1))
                {
                    --j;
                    ++k;
                }
                if (len < k - j)
                {
                    len = k - j;
                    head = j;
                    tail = k;
                }
            }
        }
        return s.substr(head - s.begin(), len + 1);
    }
};