                        //RECURSION

class Solution {
private:
    int solve(int index,int endIndex,vector<int>& a,int n){
        if(n==0 || index>endIndex){
            return 0;
        }
        int take=a[index]+solve(index+2,endIndex,a,n-1);
        int notTake=0+solve(index+1,endIndex,a,n);
        return max(take,notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        int case1=solve(0,k-2,slices,k/3);
        int case2=solve(1,k-1,slices,k/3);
        return max(case1,case2);
    }
};

                        //MEMOIZATION

class Solution {
private:
    int solve(int index,int endIndex,vector<int>&arr,int n,vector<vector<int>>&db){
        if(n==0 || index>endIndex){
            return 0;
        }
        if(db[index][n]!=-1){
            return db[index][n];
        }
        int take=arr[index] + solve(index+2,endIndex,arr,n-1,db);
        int notTake=0+ solve(index+1,endIndex,arr,n,db);
        return db[index][n]= max(take,notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        vector<vector<int>>db1(k,vector<int>(k,-1));
        vector<vector<int>>db2(k,vector<int>(k,-1));
        int case1=solve(0,k-2,slices,k/3,db1);
        int case2=solve(1,k-1,slices,k/3,db2);
        return max(case1,case2);
    }
};

                            //TABULATION
                
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int NEG = -1e9;

        vector<vector<int>> db1(k+2, vector<int>(k+2, NEG));
        vector<vector<int>> db2(k+2, vector<int>(k+2, NEG));

        // base case
        for(int i = 0; i <= k+1; i++){
            db1[i][0] = 0;
            db2[i][0] = 0;
        }

        // case 1 (0 to k-2)
        for(int index = k-2; index >= 0; index--){
            for(int i = 1; i <= k/3; i++){
                int take = slices[index] + db1[index+2][i-1];
                int notTake = db1[index+1][i];
                db1[index][i] = max(take, notTake);
            }
        }

        int case1 = db1[0][k/3];

        // case 2 (1 to k-1)
        for(int index = k-1; index >= 1; index--){
            for(int i = 1; i <= k/3; i++){
                int take = slices[index] + db2[index+2][i-1];
                int notTake = db2[index+1][i];
                db2[index][i] = max(take, notTake);
            }
        }

        int case2 = db2[1][k/3];

        return max(case1, case2);
    }
};

                                //SPACE OPTIMIZATION


class Solution {
private:
    int solve(vector<int>& slices, int start, int end, int k) {
        int NEG = -1e9;

        vector<int> prev2(k+1, NEG), prev1(k+1, NEG), curr(k+1, NEG);

        // base case: picking 0 slices = 0
        prev2[0] = prev1[0] = 0;

        for(int index = end; index >= start; index--) {
            curr[0] = 0; // base case

            for(int i = 1; i <= k; i++) {
                int take = slices[index] + prev2[i-1];
                int notTake = prev1[i];

                curr[i] = max(take, notTake);
            }

            // shift
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1[k];
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;

        int case1 = solve(slices, 0, n-2, k); // exclude last
        int case2 = solve(slices, 1, n-1, k); // exclude first

        return max(case1, case2);
    }
};