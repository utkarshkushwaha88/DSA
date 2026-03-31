                    //RECURSION

class Solution {
private:
    int solve(vector<int>&prices,int &n,int buy,int index){
        if(index>=n){
            return 0;
        }
        int profit=0;
        if(buy==1){
            profit=max(((-prices[index])+solve(prices,n,0,index+1)),(0+solve(prices,n,1,index+1)));
        }
        else{
            profit=max((prices[index]+solve(prices,n,1,index+1)),(0+solve(prices,n,0,index+1)));
            
        }
        return profit;
    }
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        return solve(prices,n,1,0);
        
    }
};


                            //MEMOIZATION

class Solution {
private:
    int solve(vector<int>&prices,int &n,int buy,int index,vector<vector<int>>&db){
        if(index>=n){
            return 0;
        }
        if(db[buy][index]!=-1){
            return db[buy][index];
        }
        int profit=0;
        if(buy==1){
           profit=max(((-prices[index])+solve(prices,n,0,index+1,db)),(0+solve(prices,n,1,index+1,db)));
           
        }
        else{
            profit=max((prices[index]+solve(prices,n,1,index+1,db)),(0+solve(prices,n,0,index+1,db)));
            
        }
        return db[buy][index]= profit;
    }
  public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        vector<vector<int>>db(2,vector<int>(n,-1));
        return solve(prices,n,1,0,db);
        
    }
};


                                //TABULATION
                                //S.C:-O(N)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0) return 0;

        vector<vector<int>> db(2, vector<int>(n+1, 0));

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                
                if(buy == 1){
                    db[buy][index] = max(-prices[index] + db[0][index+1],
                                          db[1][index+1]);
                }
                else{
                    db[buy][index] = max(prices[index] + db[1][index+1],
                                          db[0][index+1]);
                }
            }
        }

        return db[1][0];
    }
};


                            //SPACE OPTIMIZATION
                            //S.C:-0(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        vector<int> next(2, 0), curr(2, 0);

        for(int index = n - 1; index >= 0; index--) {
            
            // buy = 1
            curr[1] = max(-prices[index] + next[0],
                           next[1]);

            // buy = 0
            curr[0] = max(prices[index] + next[1],
                           next[0]);

            // move current → next
            next = curr;
        }

        return next[1];
    }
};


                        //MORE OPTIMIZED

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int max = 0;
    int start = prices[0];
    for(int i = 1;i<prices.size(); i++){
        if(start < prices[i]){
            max += prices[i] - start;
        }
        start = prices[i];
    }
    return max;
    }
};