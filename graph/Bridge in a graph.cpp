class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& vis){
        vis[node] = 1;
        
        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour, adj, vis);
            }
        }
    }

public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        
        vector<int> adj[V];
        
        // build graph without edge (c,d)
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            if((u == c && v == d) || (u == d && v == c))
                continue;
                
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        
        // run DFS from c
        dfs(c, adj, vis);
        
        // check if d is reachable
        if(vis[d] == 1)
            return false;
        else
            return true;
    }
};