#include <vector>
#include <random>

using namespace std;

class Solution
{
    int partition(vector<int> &_nums, int _left, int _right)
    {
        static default_random_engine e;
        uniform_int_distribution<int> u(_left, _right); //should not be static here
        int rand = u(e);
        int pivot = _nums[rand];
        _nums[rand] = _nums[_left];
        _nums[_left] = pivot;
        while (_left < _right)
        {
            while (_left < _right && _nums[_right] <= pivot)
                --_right;
            _nums[_left] = _nums[_right];
            while (_left < _right && _nums[_left] >= pivot)
                ++_left;
            _nums[_right] = _nums[_left];
        }
        _nums[_left] = pivot;
        return _left;
    }

    void quickSelect(vector<int> &_nums, int _left, int _right, int index)
    {
        int n = partition(_nums, _left, _right);
        if (n > index - 1)
            quickSelect(_nums, _left, n - 1, index);
        else if (n < index - 1)
            quickSelect(_nums, n + 1, _right, index);
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        quickSelect(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
};
