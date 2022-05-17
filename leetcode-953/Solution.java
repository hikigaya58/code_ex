import java.util.HashMap;
import java.util.Map;
import java.util.function.BiFunction;

class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> alphabetMap = new HashMap<Character, Integer>();
        for (int i = 0; i < order.length(); ++i)
            alphabetMap.putIfAbsent(order.charAt(i), i);

        BiFunction<String, String, Boolean> isEqualOrUpper = (String lhs, String rhs) -> {
            for (int i = 0, j = 0; i < lhs.length() && j < rhs.length(); ++i, ++j)
                if (alphabetMap.get(lhs.charAt(i)) < alphabetMap.get(rhs.charAt(j)))
                    return true;
                else if (alphabetMap.get(lhs.charAt(i)) > alphabetMap.get(rhs.charAt(j)))
                    return false;

            if (lhs.length() <= rhs.length())
                return true;
            else
                return false;
        };

        for (int i = 1; i < words.length; ++i)
            if (!isEqualOrUpper.apply(words[i - 1], words[i]))
                return false;
        return true;
    }
}