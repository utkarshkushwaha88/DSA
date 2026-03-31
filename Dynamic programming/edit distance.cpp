                    //RECURSION


class Solution {
private:
    int solve(string word1, string word2,int i,int j){
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        int ans=0;
        if(word1[i]==word2[j]){
            return solve(word1,word2,i+1,j+1);
        }
        else{
            int insertAns=1+solve(word1,word2,i,j+1);
            int deleteAns=1+solve(word1,word2,i+1,j);
            int replaceAns=1+solve(word1,word2,i+1,j+1);
            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        return ans;
    }
public:
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};


                            //MEMOIZATION

class Solution {
private:
    int solve(string word1, string word2,int i,int j,vector<vector<int>>&db){
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        if(db[i][j]!=-1){
            return db[i][j];
        }
        int ans=0;
        if(word1[i]==word2[j]){
            return solve(word1,word2,i+1,j+1,db);
        }
        else{
            int insertAns=1+solve(word1,word2,i,j+1,db);
            int deleteAns=1+solve(word1,word2,i+1,j,db);
            int replaceAns=1+solve(word1,word2,i+1,j+1,db);
            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        return db[i][j]= ans;
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>db(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,0,0,db);
    }
};

                            //TABULATION

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> db(n+1, vector<int>(m+1, 0));

        // Base cases
        for(int i = 0; i <= n; i++){
            db[i][m] = n - i; // delete remaining
        }
        for(int j = 0; j <= m; j++){
            db[n][j] = m - j; // insert remaining
        }

        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    db[i][j] = db[i+1][j+1]; 
                }
                else{
                    int insertAns = 1 + db[i][j+1];
                    int deleteAns = 1 + db[i+1][j];
                    int replaceAns = 1 + db[i+1][j+1];

                    db[i][j] = min(insertAns, min(deleteAns, replaceAns));
                }
            }
        }

        return db[0][0];
    }
};



                        //SPACE OPTIMIZATION

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> next(m+1, 0), curr(m+1, 0);

        // 🔥 Base case: dp[n][j] = m - j
        for(int j = 0; j <= m; j++){
            next[j] = m - j;
        }

        for(int i = n-1; i >= 0; i--){
            // 🔥 Base case: dp[i][m] = n - i
            curr[m] = n - i;

            for(int j = m-1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    curr[j] = next[j+1];
                }
                else{
                    int insertAns  = 1 + curr[j+1];   // dp[i][j+1]
                    int deleteAns  = 1 + next[j];     // dp[i+1][j]
                    int replaceAns = 1 + next[j+1];   // dp[i+1][j+1]

                    curr[j] = min(insertAns, min(deleteAns, replaceAns));
                }
            }

            next = curr; // move current row to next
        }

        return next[0];
    }
}; 