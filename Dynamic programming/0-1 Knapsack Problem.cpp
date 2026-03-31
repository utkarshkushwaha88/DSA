                        //  RECURSION
                        //TIME COMPLEXITY:-O(2n)
                        //SPACE COMPLEXITY:-O(n)

class Solution {
private:
    int solve(int capacity, vector<int> &val, vector<int> &wt,int index){
        if(index==0){
            if(wt[index]<=capacity){
                return val[index];
            }
            else{
                return 0;
            }
        }
        int include=0;
        if(wt[index]<=capacity){
            include=val[index]+solve(capacity-val[index],val,wt,index-1);
        }
        int exclude=solve(capacity,val,wt,index-1);
        
        int ans=max(include,exclude);
        return ans;
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        solve(W,val,wt,n-1);
        
    }
};


                            //MEMOIZATION
                            //TIME COMPLEXITY:-O(n×W)
                            //SPACE COMPLEXITY:-O(n×W)

class Solution {
private:
    int solve(int capacity, vector<int> &val, vector<int> &wt, int index,
              vector<vector<int>>& dp) {

        if(index == 0){
            if(wt[0] <= capacity)
                return val[0];
            else
                return 0;
        }

        if(dp[index][capacity] != -1)
            return dp[index][capacity];

        int include = 0;
        if(wt[index] <= capacity){
            include = val[index] + solve(capacity - wt[index], val, wt, index-1, dp);
        }

        int exclude = solve(capacity, val, wt, index-1, dp);

        dp[index][capacity] = max(include, exclude);
        return dp[index][capacity];
    }

public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));

        return solve(W, val, wt, n-1, dp);
    }
};



                                //TABULATION
                                //TIME COMPLEXITY:-O(n×W)
                                //SPACE COMPLEXITY:-O(n×W)

class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1,0));
        
        for(int c=wt[0]; c<=W; c++){
            dp[0][c] = val[0];
        }
        
        for(int i=1;i<n;i++){
            for(int c=0;c<=W;c++){
                
                int include = 0;
                if(wt[i] <= c){
                    include = val[i] + dp[i-1][c-wt[i]];
                }
                
                int exclude = dp[i-1][c];
                
                dp[i][c] = max(include,exclude);
            }
        }
        
        return dp[n-1][W];
    }
};


                        //SPACE OPTIMIZED
                        //TIME COMPLEXITY:-O(n×W)
                        //SPACE COMPLEXITY:-O(W)

class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = wt.size();
        vector<int> dp(W+1,0);
        
        for(int c = wt[0]; c <= W; c++){
            dp[c] = val[0];
        }
        
        for(int i = 1; i < n; i++){
            for(int c = W; c >= 0; c--){
                
                int include = 0;
                if(wt[i] <= c){
                    include = val[i] + dp[c - wt[i]];
                }
                
                int exclude = dp[c];
                
                dp[c] = max(include, exclude);
            }
        }
        
        return dp[W];
    }
};