                            //RECURSION

class Solution {
private:
    bool solve(string &txt, string &pat,int i,int j){
        //base case
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(pat[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        //match
        if(txt[i]==pat[j] || pat[j]=='?'){
            return solve(txt,pat,i-1,j-1);
        }
        else if(pat[j]=='*'){
            return (solve(txt,pat,i-1,j) || solve(txt,pat,i,j-1));
        }
        else{
            return false;
        }
    }
public:
    bool wildCard(string &txt, string &pat) {
        return solve(txt,pat,txt.length(),pat.length());
        
    }
};



                        //MEMOIZATION

class Solution {
private:
    bool solve(string &txt, string &pat,int i,int j,vector<vector<int>>&db){
        //base case
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(pat[k-1]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(db[i][j]!=-1){
            return db[i][j];
        }
        //match
        if(txt[i]==pat[j] || pat[j]=='?'){
            return solve(txt,pat,i-1,j-1,db);
        }
        else if(pat[j]=='*'){
            return (solve(txt,pat,i-1,j,db) || solve(txt,pat,i,j-1,db));
        }
        else{
            return false;
        }
    }
  public:
    bool wildCard(string &txt, string &pat) {
        vector<vector<int>>db(txt.length(),vector<int>(pat.length(),-1));
        return solve(txt,pat,txt.length()-1,pat.length()-1,db);
        
    }
};


                            //TABULATION

class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.length();
        int m = pat.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case
        dp[0][0] = true;

        // pattern vs empty text
        for (int j = 1; j <= m; j++) {
            dp[0][j] = (pat[j - 1] == '*') && dp[0][j - 1];
        }

        // fill table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (txt[i - 1] == pat[j - 1] || pat[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pat[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

                            //SPACE OPTIMIZATION

class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.length();
        int m = pat.length();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        // base case
        prev[0] = true;

        // pattern vs empty text
        for (int j = 1; j <= m; j++) {
            prev[j] = (pat[j - 1] == '*') && prev[j - 1];
        }

        for (int i = 1; i <= n; i++) {

            curr[0] = false; // text non-empty, pattern empty

            for (int j = 1; j <= m; j++) {

                if (txt[i - 1] == pat[j - 1] || pat[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (pat[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else {
                    curr[j] = false;
                }
            }

            prev = curr; // move current row to previous
        }

        return prev[m];
    }
};