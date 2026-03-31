                        //recursion

class Solution {
private:
    int solve(vector<int>& arr, int key){
        if(key==0){
            return 1;
        }
        if(key<0){
            return 0;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=solve(arr,key-arr[i]);
        }
        return ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums,target);
    }
};

                        //memoization
class Solution {
private:
    int solve(vector<int>& arr, int key,vector<int>&db){
        if(key==0){
            return 1;
        }
        if(key<0){
            return 0;
        }
        if(db[key]!=-1){
            return db[key];
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=solve(arr,key-arr[i],db);
        }
        db[key]=ans;
        return db[key];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>db(target+1,-1);

         return solve(nums,target,db);

    }
};


                        //Tabulation


class Solution {
public:
    int combinationSum4(vector<int>& arr, int key) {
        vector<unsigned long long > dp(key+1,0);
        dp[0] = 1;
        for(int i=1;i<=key;i++){
            for(int j=0;j<arr.size();j++){
                if(i-arr[j] >= 0){
                    dp[i] += dp[i-arr[j]];
                }
            }
        }
        return dp[key];
    }
};