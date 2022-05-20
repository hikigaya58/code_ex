import java.util.Map;
import java.util.TreeMap;

class Solution {
    public int[] findRightInterval(int[][] intervals) {
        TreeMap<Integer, Integer> valIndexMap = new TreeMap<Integer, Integer>();
        for (int i = 0; i < intervals.length; ++i) {
            if (valIndexMap.containsKey(intervals[i][0]))
                continue;
            valIndexMap.put(intervals[i][0], i);
        }

        int[] answer = new int[intervals.length];
        for (int i = 0; i < intervals.length; ++i) {
            Map.Entry<Integer, Integer> it = valIndexMap.ceilingEntry(intervals[i][1]);
            if (it != null) {
                answer[i] = it.getValue();

                continue;
            }
            answer[i] = -1;
        }

        return answer;
    }
}