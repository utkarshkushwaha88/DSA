class Solution {
private:
    void solve(int src,
               unordered_map<int,vector<int>>& adj,
               vector<int>& vis,
               vector<int>& parent,
               vector<int>& dist) {

        queue<int> q;
        q.push(src);

        vis[src] = 1;
        parent[src] = -1;
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto neighbour : adj[node]){
                if(!vis[neighbour]){
                    vis[neighbour] = 1;
                    parent[neighbour] = node;
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }
    }

public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

        unordered_map<int,vector<int>> adj;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);   // undirected
        }

        vector<int> vis(V,0);
        vector<int> parent(V,-1);
        vector<int> dist(V,-1);

        solve(src, adj, vis, parent, dist);

        return dist;
    }
};