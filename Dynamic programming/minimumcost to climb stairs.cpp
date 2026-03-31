                                //RECURSION

class Solution {
private:
    int solve(vector<int>&cost,int n){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        int ans=cost[n] + min(solve(cost,n-1),solve(cost,n-2));
        return ans;
    }
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=min(solve(cost,n-1),solve(cost,n-2));
        return ans;
    }
};

                            //RECURSION AND MEMOIZATION
class Solution {
private:
    int solve(vector<int>& cost, int n, vector<int>& dp){
        
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];
        
        // check if already calculated
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        vector<int> dp(n+1, -1);
        
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        
        return ans;
    }
};

                            //TABULATION


class Solution {
private:
    int solve(vector<int>& cost, int n){
        vector<int> dp(n+1, -1);

        db[0]=cost[0];
        db[1]=cost[1];

        for(int i=2;i<n;i++){
            db[i]=cost[i] + min(db[n-1],db[n-2]);
        }
        return min(db[n-1],db[n-2]);
        
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        return solve(cost,n);
    }
};


                            //SPACE OPTIMIZATION


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        for(int i=2;i<cost.size();i++){
            int curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return min(prev1,prev2);
    }
};