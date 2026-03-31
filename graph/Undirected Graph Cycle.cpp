
//one of the important approach  is if graph is cyclic then topological sort is definately false,that we may use to find graph is cyclic or not
                                    //METHOD 1:-By BFS


class Solution {
private:
    bool solve(int src, unordered_map<int,vector<int>>& adj, unordered_map<int,bool>& vis){
        
        queue<int> q;
        unordered_map<int,int> parent;
        
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto i : adj[node]){
                
                if(vis[i] && parent[node] != i){
                    return true;
                }
                
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                    parent[i] = node;
                }
            }
        }
        
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,bool> vis;
        unordered_map<int,vector<int>> adj;
        
        for(int i=0;i<V;i++){
            vis[i] = false;
        }
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(solve(i,adj,vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};


                            //By DFS


class Solution {
private:
    bool solve(int src,int parent, unordered_map<int,vector<int>>& adj, unordered_map<int,bool>& vis){
        vis[src]=true;
        for(auto neighbour:adj[src]){
            if(!vis[neighbour]){
                bool cycleDetected=solve(neighbour,src,adj,vis);
                if(cycleDetected){
                    return true;
                }
            }
            else if(neighbour!=parent){
                //cycle present 
                return true;
            }
        }
        return false; 
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,bool> vis;
        unordered_map<int,vector<int>> adj;
        
        for(int i=0;i<V;i++){
            vis[i] = false;
        }
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(solve(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};