                        //RECURSION

class Solution {
private:
    int solve(vector<int>&prices,int &n,int buy,int index,int k){
        if(index>=n || k==0){
            return 0;
        }
        
        int profit=0;
        if(buy==1){
            profit=max(((-prices[index])+solve(prices,n,0,index+1,k)),(0+solve(prices,n,1,index+1,k)));
        }
        else{
            profit=max((prices[index]+solve(prices,n,1,index+1,k-1)),(0+solve(prices,n,0,index+1,k)));
            
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices, int k) {
        int n=prices.size();
        return solve(prices,n,1,0,k);
        
    }
};


                            //MEMOIZATION

class Solution {
private:
    int solve(vector<int>&prices,int &n,int buy,int index,int k,vector<vector<vector<int>>>&db){
        if(index>=n || k==0){
            return 0;
        }
        if(db[index][buy][k]!=-1){
            return db[index][buy][k];
        }
        int profit=0;
        if(buy==1){
            profit=max(((-prices[index])+solve(prices,n,0,index+1,k,db)),(0+solve(prices,n,1,index+1,k,db)));
        }
        else{
            profit=max((prices[index]+solve(prices,n,1,index+1,k-1,db)),(0+solve(prices,n,0,index+1,k,db)));
            
        }
        return db[index][buy][k]= profit;
    }
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<int>>>db(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,n,1,0,k,db);
        
    }
};

                        //TABULATION

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> db(n+1,
            vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= 2; limit++){

                    if(buy == 1){
                        db[index][buy][limit] = max(
                            -prices[index] + db[index+1][0][limit],
                            db[index+1][1][limit]
                        );
                    }
                    else{
                        db[index][buy][limit] = max(
                            prices[index] + db[index+1][1][limit-1],
                            db[index+1][0][limit]
                        );
                    }
                }
            }
        }

        return db[0][1][2];
    }
}; 

                                //SPACE OPTIMIZATION

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>next(2,vector<int>(3,0));

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= 2; limit++){

                    if(buy == 1){
                        curr[buy][limit] = max(
                            -prices[index] + next[0][limit],
                            next[1][limit]
                        );
                    }
                    else{
                        curr[buy][limit] = max(
                            prices[index] + next[1][limit-1],
                            next[0][limit]
                        );
                    }
                    
                }
            }
            next=curr;
        }

        return next[1][2];
    }
};


                            //MORE SPACE OPTIMIZED for at most to transcations

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (int p : prices) {
            buy1  = max(buy1, -p);
            sell1 = max(sell1, buy1 + p);
            buy2  = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        return sell2;
    }
};

    


