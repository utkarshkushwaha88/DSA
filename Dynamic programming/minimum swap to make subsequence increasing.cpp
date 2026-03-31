                                //RECURSION


class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped){
        //base case
        if(index==nums1.size()){
            return 0;
        }
        int ans=INT_MAX;
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        //catch
        if(swapped){
            swap(prev1,prev2);
        }
        //no swap
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=solve(nums1,nums2,index+1,0);
        }
        //swap
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solve(nums1,nums2,index+1,1));
        }
        return ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        bool swapped=0;
        return solve(nums1,nums2,1,swapped);
    }
};

                            //MEMOIZATION

class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped,vector<vector<int>>&db){
        //base case
        if(index==nums1.size()){
            return 0;
        }
        int ans=INT_MAX;
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        //catch
        if(swapped){
            swap(prev1,prev2);
        }
        if(db[index][swapped]!=-1){
            return db[index][swapped];
        }
        //no swap
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=solve(nums1,nums2,index+1,0,db);
        }
        //swap
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solve(nums1,nums2,index+1,1,db));
        }
        return db[index][swapped]= ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        vector<vector<int>>db(n,vector<int>(2,-1));
        bool swapped=0;
        return solve(nums1,nums2,1,swapped,db);
    }
};


                                //TABULATION

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

        vector<vector<int>> dp(n+1, vector<int>(2, INT_MAX));

        // base case
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int index = n-1; index >= 1; index--) {
            for(int swapped = 1; swapped >= 0; swapped--) {

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped) swap(prev1, prev2);

                int ans = INT_MAX;

                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = dp[index+1][0];
                }

                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1) {
                    if(dp[index+1][1] != INT_MAX)
                        ans = min(ans, 1 + dp[index+1][1]);
                }

                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }
};


                                    //SPACE OPTIMIZED

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int noSwap = 0;  // no swap at index 0
        int swap = 1;    // swap at index 0

        for(int i = 1; i < n; i++) {

            int currNoSwap = INT_MAX;
            int currSwap = INT_MAX;

            // case 1: natural increasing
            if(nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
                currNoSwap = noSwap;
                currSwap = swap + 1;
            }

            // case 2: cross increasing
            if(nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                currNoSwap = min(currNoSwap, swap);
                currSwap = min(currSwap, noSwap + 1);
            }

            noSwap = currNoSwap;
            swap = currSwap;
        }

        return min(noSwap, swap);
    }
};