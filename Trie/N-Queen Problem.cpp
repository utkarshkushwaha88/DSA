                    // FOR OUTPUT LIKE THIS 
                    [
//  [".Q..",
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]




class Solution {
public:

    void addSolution(vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
        vector<int> temp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 1){
                    temp.push_back(j + 1); // store column position
                }
            }
        }

        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>>& board, int n){

        int x = row;
        int y = col;

        // check same row (left side)
        while(y >= 0){
            if(board[x][y] == 1) return false;
            y--;
        }

        // upper diagonal
        x = row;
        y = col;
        while(x >= 0 && y >= 0){
            if(board[x][y] == 1) return false;
            x--;
            y--;
        }

        // lower diagonal
        x = row;
        y = col;
        while(x < n && y >= 0){
            if(board[x][y] == 1) return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n){

        if(col == n){
            addSolution(ans, board, n);
            return;
        }

        for(int row = 0; row < n; row++){

            if(isSafe(row, col, board, n)){

                board[row][col] = 1;

                solve(col + 1, ans, board, n);

                board[row][col] = 0; // backtrack
            }
        }
    }

    vector<vector<int>> nQueen(int n) {

        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;

        solve(0, ans, board, n);

        return ans;
    }
};

                                //FOR OUTPUT LIKE THIS
                               // [[2, 4, 1, 3], [3, 1, 4, 2]]
// TIME COMPLEXITY:-O(N!)
// SPACE COMPLEXITY:-O(N^2) board
// O(N) recursion
 
class Solution {
public:

    void addSolution(vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
        vector<int> temp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 1){
                    temp.push_back(j + 1); // store column position
                }
            }
        }

        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>>& board, int n){

        int x = row;
        int y = col;

        // check same row (left side)
        while(y >= 0){
            if(board[x][y] == 1) return false;
            y--;
        }

        // upper diagonal
        x = row;
        y = col;
        while(x >= 0 && y >= 0){
            if(board[x][y] == 1) return false;
            x--;
            y--;
        }

        // lower diagonal
        x = row;
        y = col;
        while(x < n && y >= 0){
            if(board[x][y] == 1) return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n){

        if(col == n){
            addSolution(ans, board, n);
            return;
        }

        for(int row = 0; row < n; row++){

            if(isSafe(row, col, board, n)){

                board[row][col] = 1;

                solve(col + 1, ans, board, n);

                board[row][col] = 0; // backtrack
            }
        }
    }

    vector<vector<int>> nQueen(int n) {

        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;

        solve(0, ans, board, n);

        return ans;
    }
};



