import java.util.*;

class Solution {
    public int solution(int[][] maps) {
        int answer = 0;
        int n = maps.length, m = maps[0].length;
        int[][] v = new int[n][m];
        
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0});
        v[0][0] = 1;
        
        int[] dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        
        while (!q.isEmpty()) {
            int[] pos = q.poll();
            int x = pos[0], y = pos[1];
            
            for (int i = 0; i < 4; ++i)  {
                int cx = x + dx[i], cy = y + dy[i];
                if (cx < 0 || cx >= n || cy < 0 || cy >=m || maps[cx][cy] == 0 || v[cx][cy] != 0) continue;
                v[cx][cy] = v[x][y] + 1;
                q.offer(new int[]{cx, cy});
            }
        }
        
        if (v[n - 1][m - 1] == 0) answer = -1;
        else answer = v[n - 1][m - 1];
        
        return answer;
    }
}