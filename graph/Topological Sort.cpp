class Solution {
private:
    void isTrue(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis,stack<int>&s){
        vis[node]=true;
        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                isTrue(neighbour,adj,vis,s);
            }
        }
        s.push(node);
        return ;
    }
  public:   
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        stack<int> s;
        vector<bool>vis(V,false);
        vector<int>ans;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                isTrue(i,adj,vis,s);
            }
        }
        while(!s.empty()){
            int temp=s.top();
            ans.push_back(temp);
            s.pop();
        }
        return ans;
    }
};



                            //BY Kahn algorithm(BFS)
// STEPS:-
// 1.find indegree of all nodes
// 2.push node in queue with 0 indegree
// 3.do BFS and insert in vector


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
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //do bfs
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto neighbour:adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        return ans;   
    }
};