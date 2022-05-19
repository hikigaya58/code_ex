import java.util.concurrent.ThreadLocalRandom;

class Solution {
    public int minMoves2(int[] nums) {
        int head = 0, tail = nums.length - 1, midNum = 0;

        while (true) {
            int rand = ThreadLocalRandom.current().nextInt(head, tail + 1);
            int pivot = nums[rand];
            nums[rand] = nums[head];
            nums[head] = pivot;

            while (head < tail) {
                while (head < tail && nums[tail] >= pivot)
                    --tail;
                nums[head] = nums[tail];
                while (head < tail && nums[head] <= pivot)
                    ++head;
                nums[tail] = nums[head];
            }
            nums[head] = pivot;
            if (head == Math.floorDiv(nums.length, 2)) {
                midNum = pivot;
                break;
            } else if (head > Math.floorDiv(nums.length, 2)) {
                head = 0;
                tail -= 1;
            } else if (head < Math.floorDiv(nums.length, 2)) {
                head += 1;
                tail = nums.length - 1;
            }
        }

        int count = 0;
        for (int i : nums)
            count += Math.abs(i - midNum);

        return count;
    }
}