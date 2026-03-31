                            //WHEN HOUSES ARE IN CIRCULAR ORDER 
class Solution {
private:
    int solve(vector<int>&arr){
        int n=arr.size();
        int prev2=0;
        int prev1=arr[0];
        for(int i=1;i<n;i++){
            int include=arr[i]+prev2;
            int exclude=prev1;
            int curr=max(include,exclude);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> first, second;
        for(int i=0;i<n;i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        return max(solve(first),solve(second));
    }
};