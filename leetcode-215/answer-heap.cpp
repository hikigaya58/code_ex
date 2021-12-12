#include <vector>

using namespace std;

class Solution
{
public:
    void makeMinHeap(vector<int> &_nums, int _start, int _end)
    {
        for (int i = _end / 2; i > 0; --i)
            adjustDown(_nums, i, _end);
    }

    void adjustDown(vector<int> &_nums, int _start, int _end)
    {
        _nums[0] = _nums[_start];
        for (int i = 2 * _start; i <= _end; i *= 2)
        {
            if (i < _end && _nums[i] > _nums[i + 1])
                ++i;
            if (_nums[i] >= _nums[0])
                break;
            else
            {
                _nums[_start] = _nums[i];
                _start = i;
            }
        }
        _nums[_start] = _nums[0];
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        nums.insert(nums.begin(), 0);
        makeMinHeap(nums, 1, k);
        for (int i = k + 1; i != nums.size(); ++i)
            if (nums[i] > nums[1])
            {
                nums[1] = nums[i];
                adjustDown(nums, 1, k);
            }
        return nums[1];
    }
};