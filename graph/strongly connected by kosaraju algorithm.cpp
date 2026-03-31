class Solution {
private:
    void dfs(int node, unordered_map<int,vector<int>>& adj, vector<bool>& vis, stack<int>& s){
        vis[node] = true;

        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour, adj, vis, s);
            }
        }

        s.push(node);
    }

    void revDfs(int node, unordered_map<int,vector<int>>& transpose, vector<bool>& vis){
        vis[node] = true;

        for(auto nbr : transpose[node]){
            if(!vis[nbr]){
                revDfs(nbr, transpose, vis);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &edges) {

        unordered_map<int,vector<int>> adj;

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<bool> vis(V,false);
        stack<int> s;

        // Step 1: Topological sort
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj, vis, s);
            }
        }

        // Step 2: Transpose graph
        unordered_map<int,vector<int>> transpose;

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            transpose[v].push_back(u);
        }

        // Step 3: reset visited
        for(int i=0;i<V;i++){
            vis[i] = false;
        }

        int cnt = 0;

        // Step 4: DFS using stack order
        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(!vis[top]){
                cnt++;
                revDfs(top, transpose, vis);
            }
        }

        return cnt;
    }
};