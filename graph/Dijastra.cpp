class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        unordered_map<int,list<pair<int,int>>> adj;

        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});   // directed graph
        }

        vector<int> dis(V, INT_MAX);

        set<pair<int,int>> st;

        dis[0] = 0;
        st.insert({0,0});

        while(!st.empty()){

            auto top = *(st.begin());

            int nodeDistance = top.first;
            int topNode = top.second;

            st.erase(st.begin());

            for(auto neighbour : adj[topNode]){

                int node = neighbour.first;
                int weight = neighbour.second;

                if(nodeDistance + weight < dis[node]){

                    auto record = st.find({dis[node], node});

                    if(record != st.end()){
                        st.erase(record);
                    }

                    dis[node] = nodeDistance + weight;

                    st.insert({dis[node], node});
                }
            }
        }

        // convert unreachable nodes
        for(int i=0;i<V;i++){
            if(dis[i]==INT_MAX){
                dis[i] = -1;
            }
        }

        return dis;
    }
};