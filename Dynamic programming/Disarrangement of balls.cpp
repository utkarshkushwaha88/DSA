                    //BY RECURSION


class Solution {
  public:
    int countDer(int n) {
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        int ans =((n-1)*(countDer(n-1)+countDer(n-2)));
        return ans;
    }
};


                        //BY MEMOIZATION



class Solution {
private:    
    int solve(int n,vector<int>&db){
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        if(db[n]!=-1){
            return db[n];
        }
        db[n]=((n-1)*(solve(n-2,db)+solve(n-1,db)));
        return db[n];
    }
public:
    int countDer(int n) {
        vector<int>db(n+1,-1);
        solve(n,db);
    }
};



                        //TABULATION

class Solution {
public:
    int countDer(int n) {
        
        vector<int>db(n+1,-1);
        db[1]=0;
        db[2]=1;
        for(int i=3;i<=n;i++){
            db[i]=(i-1)*(db[i-2]+db[i-1]);
        }
        if(db[n]==-1)
            return 0;
        return db[n];
    }
};


                        //SPACE OPTIMIZATION


class Solution {
public:
    int countDer(int n) {
        if(n == 1)
            return 0;
        if(n == 2)
            return 1;
            
        int prev1=1;
        int prev2=0;
        for(int i=3;i<=n;i++){
            int curr=((i-1)*(prev1+prev2));
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
    }
};
