class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        vector<int> dis(V, INT_MAX);
        dis[src] = 0;

        // Relax edges V-1 times
        for(int i = 0; i < V-1; i++){
            for(int j = 0; j < edges.size(); j++){

                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if(dis[u] != INT_MAX && dis[u] + wt < dis[v]){
                    dis[v] = dis[u] + wt;
                }
            }
        }

        // Check negative cycle
        for(int j = 0; j < edges.size(); j++){

            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dis[u] != INT_MAX && dis[u] + wt < dis[v]){
                return {-1};
            }
        }

        // Convert unreachable nodes
        for(int i = 0; i < V; i++){
            if(dis[i] == INT_MAX){
                dis[i] = 100000000;
            }
        }

        return dis;
    }
};