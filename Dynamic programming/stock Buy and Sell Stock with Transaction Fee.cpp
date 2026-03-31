`                               //RECURSION
class Solution {
private:
    int solve(vector<int>& prices,int &n,int buy,int index ,int& fee){
        if(index>=n){
            return 0;
        }
        int profit=0;
        if(buy==1){
            profit=max(((-prices[index])+solve(prices,n,0,index+1,fee)),(0+solve(prices,n,1,index+1,fee)));
        }
        else{
            profit=max((prices[index]+solve(prices,n,1,index+1,fee)-fee),(0+solve(prices,n,0,index+1,fee)));
            
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        return solve(prices,n,1,0,fee);
    }
};

                                //SPACE OPTIMIZATION



class Solution {

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n == 0) return 0;

        vector<int> next(2, 0), curr(2, 0);

        for(int index = n - 1; index >= 0; index--) {
            
            // buy = 1
            curr[1] = max(-prices[index] + next[0],
                           next[1]);

            // buy = 0
            curr[0] = max(prices[index] + next[1]-fee,
                           next[0]);

            // move current → next
            next = curr;
        }

        return next[1];
    }
};