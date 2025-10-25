import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Arrays.sort(participant, new Comparator<String>() {
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });
        Arrays.sort(completion, new Comparator<String>() {
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });
        int c = 0;
        for (int i = 0; i < completion.length; ++i) {
            if (!participant[i].equals(completion[i])) {
                answer = participant[i];
                c = 1;
                break;
            }
        }
        if (c == 0) answer = participant[participant.length - 1];
        return answer;
    }
}