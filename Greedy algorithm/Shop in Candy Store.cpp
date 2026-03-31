class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(),prices.end());
        vector<int>ans;
        int mini=0;
        int buy=0;
        int freeCan=prices.size()-1;
        while(buy<=freeCan){
            mini+=prices[buy];
            buy++;
            freeCan=freeCan-k;
        }
        ans.push_back(mini);
        int maxi=0;
         buy=prices.size()-1;
         freeCan=0;
        while(buy>=freeCan){
            maxi+=prices[buy];
            buy--;
            freeCan=freeCan+k;
        }
        ans.push_back(maxi);
        return ans;
    }
};