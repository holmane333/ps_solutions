class Solution {
    public int solution(int[][] info, int n, int m) {
        int answer = (int)1e9;
        int[][][] dp = new int[info.length][130][130];
        dp[0][info[0][0]][0] = 1;
        dp[0][0][info[0][1]] = 1;
        for (int i = 1; i < info.length; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (j >= info[i][0]) dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j - info[i][0]][k]);
                    if (k >= info[i][1]) dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j][k - info[i][1]]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dp[info.length - 1][i][j] == 1) answer = Math.min(answer, i);
            }
        }
        if (answer == (int)1e9) answer = -1;
        return answer;
    }
}