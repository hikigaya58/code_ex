class Solution {
    public int findKthNumber(int m, int n, int k) {
        int left = 0, right = m * n;
        while (left < right) {
            int mid = left + Math.floorDiv(right - left, 2);
            int loc = Math.floorDiv(mid, n) * n;
            for (int i = Math.floorDiv(mid, n) + 1; i <= m; ++i)
                loc += Math.floorDiv(mid, i);
            if (loc >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }
}