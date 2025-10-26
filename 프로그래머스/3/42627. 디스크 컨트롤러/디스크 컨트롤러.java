import java.util.*;

class Solution {
    class Pair implements Comparable<Pair> {
        Integer time;
        Integer req;
        Integer num;
        
        Pair(Integer t, Integer r, Integer n) {
            this.time = t;
            this.req = r;
            this.num = n;
        }
        
        @Override
        public int compareTo(Pair pair) {
            if (this.time == pair.time) {
                if (this.req == pair.req) {
                    return this.num.compareTo(pair.num);
                }
                return this.req.compareTo(pair.req);
            }
            return this.time.compareTo(pair.time);
        }
    }
    public int solution(int[][] jobs) {
        int answer = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        Arrays.sort(jobs, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0];
            }
        });
        
        int idx = 0, t = 0, c = 0;
        while (idx < jobs.length || !pq.isEmpty()) {
            while (idx < jobs.length && jobs[idx][0] <= t) {
                pq.offer(new Pair(jobs[idx][1], jobs[idx][0], idx));
                ++idx;
                c = 1;
            }
            if (!pq.isEmpty()) {
                Pair pair = pq.poll();
                t += pair.time;
                answer += t - pair.req;
                c = 1;
            }
            if (c == 0) {
                ++t;
            }
            c = 0;
        }
        return answer / jobs.length;
    }
}