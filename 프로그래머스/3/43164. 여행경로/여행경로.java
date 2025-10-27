import java.util.*;

class Solution {
    class Pair {
        String s;
        int pos;
        
        Pair(String s, int pos) {
            this.s = s;
            this.pos = pos;
        }
    }
    HashMap<String, Integer> hm;
    ArrayList<Pair>[] e;
    int maxLength;
    int[] v;
    String[] nodes;
    String[] answer;
    int check = 0;
    
    public String[] solution(String[][] tickets) {
        hm = new HashMap<>();
        
        hm.put("ICN", 1);
        int idx = 2;
        for (String[] ticket: tickets) {
            for (String t: ticket) {
                if (hm.containsKey(t)) continue;
                hm.put(t, idx++);                
            }
        }
        
        e = new ArrayList[idx];
        for (int i = 0; i < idx; ++i) {
            e[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < tickets.length; ++i) {
            e[hm.get(tickets[i][0])].add(new Pair(tickets[i][1], i));
        }
        
        for (int i = 0; i < idx; ++i) {
            Collections.sort(e[i], new Comparator<Pair>() {
                public int compare(Pair o1, Pair o2) {
                    return o1.s.compareTo(o2.s);
                }
            });
        }
        maxLength = tickets.length;
        v = new int[tickets.length];
        answer = new String[tickets.length + 1];
        nodes = new String[tickets.length + 1];
        nodes[0] = "ICN";
        
        dfs(0, "ICN");
        
        return answer;
    }
    
    public void dfs(int cnt, String node) {
        if (cnt == maxLength) {
            check = 1;
            answer = nodes.clone();
            return;
        }
        
        for (Pair pair: e[hm.get(node)]) {
            if (v[pair.pos] != 0) continue;
            v[pair.pos] = 1;
            nodes[cnt + 1] = pair.s;
            dfs(cnt + 1, pair.s);
            v[pair.pos] = 0;
            
            if (check == 1) break;
        }
    }
}