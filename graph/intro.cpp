#include <bits/stdc++.h>
using namespace std;
class graph{
    public:
        unordered_map<int,list<int>>adj;
        void addEdges(int u,int v,bool direction){
            //direction=0->undirected
            //direction=1->directed
            adj[u].push_back(v);
            if(direction==0){
                adj[v].push_back(u);
            }
        }
        void print(){
            for(auto i:adj){
                cout<<i.first<<"-> ";
                for(auto j: i.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }

};
int main() {
    graph g;
    int n;
    cout<<"Enter number of nodes "<<endl;
    cin>>n;
    int m;
    cout<<"Enter number of edges "<<endl;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdges(u,v,0);

    }
    g.print();
return 0;
}