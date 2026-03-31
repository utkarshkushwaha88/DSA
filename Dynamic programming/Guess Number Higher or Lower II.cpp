                        //RECURSION
class Solution {
private:
    int solve(int start,int end){
        if(start>=end){
            return 0;
        }
        int maxi=INT_MAX;
        for(int i=start;i<=end;i++){
            maxi=min(maxi,i+max(solve(start,i-1),solve(i+1,end)));
        }
        return maxi;
    }
public:
    int getMoneyAmount(int n) {
        return solve(1,n);
    }
};

                //MEMOIZATION

class Solution {
private:
    int solve(int start,int end,vector<vector<int>>&db){
        if(start>=end){
            return 0;
        }
        if(db[start][end]!=-1){
            return db[start][end];
        }
        int maxi=INT_MAX;
        for(int i=start;i<=end;i++){
            maxi=min(maxi,i+max(solve(start,i-1,db),solve(i+1,end,db)));
        }
        return db[start][end]= maxi;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>db(n+1,vector<int>(n+1,-1));

        return solve(1,n,db);
    }
};

                        //TABULATION

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>db(n+2,vector<int>(n+2,0));

        for(int start=n;start>=1;start--){
            for(int end=start;end<=n;end++){
                if(start==end){
                    continue;
                }
                else{
                    int maxi=INT_MAX;
                    for(int i=start;i<=end;i++){
                        maxi=min(maxi,i+max(db[start][i-1],db[i+1][end]));
                    }
                     db[start][end]=maxi;
                }
            }
        }
        return db[1][n];
    }
};