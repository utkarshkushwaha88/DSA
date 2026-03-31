
                    //basic to understand but gives TLE
class Solution {
  public:
  bool isSafe(int row,int col,vector<vector<int>>&board,int val,int n){
    for(int i=0;i<n;i++){
        //row check
        if(board[row][i]==val){
            return false;
        }
        //col check
        if(board[i][col]==val){
            return false;
        }
        //3x3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&board){
    int n=board.size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            //cell empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val,n)){
                        board[row][col]=val;
                        //recursive call
                        bool aageSolutionPossible=solve(board);
                        if(aageSolutionPossible){
                            return true;
                        }
                        else{
                            //backtracking
                            board[row][col]=0;
                        }
                    }
                }
                return false; 
                
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<int>> &mat) {
        
        solve(mat);
    }
};



                            //Method 2

class Solution {
public:

    bool solve(vector<vector<int>>& board,
               vector<vector<int>>& row,
               vector<vector<int>>& col,
               vector<vector<int>>& box)
    {
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){

                if(board[r][c]==0){

                    for(int num=1;num<=9;num++){

                        int boxIndex = (r/3)*3 + c/3;

                        if(!row[r][num] && !col[c][num] && !box[boxIndex][num]){

                            board[r][c]=num;

                            row[r][num]=1;
                            col[c][num]=1;
                            box[boxIndex][num]=1;

                            if(solve(board,row,col,box))
                                return true;

                            board[r][c]=0;

                            row[r][num]=0;
                            col[c][num]=0;
                            box[boxIndex][num]=0;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<int>> &mat) {

        vector<vector<int>> row(9, vector<int>(10,0));
        vector<vector<int>> col(9, vector<int>(10,0));
        vector<vector<int>> box(9, vector<int>(10,0));

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){

                if(mat[r][c]!=0){

                    int num=mat[r][c];
                    int boxIndex=(r/3)*3 + c/3;

                    row[r][num]=1;
                    col[c][num]=1;
                    box[boxIndex][num]=1;
                }
            }
        }

        solve(mat,row,col,box);
    }
};