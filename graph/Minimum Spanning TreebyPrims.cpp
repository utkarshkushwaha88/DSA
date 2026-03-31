                                //METHOD->1 TIME COMPLEXITY:-O(V^2)
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>key(V,INT_MAX);
        vector<int>mst(V,false);
        vector<int>parent(V,-1);
        
        key[0]=0;
        parent[0]=-1;
        
        for(int i=0;i<V;i++){
            int mini=INT_MAX;
            int u;
            //find min wali node
            for(int j=0;j<V;j++){
                if(mst[j]==false && key[j]<mini){
                    u=j;
                    mini=key[j];
                }
            }
            //mark min wala mst true
            mst[u]=true;
            //check its adjacent nodes
            for(auto neighbour:adj[u]){
                if(mst[neighbour.first]==false && neighbour.second<key[neighbour.first]){
                    key[neighbour.first]=neighbour.second;
                    parent[neighbour.first]=u;
                }
            }
        }
        int sum=0;
        for(int i=1;i<V;i++){
           sum+=key[i];
        }
        return sum;
    }
};

                    //METHOD->2 TIME COMPLEXITY:-O(ElogV)


class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,list<pair<int,int>>> adj;
        
        // build adjacency list
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        vector<int> parent(V,-1);
        
        // min heap (key,node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        key[0] = 0;
        pq.push({0,0});
        
        while(!pq.empty()){
            
            int u = pq.top().second;
            pq.pop();
            
            if(mst[u]) continue;
            
            mst[u] = true;
            
            for(auto neighbour : adj[u]){
                
                int v = neighbour.first;
                int w = neighbour.second;
                
                if(!mst[v] && w < key[v]){
                    key[v] = w;
                    parent[v] = u;
                    
                    pq.push({key[v], v});
                }
            }
        }
        
        int sum = 0;
        for(int i=0;i<V;i++){
            sum += key[i];
        }
        
        return sum;
    }
};