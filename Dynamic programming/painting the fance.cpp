                            //RECURSION 
class Solution {
private:
    int add(int a,int b){
        return a+b;
    }
    int multi(int a,int b){
        return a*b;
    }
    int solve(int n,int k){
        if(n==1){
            return k;
        }
        if(n==2){
            return add(k,multi(k,k-1));
        }
        int ans=add(multi(solve(n-2,k),k-1),multi(solve(n-1,k),k-1));
        return ans;
    }
public:
    int countWays(int n, int k) {
        return solve(n,k);
    }
};


                    //MEMOIZATION

class Solution {
private:
    int add(int a,int b){
        return a+b;
    }
    int multi(int a,int b){
        return a*b;
    }
    int solve(int n,int k,vector<int>&db){
        if(n==1){
            return k;
        }
        if(n==2){
            return add(k,multi(k,k-1));
        }
        if(db[n]!=-1){
            return db[n];
        }
        db[n]=add(multi(solve(n-2,k,db),k-1),multi(solve(n-1,k,db),k-1));
        return db[n];
    }
public:
    int countWays(int n, int k) {
        vector<int>db(n+1,-1);
        return solve(n,k,db);
    }
};



                            //TABULATION

class Solution {
private:
    int add(int a,int b){
        return a+b;
    }
    int multi(int a,int b){
        return a*b;
    }
  public:
    int countWays(int n, int k) {
        vector<int>db(n+1,-1);
        db[1]=k;
        db[2]=add(k,multi(k,k-1));
        for(int i=3;i<=n;i++){
            db[i]=add(multi(db[i-2],k-1),multi(db[i-1],k-1));
        }
        return db[n];
    }
};



                        //SPACE OPTIMIZATION


class Solution {
private:
    int add(int a,int b){
        return a+b;
    }
    int multi(int a,int b){
        return a*b;
    }
public:
    int countWays(int n, int k) {
        
        int prev1=add(k,multi(k,k-1));
        int prev2=k;
        for(int i=3;i<=n;i++){
            int curr=add(multi(prev2,k-1),multi(prev1,k-1));
            prev2=prev1;
            prev1=curr;
        }
        if(n==1)
            return prev2;
        return prev1;
    }
};

