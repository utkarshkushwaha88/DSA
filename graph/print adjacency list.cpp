class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        int m=edges.size();
         vector<vector<int>>ans(V);
        for(int i=0;i<m;i++){
            int u=edges[i].first;
            int v=edges[i].second;
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        return ans;
        
    }
};   