class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // Step 1: Sort
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0])
                return a[1] > b[1]; // height descending
            return a[0] < b[0];     // width ascending
        });

        // Step 2: LIS on heights
        vector<int> ans;

        for(auto &env : envelopes){
            int h = env[1];

            if(ans.empty() || h > ans.back()){
                ans.push_back(h);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), h) - ans.begin();
                ans[index] = h;
            }
        }

        return ans.size();
    }
};