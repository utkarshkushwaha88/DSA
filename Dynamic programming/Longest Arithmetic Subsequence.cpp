                        //RECURSION

// User function template for C++

class Solution {
private:
    int solve(int index,int diff,vector<int>&arr){
        if(index<0){
            return 0;
        }
        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(arr[index]-arr[j]==diff){
                ans=max(ans,1+solve(j,diff,arr));
            }
            
        }
        return ans;
    }
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n=arr.size();
        if(n<=2){
            return n;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solve(i,arr[j]-arr[i],arr));
            }
        }
       return ans; 
    }
};

                                //MEMOIZATION
                            
// User function template for C++

class Solution {
private:
    int solve(int index,int diff,vector<int>&arr,unordered_map<int,int>db[]){
        if(index<0){
            return 0;
        }
        if(db[index].count(diff)){
            return db[index][diff];
        }
        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(arr[index]-arr[j]==diff){
                ans=max(ans,1+solve(j,diff,arr,db));
            }
            
        }
        return db[index][diff]= ans;
    }
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>db[n+1];
        if(n<=2){
            return n;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solve(i,arr[j]-arr[i],arr,db));
            }
        }
       return ans; 
    }
};

                    //TABULATION

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int ans=0;
        unordered_map<int,int>db[n+1];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int cnt=1;
                 
                //check if answer already present
                if(db[j].count(diff)){
                    cnt=db[j][diff];
                }
                db[i][diff]=1+cnt;
                ans=max(ans,db[i][diff]);
            }
        }
        return ans;
    }
};

