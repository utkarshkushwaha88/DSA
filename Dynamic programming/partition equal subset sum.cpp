                            //recursion
                
class Solution {
bool solve(int index,vector<int>&nums,int n,int target){
    if(index>=n){
        return 0;
    }
    if(target<0){
        return 0;
    }
    if(target==0){
        return 1;
    }
    bool include=solve(index+1,nums,n,target-nums[index]);
    bool exclude=solve(index+1,nums,n,target);
    return (include || exclude);
}
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum & 1){
            return false;
        }
        int target=sum/2;
        bool ans=solve(0,nums,n,target);
        return ans;
    }
};


                            //MEMOIZATION

class Solution {
bool solve(int index,vector<int>&nums,int n,int target,vector<vector<int>>&db){
    if(index>=n){
        return 0;
    }
    if(target<0){
        return 0;
    }
    if(target==0){
        return 1;
    }
    if(db[index][target]!=-1){
        return db[index][target];
    }
    bool include=solve(index+1,nums,n,target-nums[index],db);
    bool exclude=solve(index+1,nums,n,target,db);
    return db[index][target]=(include || exclude);
}
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum & 1){
            return false;
        }
        int target=sum/2;
        vector<vector<int>>db(n,vector<int>(target+1,-1));
        bool ans=solve(0,nums,n,target,db);
        return ans;
    }
};

                            //TABULATION


class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for(int x : arr) sum += x;

        if(sum & 1) return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        // base case
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for(int index = n-1; index >= 0; index--) {
            for(int tar = 1; tar <= target; tar++) {

                bool include = false;
                if(tar >= arr[index])
                    include = dp[index+1][tar - arr[index]];

                bool exclude = dp[index+1][tar];

                dp[index][tar] = include || exclude;
            }
        }

        return dp[0][target];
        
    }
};


                            //SPACE OPTIMIZED

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for(int x : arr) sum += x;

        if(sum & 1) return false;

        int target = sum / 2;

        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);

        next[0] = 1;

        for(int index = n-1; index >= 0; index--) {

            curr[0] = 1;  

            for(int tar = 1; tar <= target; tar++) {

                bool include = false;
                if(tar >= arr[index])
                    include = next[tar - arr[index]];

                bool exclude = next[tar];

                curr[tar] = include || exclude;
            }

            next = curr;  
        }

        return next[target];
    }
};

                                //MORE SPACE OPTIMIZED

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum & 1) return false;

        int target = sum / 2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(int num : nums) {
            for(int tar = target; tar >= num; tar--) {
                dp[tar] = dp[tar] || dp[tar - num];
            }
        }

        return dp[target];
    }
};