#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> answer;
        if (nums.begin() == nums.end())
            return answer; //for input like []
        sort(nums.begin(), nums.end());
        auto i = nums.begin();
        while (i < nums.begin() + (nums.size() - 2)) //nums.end() cann't be operate, make this complex,don't use iterator?
        {
            auto j = i + 1, k = nums.begin() + (nums.size() - 1);
            while (j < k)
            {
                int sum = *i + *j + *k;
                if (sum == 0)
                {
                    answer.push_back(vector<int>{*i, *j, *k}); //anonymous variable?
                    while (j + 1 < k && *j == *(j + 1))
                        ++j;
                    ++j;
                    while (k - 1 > j && *k == *(k - 1))
                        --k;
                    --k;
                }
                else if (sum < 0)
                {
                    while (j + 1 < k && *j == *(j + 1))
                        ++j;
                    ++j;
                }
                else if (sum > 0)
                {
                    while (k - 1 > j && *k == *(k - 1))
                        --k;
                    --k;
                }
            }
            while (i + 2 < nums.end() && *i == *(i + 1))
                ++i;
            ++i;
        }
        return answer;
    }
};