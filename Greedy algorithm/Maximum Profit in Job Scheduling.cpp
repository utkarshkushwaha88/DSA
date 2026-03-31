class Solution {
public:
    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp) {
        if(i >= jobs.size()) return 0;
        
        if(dp[i] != -1) return dp[i];

        // Binary search to find next non-overlapping job
        int next = lower_bound(jobs.begin(), jobs.end(), vector<int>{jobs[i][1], 0, 0}) - jobs.begin();

        // take or skip
        int take = jobs[i][2] + solve(next, jobs, dp);
        int skip = solve(i + 1, jobs, dp);

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<vector<int>> jobs;

        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // sort by start time
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);

        return solve(0, jobs, dp);
    }
};