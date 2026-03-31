                        //BT
class Solution {
  public:
  
    vector<int> solve(vector<vector<int>> &adj, int n, vector<bool> &vis){
        
        queue<int> q;
        vector<int> ans;
        
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
    
    
    vector<int> bfs(vector<vector<int>> &adj) {
        
        int n = adj.size();
        vector<bool> vis(n,false);
        
        return solve(adj,n,vis);
    }
};