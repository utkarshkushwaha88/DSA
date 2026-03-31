                            //MEMOIZATION

class Solution {
private:
    int solve(int n,int x,int y,int z,vector<int>&db){
        
        if(n == 0){
            return 0;
        }
        
        if(n < 0){
            return INT_MIN;
        }
        if(db[n]!=-1){
            return db[n];
        }

        int inclux = 1 + solve(n-x,x,y,z,db);
        int incluy = 1 + solve(n-y,x,y,z,db);
        int incluz = 1 + solve(n-z,x,y,z,db);

        db[n]=max(inclux, max(incluy, incluz));
        return db[n];
    }

public:
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int>db(n+1,-1);
        int ans = solve(n,x,y,z,db);
        
        if(ans < 0)
            return 0;

        return ans;
    }
};



                            //TABULATION

class Solution {
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int>db(n+1,INT_MIN);
        if(n==0){
            return 0;
        }
        db[0]=0;
        for(int i=1;i<=n;i++){
            if(i-x>=0)
                db[i]=max(db[i],db[i-x]+1);
            if(i-y>=0)
                db[i]=max(db[i],db[i-y]+1);
            if(i-z>=0)
                db[i]=max(db[i],db[i-z]+1);
        }
        if(db[n]<0){
            return 0;
        }
        else
            return db[n];
    }
};


// For this problem, space optimization means removing the recursion stack and solving it using Bottom-Up DP with a single array.
// We cannot reduce space below O(n) because each length 0 → n may depend on previous values.

// So the best optimized approach is Tabulation with one DP array.
// For maximize the cuts, space cannot be reduced to O(1) because:

// dp[i] depends on dp[i-x], dp[i-y], dp[i-z]

// which may be far behind in the array.