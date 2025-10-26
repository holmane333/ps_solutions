import java.util.*;

class Solution {
    ArrayList<Integer>[] e;
    int answer = 0;
    int[] nodeInfo;
    
    boolean[][][] cache;
    
    public int solution(int[] info, int[][] edges) {
        e = new ArrayList[info.length + 2];
        nodeInfo = info;
        for (int i = 0; i < info.length + 2; ++i) e[i] = new ArrayList<>();
        for (int[] edge: edges) {
            e[edge[0]].add(edge[1]);
        }
        
        cache = new boolean[18][18][1 << info.length];
        
        ArrayList<Integer> nextMoves = new ArrayList<>();
        for (int node : e[0]) {
            nextMoves.add(node);
        }
        
        cache[1][0][1] = true;
        dfs(1, 0, nextMoves, 1);
        
        return answer;
    }
    
    public void dfs(int sheep, int wolf, ArrayList<Integer> nextMoves, int mask) {
        answer = Math.max(answer, sheep);
        for (int i = 0; i < nextMoves.size(); ++i) {
            int nextMove = nextMoves.get(i);
            int nextSheep = sheep, nextWolf = wolf;
            if (nodeInfo[nextMove] == 0) nextSheep++;
            else nextWolf++;
            if (nextSheep <= nextWolf || cache[nextSheep][nextWolf][mask | (1 << nextMove)]) continue;
            
            cache[nextSheep][nextWolf][mask | (1 << nextMove)] = true;
            
            ArrayList<Integer> nextNextMoves = new ArrayList<>(nextMoves);
            nextNextMoves.remove(i);
            for (Integer node: e[nextMove]) {
                nextNextMoves.add(node);
            }
            
            dfs(nextSheep, nextWolf,nextNextMoves, (mask | (1 << nextMove)));
        }
    }
    
}