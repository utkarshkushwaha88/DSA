                        // TIME COMPLEXITY:-O(N)
                        // SPACE COMPLEXITY:-O(N)+O(N)=O(N)
                        
                        //METHOD 1:-BY RECURSION AND MEMOIZATION
class Solution {
private:
    int fib(int n,vector<int>&db){
        if(n==1 || n==0){
            return n;
        }
        if(db[n]!=-1){
            return db[n];
        }
        db[n]=fib(n-1,db)+fib(n-2,db);
        return db[n];
    }
public:
    int nthFibonacci(int n) {
        vector<int>dp(n+1,-1);
        return fib(n,dp);
        
        
    }
};


                        //BY TABULATION 
                        //TIME COMPLEXITY:-O(N)
                        //SPACE COMPLEXITY:-O(N)

#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin>>n;
    vector<int>db(n+1,-1);
    db[1]=1;
    db[0]=0;
    for(int i=2;i<=n;i++){
        db[i]=db[n-1]+db[n-2];
    }

return db;
}

                    //METHOD3:-SPACE OPTIMIZATION
                    //TIME COMPLEXITY:-O(N) 
                    //SPACE COMPLEXITY:-O(1)


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    prev1=1;
    prev2=0;
    int curr=0;
    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }

return curr;
}