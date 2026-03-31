                //recursion

class Solution {
  public:
    // Function to return the total number of possible unique BST.
    int numTrees(int n) {
        if(n<=1){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return ans;
        
    }
};


                        //MEMOIZATION

class Solution {
private:
    int solve(int n,vector<int>&db){
        if(n<=1){
            return 1;
        }
        if(db[n]!=-1){
            return db[n];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=solve(i-1,db)*solve(n-i,db);
        }
        return db[n]= ans;
    }
  public:
    
    int numTrees(int n) {
        
        vector<int>db(n+1,0);
        
        
        return solve(n,db);
    }
};

                        //TABULATION


class Solution {
public:
    int numTrees(int n) {
        vector<int>db(n+1,0);
        db[0]=db[1]=1;
        // i-> for number of nodes
        for(int i=2;i<=n;i++){
            //j->for root node
            for(int j=1;j<=i;j++){
                db[i]+=db[j-1]*db[i-j];
            }
        }
        
        return db[n];
    }
};

                        //space optimization by catalan number

class Solution {
public:
    int numTrees(int n) {
        long long catalan = 1;
        
        for(int i = 0; i < n; i++) {
            catalan = catalan * 2 * (2 * i + 1) / (i + 2);
        }
        
        return (int)catalan;
    }
};
