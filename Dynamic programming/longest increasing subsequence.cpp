                    //RECURSION

class Solution {
private:
    int solve(int &n,vector<int>& nums,int curr,int prev){
        if(curr==n){
            return 0;
        }
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include=1+ solve(n,nums,curr+1,curr);
        }
        int exclude=0 + solve(n,nums,curr+1,prev);
        return max(include,exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return solve(n,nums,0,-1);
    }
};


                        //MEMOIZATION

class Solution {
private:
    int solve(int n, vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        if(curr == n) return 0;

        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solve(n, nums, curr+1, curr, dp);
        }

        int exclude = solve(n, nums, curr+1, prev, dp);

        return dp[curr][prev+1] = max(include, exclude);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1)); 
        return solve(n, nums, 0, -1, dp);
    }
};


                        //TABULATION

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>db(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //include
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    include=1+db[curr+1][curr+1];
                }
                //exclude
                int exclude=0 + db[curr+1][prev+1];
                db[curr][prev+1]=max(include,exclude);
            }

        }
        return db[0][0];
    }
}; 


                            //SPACE OPTIMIZATION


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>currRow(n+1,0);
        vector<int>next(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //include
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    include=1+next[curr+1];
                }
                //exclude
                int exclude=0 + next[prev+1];
                currRow[prev+1]=max(include,exclude);
            }
            next=currRow;
        }
        return next[0];
    }
};

                        //MORE OPTIMIZED
                        //T.C:-O(NLOGN)
                        //S.C:-O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                //just greatest element by binary search in DP
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
};