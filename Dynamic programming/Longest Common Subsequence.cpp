                        //RECURSION

class Solution {
private:
    int solve(string &text1, string &text2, int n, int m){
        if(n < 0 || m < 0){
            return 0;
        }

        if(text1[n] == text2[m]){
            return 1 + solve(text1, text2, n-1, m-1);
        }

        return max(
            solve(text1, text2, n-1, m),
            solve(text1, text2, n, m-1)
        );
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, text1.length()-1, text2.length()-1);
    }
};


                    //MEMOIZATION

class Solution {
private:
    int solve(string &text1, string &text2, int n, int m, vector<vector<int>>& dp){
        if(n < 0 || m < 0){
            return 0;
        }

        if(dp[n][m] != -1) return dp[n][m];

        if(text1[n] == text2[m]){
            return dp[n][m] = 1 + solve(text1, text2, n-1, m-1, dp);
        }

        return dp[n][m] = max(
            solve(text1, text2, n-1, m, dp),
            solve(text1, text2, n, m-1, dp)
        );
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(text1, text2, n-1, m-1, dp);
    }
};

                            //TABULATION


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};

                                //SPACE OPTIMIZATION

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};