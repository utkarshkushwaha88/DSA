// To solve “check if edge (c, d) is a bridge” using Tarjan’s Algorithm, we use DFS with discovery time and low time.

// Idea:

// disc[u] → time when node u is first visited

// low[u] → lowest discovery time reachable from u

// An edge (u,v) is a bridge if:

// Meaning:
// v cannot reach any ancestor of u without using edge (u,v).

// Algorithm Steps

// Build adjacency list

// Run DFS

// Maintain:

// disc[]

// low[]

// parent

// During DFS check the bridge condition

// If (u,v) equals (c,d) or (d,c) and satisfies the bridge condition → return true.


class Solution {
private:
    void dfs(int node, int parent, vector<int> adj[], vector<int>& disc,
            vector<int>& low, vector<bool>& vis, int& timer,
            int c, int d, bool &ans) {

        vis[node] = true;
        disc[node] = low[node] = timer++;

        for(auto neighbour : adj[node]) {

            if(neighbour == parent)
                continue;

            if(!vis[neighbour]) {

                dfs(neighbour, node, adj, disc, low, vis, timer, c, d, ans);

                low[node] = min(low[node], low[neighbour]);

                if(low[neighbour] > disc[node]) {
                    if((node == c && neighbour == d) ||
                       (node == d && neighbour == c)) {
                        ans = true;
                    }
                }
            }
            else {
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }

public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {

        vector<int> adj[V];

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(V,-1), low(V,-1);
        vector<bool> vis(V,false);

        int timer = 0;
        bool ans = false;

        // run DFS for all components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, -1, adj, disc, low, vis, timer, c, d, ans);
            }
        }

        return ans;
    }
};
// Time Complexity

// DFS runs once:

// O(V + E)
// Important Concept

// While returning from DFS:

// low[node] = min(low[node], low[child])

// If child cannot reach an ancestor:

// low[child] > disc[node]

// Then the edge is a bridge.

// ✅ If you want, I can also show:

// The easiest intuition of disc[] and low[] (with diagram)

