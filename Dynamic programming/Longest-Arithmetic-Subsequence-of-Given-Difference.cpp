            //Longest-Arithmetic-Subsequence-of-Given-Difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int>db;
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=arr[i]-difference;
            int tempAns=0;
            if(db.count(temp)){
                tempAns=db[temp];
            }
            db[arr[i]]=1+tempAns;
            ans=max(ans,db[arr[i]]);
        }
        return ans;
    }
};