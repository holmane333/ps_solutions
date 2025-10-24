import java.io.*;
import java.util.*;

class Solution {
    static class Pair {
        int left;
        int right;
        Pair(int x, int y) {
            this.left = x;
            this.right = y;
        }
    }
    
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int cnt = 1;
        Queue<Pair> q = new LinkedList<>();
        for (int i = 0; i < players.length; ++i) {
            while (!q.isEmpty()) {
                if (q.peek().left <= i) {
                    cnt -= q.poll().right;
                }
                else {
                    break;
                }
            }
            int p = players[i] + 1;
            
            if (p > cnt * m) {
                int c = (p - cnt * m) / m;
                if ((p - cnt * m) % m > 0) c += 1;
                cnt += c;
                answer += c;
                q.offer(new Pair(i + k, c));
            }
            
        }
        return answer;
    }
}