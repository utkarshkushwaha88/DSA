                                //RECURSION
class Solution {
private:
    int solve(int dice,int &faces,int target){
        if(target<0){
            return 0;
        }
        if(dice==0 && target!=0){
            return 0;
        }
        if(target==0 && dice!=0){
            return 0;
        }
        if(dice==0 && target==0){
            return 1;   
        }
        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+ solve(dice-1,faces,target-i);
        }
        return ans;
    }
  public:
    int noOfWays(int m, int n, int x) {
        return solve(n,m,x);
        
    }
};

                                //MEMOIZATION

class Solution {
private:
    int solve(int dice,int &faces,int target,vector<vector<int>>&db){
        if(target<0){
            return 0;
        }
        if(dice==0 && target!=0){
            return 0;
        }
        if(target==0 && dice!=0){
            return 0;
        }
        if(dice==0 && target==0){
            return 1;
        }
        if(db[dice][target]!=-1){
            return db[dice][target];
        }
        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+ solve(dice-1,faces,target-i,db);
            
        }
        return  db[dice][target]=ans;;
    }
  public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>>db(n+1,vector<int>(x+1,-1));
        return solve(n,m,x,db);
        
    }
};


                        //TABULATION

class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> db(n+1, vector<int>(x+1, 0));
        
        db[0][0] = 1;
        
        for(int dice = 1; dice <= n; dice++) {
            for(int target = 1; target <= x; target++) {
                
                int ans = 0;
                
                for(int i = 1; i <= m; i++) {
                    if(target - i >= 0) {
                        ans += db[dice-1][target-i];
                    }
                }
                
                db[dice][target] = ans;
            }
        }
        
        return db[n][x];
    }
};


                            //SPACE OPTIMIZED

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1e9 + 7;

        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        prev[0] = 1;

        for(int dice = 1; dice <= n; dice++) {
            fill(curr.begin(), curr.end(), 0);  // ✅ important

            for(int t = 1; t <= target; t++) {
                int ans = 0;

                for(int face = 1; face <= k; face++) {
                    if(t - face >= 0) {
                        ans = (ans + prev[t - face]) % MOD;
                    }
                }

                curr[t] = ans;
            }

            prev = curr;
        }

        return prev[target];
    }
};