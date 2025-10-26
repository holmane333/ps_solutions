import java.util.*;

class Solution {
    class Pair {
        int weight;
        int time;
        Pair(int w, int t) {
            this.weight = w;
            this.time = t;
        }
    }
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 1;
        int cnt = 0;
        Queue<Pair> q = new LinkedList<>();
        for (int truck: truck_weights) {
            while (!q.isEmpty() && (q.size() >= bridge_length || cnt + truck > weight)) {
                Pair passed = q.poll();
                answer = Math.max(answer, passed.time);
                cnt -= passed.weight;
            }
            q.offer(new Pair(truck, answer + bridge_length));
            cnt += truck;
            answer++;
        }
        
        while (!q.isEmpty()) {
            Pair passed = q.poll();
            answer = passed.time;
        }
        return answer;
    }
}