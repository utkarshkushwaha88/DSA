class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>db(amount+1,INT_MAX);
        db[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if((i-coins[j]>=0) && db[i-coins[j]]!=INT_MAX){
                    db[i]=min(db[i],1+db[i-coins[j]]);
                }
            }
        }
        if(db[amount]==INT_MAX)
            return -1;
        return db[amount];
    }
};