class Solution {
private:

    static bool cmp(vector<int>&a, vector<int>&b){
        return a[2] < b[2];
    }

    void makeSet(vector<int>&parent, vector<int>&rank, int V){
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
    }

    void unionSet(int u ,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(parent,u);
        v=findParent(parent,v);

        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(), cmp);

        vector<int>parent(V);
        vector<int>rank(V);

        makeSet(parent,rank,V);

        int minWeight=0;

        for(int i=0;i<edges.size();i++){

            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            int pu = findParent(parent,u);
            int pv = findParent(parent,v);

            if(pu != pv){
                minWeight += wt;
                unionSet(pu,pv,parent,rank);
            }
        }

        return minWeight;
    }
};  