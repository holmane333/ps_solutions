import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        Stack<Integer> q = new Stack<>();
        for (int i: arr) {
            if (!q.isEmpty() && q.peek() == i) continue;
            q.push(i);
        }
        answer = new int[q.size()];
        int i = q.size() - 1;
        while (!q.isEmpty()) {
            answer[i--] = q.pop();
        }
        return answer;
    }
}