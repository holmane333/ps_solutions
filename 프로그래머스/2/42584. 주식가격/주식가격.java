import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Deque<int[]> dq = new ArrayDeque<>();
        for (int i = 0; i < prices.length; ++i) {
            while (!dq.isEmpty() && dq.peekLast()[0] > prices[i]) {
                int[] p = dq.pollLast();
                answer[p[1]] = i - p[1];
            }
            dq.offer(new int[] {prices[i], i});
        }
        while (!dq.isEmpty()) {
            int[] p = dq.poll();
            answer[p[1]] = prices.length - 1 - p[1];
        }
        return answer;
    }
}