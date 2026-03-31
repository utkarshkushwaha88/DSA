                        //recursion

class Solution {
private:
    int solve(int n){
        if(n==0)
            return 0;
        
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans =min(ans,1+solve(n-i*i));
        }
        return ans;
    }
  public:
    int minSquares(int n) {
       return  solve ( n);
    }
};


                        //memoization

class Solution {
private:
    int solve(int n,vector<int>&db){
        if(n==0)
            return 0;
        if(db[n]!=-1)
            return db[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans =min(ans,1+solve(n-i*i,db));
        }
        return db[n]=ans;
    }
  public:
    int minSquares(int n) {
        vector<int>db(n+1,-1);
       return  solve (n,db);
    }
};

                        //tabulation

class Solution {
private:
    int solve(int n){
        vector<int>db(n+1,INT_MAX);
        db[0]=0;
        
        for(int j=1;j<=n;j++){
            for(int i=1;i*i<=j;i++){
                db[j]=min(db[j],1+db[j-i*i]);
            }
        }
        return db[n];
    }
  public:
    int minSquares(int n) {
        
       return  solve (n);
    }
}; 