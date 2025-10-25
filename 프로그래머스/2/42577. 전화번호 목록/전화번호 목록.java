import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        // HashSet<String> hs = new HashSet<>();
        // for (String num: phone_book) {
        //     for (int i = 1; i < num.length(); ++i) {
        //         hs.add(num.substring(0, i));
        //     }
        // }
        // for (String num: phone_book) {
        //     if (hs.contains(num)) {
        //         answer = false;
        //         break;
        //     }
        // }
        Arrays.sort(phone_book);
        for (int i = 1; i < phone_book.length; ++i) {
            if (phone_book[i].startsWith(phone_book[i - 1])) {
                answer = false;
                break;
            }
        }
        return answer;
    }
}