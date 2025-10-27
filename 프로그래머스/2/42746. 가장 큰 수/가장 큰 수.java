import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String[] s = new String[numbers.length];
        for (int i = 0; i < numbers.length; ++i) {
            s[i] = String.valueOf(numbers[i]);
        }
        Arrays.sort(s, new Comparator<String>() {
            public int compare(String o1, String o2) {
                return (o2 + o1).compareTo(o1 + o2);
            }
        });
        
        if (s[0].equals("0")) answer = "0";
        else answer = String.join("", s);
        
        return answer;
    }
}