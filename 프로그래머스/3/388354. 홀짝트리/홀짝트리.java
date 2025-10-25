import java.util.*;

class Solution {
    public int[] solution(int[] nodes, int[][] edges) {
        int[] answer = {0, 0};
        int maxNode = 1000000;
        int[] v = new int[maxNode + 10];
        int[] check = new int[maxNode + 10];
        int[][] cnt = new int[maxNode + 10][2];
        
        ArrayList<Integer>[] e = new ArrayList[maxNode + 10];
        for (int i = 0; i < maxNode + 10; ++i) e[i] = new ArrayList<>();
        
        for (int[] edge: edges) {
            e[edge[0]].add(edge[1]);
            e[edge[1]].add(edge[0]);
        }
        
        int t = 1;
        for (int node: nodes) {
            if (v[node] != 0) continue;
            v[node] = t++;
            Queue<Integer> q = new LinkedList<>();
            q.offer(node);
            while (!q.isEmpty()) {
                int nd = q.poll();
                if ((nd % 2 == 0 && e[nd].size() % 2 == 0) || (nd % 2 == 1 && e[nd].size() % 2 == 1)) check[nd] = 0;
                else check[nd] = 1;
                cnt[v[node]][check[nd]]++;
                for (Integer i: e[nd]) {
                    if (v[i] != 0) continue;
                    v[i] = v[node];
                    q.offer(i);
                }
            }
        }
        
        for (int node: nodes) {
            int cnt1 = 0;
            if (check[node] == 0) cnt1 -= 1;
            else cnt1 += 1;
            if (cnt[v[node]][0] + cnt1 == 0) answer[0]++;
            if (cnt[v[node]][1] - cnt1 == 0) answer[1]++;
        }
        
        return answer;
    }
}