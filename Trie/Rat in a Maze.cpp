class Solution {
  public:
  
    void solve(int i, int j, vector<vector<int>>& maze, int n,
               vector<string>& ans, string path,
               vector<vector<int>>& vis) {
        
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        
        vis[i][j] = 1;
        
        // Down
        if(i+1 < n && !vis[i+1][j] && maze[i+1][j] == 1){
            solve(i+1, j, maze, n, ans, path + 'D', vis);
        }
        
        // Left
        if(j-1 >= 0 && !vis[i][j-1] && maze[i][j-1] == 1){
            solve(i, j-1, maze, n, ans, path + 'L', vis);
        }
        
        // Right
        if(j+1 < n && !vis[i][j+1] && maze[i][j+1] == 1){
            solve(i, j+1, maze, n, ans, path + 'R', vis);
        }
        
        // Up
        if(i-1 >= 0 && !vis[i-1][j] && maze[i-1][j] == 1){
            solve(i-1, j, maze, n, ans, path + 'U', vis);
        }
        
        vis[i][j] = 0; // backtrack
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        vector<string> ans;
        
        if(maze[0][0] == 0) return ans;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        solve(0, 0, maze, n, ans, "", vis);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};