class Solution {
private:
    static int min(int a,int b){
        if(a<b){
            return a;
        }
        return b;
    }

    void dfs(int node,int parent,vector<int>&disc,vector<int>&low,
             vector<int>&vis,unordered_map<int,list<int>>&adj,
             vector<int>&ap,int &timer){

        vis[node]=1;
        disc[node]=low[node]=timer++;
        int child=0;

        for(auto nbr:adj[node]){

            if(nbr==parent){
                continue;
            }

            if(!vis[nbr]){
                dfs(nbr,node,disc,low,vis,adj,ap,timer);

                low[node]=min(low[node],low[nbr]);

                if(low[nbr] >= disc[node] && parent!=-1){
                    ap[node]=1;
                }

                child++;
            }
            else{
                low[node]=min(low[node],disc[nbr]);
            }
        }

        if(parent==-1 && child>1){
            ap[node]=1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {

        unordered_map<int,list<int>> adj;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer=0;

        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        vector<int>vis(V,0);
        vector<int>ap(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,disc,low,vis,adj,ap,timer);
            }
        }

        vector<int>ans;

        for(int i=0;i<V;i++){
            if(ap[i]==1){
                ans.push_back(i);
            }
        }

        if(ans.size()==0){
            return {-1};
        }

        return ans;
    }
};