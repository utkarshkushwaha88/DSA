class Solution {
private:

    void topoSort(int node, unordered_map<int,list<pair<int,int>>> &adj,
                  stack<int> &s, vector<int> &vis) {

        vis[node] = 1;

        for(auto neighbour : adj[node]) {
            if(!vis[neighbour.first]) {
                topoSort(neighbour.first, adj, s, vis);
            }
        }

        s.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        unordered_map<int,list<pair<int,int>>> adj;

        for(int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
        }

        // Topological Sort
        vector<int> vis(V,0);
        stack<int> s;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(i,adj,s,vis);
            }
        }

        // Distance array
        vector<int> dist(V,INT_MAX);
        dist[0] = 0;

        // Relax edges using topo order
        while(!s.empty()){

            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX){

                for(auto i : adj[top]){

                    int v = i.first;
                    int weight = i.second;

                    if(dist[top] + weight < dist[v]){
                        dist[v] = dist[top] + weight;
                    }
                }
            }
        }

        // Convert unreachable nodes to -1
        for(int i=0;i<V;i++){
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};