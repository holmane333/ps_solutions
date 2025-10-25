import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        HashSet<Integer> hs = new HashSet<>();
        for (int num: nums) {
            hs.add(num);
        }
        answer = Math.min(nums.length / 2, hs.size());
        return answer;
    }
}