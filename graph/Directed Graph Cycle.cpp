                        //METHOD1:-USING DFS

class Solution {
private:
    bool solve(int node,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &vis,unordered_map<int,bool> &dfsVis){
        vis[node]=true;
        dfsVis[node]=true;
        for(auto neighbour:adj[node]){
            if(!vis[neighbour]){
                bool cycleDetected=solve(neighbour,adj,vis,dfsVis);
                if(cycleDetected){
                    return true;
                }
            }
            else if(dfsVis[neighbour]){
                    return true;
                }
        }
        dfsVis[node]=false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int,bool> vis;
        unordered_map<int,bool>dfsVis;
        
        unordered_map<int,vector<int>> adj;
        
        for(int i=0;i<V;i++){
            vis[i] = false;
            dfsVis[i]=false;
        }
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(solve(i,adj,vis,dfsVis)){
                    return true;
                }
            }
        }
        return false;
    }
};

                    //METHOD 2:-USING BFS OR YOU MAY SAY BY KAHN'S ALGORITHM

// Thinking is that topology sorting in only applicable on DAG so if a graph is cyclic then we never get same no. of nodes in graph  or we can say that invalid topological order.

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //make adj matrix
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        //find indegree of nodes
        vector<int>indegree(V);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        //0 indegree wale node ko push karo
        queue<int> q;
        int cnt=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //do bfs
        while(!q.empty()){
            int node=q.front();
            cnt++;
            q.pop();
            for(auto neighbour:adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
            if(cnt==V){
                return false;
            }
            else{
                return true;
            }
    }
};
