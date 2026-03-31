                        //memoization
class Solution {
private:
    int solve(int i,vector<int>& arr,int &n,vector<int>&db){
        if(i>=n){
            return 0;
        }
        if(db[i]!=INT_MIN){
            return db[i];
        }
        int include=arr[i]+solve(i+2,arr,n,db);
        int exclude=solve(i+1,arr,n,db);
        
        db[i]=max(include,exclude);
        return db[i];
    }
  public:
    int findMaxSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>db(n+1,INT_MIN);
        return solve(0,arr,n,db);
        
    }
};


                    //TABULATION

class Solution {
public:
    int findMaxSum(vector<int>& arr) {

        int n = arr.size();

        if(n == 1)
            return arr[0];

        vector<int> db(n,0);

        dp[0] = arr[0];
        db[1]=max(arr[0],arr[1]);

        for(int i = 2; i < n; i++){
            int include= db[i-2]+arr[i];
            int exclude=db[i-1];
            db[i]=max(include,exclude);
        }

        return dp[n-1];
    }
};


                        //SPACE OPTIMIZED

class Solution {
public:
    int findMaxSum(vector<int>& arr) {

        int n = arr.size();

        int prev2 = 0;
        int prev1 = arr[0];

        for(int i = 1; i < n; i++){

            int include = arr[i] + prev2;
            int exclude = prev1;

            int curr = max(include, exclude);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

