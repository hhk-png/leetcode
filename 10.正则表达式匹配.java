class Solution {
    public boolean isMatch(String text, String pattern) {
        boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
        dp[text.length()][pattern.length()] = true;

        for(int i = text.length(); i >= 0; i--) {
            for(int j = pattern.length() - 1; j >= 0; j--) {
                boolean firstMatch = (i < text.length() && (text.charAt(i) == pattern.charAt(j) || pattern[j] == '.'));
                if(j+1 < pattern.length() && pattern.charAt(j+1) == '*') {
                    dp[i][j] = dp[i][j+2] || firstMatch && dp[i+1][j];
                } else {    
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
}