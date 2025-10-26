import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int sco: scoville) {
            pq.offer(Long.valueOf(sco));
        }
        
        int c = 0;
        
        while (!pq.isEmpty()) {
            if (pq.peek() >= K) {
                c = 1;
                break;
            }
            if (pq.size() <= 1) break;
            Long a = pq.poll();
            Long b = pq.poll();
            pq.offer(a + b * 2);
            ++answer;
        }
        
        if (c == 0) answer = -1;
        return answer;
    }
}