                            //RECURSION


class Solution {
private:
    int solve(vector<vector<int>>& mat,int i,int j,int &maxi){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        int right=solve(mat,i,j+1,maxi);
        int diagonal=solve(mat,i+1,j+1,maxi);
        int down=solve(mat,i+1,j,maxi);
        if(mat[i][j]==1){
            int ans=1+min(right,min(diagonal,down));
            maxi=max(ans,maxi);
            return ans;
        }
        else {
            return 0;
        }
    }
public:
    int maxSquare(vector<vector<int>>& mat) {
        int maxi=0;
        solve(mat,0,0,maxi);
        return maxi;
        
    }
};


                                //MEMOIZATION



class Solution {
private:
    int solve(vector<vector<int>>& mat,int i,int j,int &maxi,vector<vector<int>> &db){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(db[i][j]!=-1){
            return db[i][j];
        }
        int right=solve(mat,i,j+1,maxi,db);
        int diagonal=solve(mat,i+1,j+1,maxi,db);
        int down=solve(mat,i+1,j,maxi,db);
        if(mat[i][j]==1){
            int ans=1+min(right,min(diagonal,down));
            maxi=max(ans,maxi);
            return db[i][j]=ans;
        }
        else {
            return db[i][j]=0;
        }
    }
  public:
    int maxSquare(vector<vector<int>>& mat) {
        int maxi=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> db(n, vector<int>(m, -1));
        solve(mat,0,0,maxi,db);
        return maxi;
        
    }
};



                    //Tabulation


class Solution {
private:
    void solve(vector<vector<int>>& mat, int &maxi) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> db(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int right = db[i][j + 1];
                int dia = db[i + 1][j + 1];
                int bottom = db[i + 1][j];

                if (mat[i][j] == 1) {
                    db[i][j] = 1 + min(right, min(dia, bottom));
                    maxi = max(maxi, db[i][j]);
                } else {
                    db[i][j] = 0;
                }
            }
        }
    }

public:
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0;
        solve(mat, maxi);
        return maxi;   // returns side length
    }
};

                            //space optimized
                            //S.C:-O(m)

class Solution {
public:
    int maximalSquare(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();

        vector<int> next(m + 1, 0);
        vector<int> curr(m + 1, 0);

        int maxi = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];

                if (matrix[i][j] == 1) {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;  
        }

        return maxi ; 
    } 
};