                            // Time Complexity:O(N log K)
                            // Space Complexity:O(K)

#include<limits.h>
#include<queue>
class node{
    public:
        int data;
        int row;
        int col;
        node(int d,int r,int c){
            data=d;
            row=r;
            col=c;
        }
};
class compare{
    public:
        bool operator()(node*a,node*b){
            return a->data>b->data;
        }
};
class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        int k=mat.size();
        int n=mat[0].size();
        vector<int>ans;
        int mini=INT_MAX,maxi=INT_MIN;
        priority_queue<node*,vector<node*>,compare>h;
        for(int i=0;i<k;i++){
            int element=mat[i][0];
            mini=min(mini,element);
            maxi=max(maxi,element);
            h.push(new node(element,i,0));
        }
        int start=mini,end=maxi;
        while(!h.empty()){
            node* temp=h.top();
            h.pop();
            mini=temp->data;
            if(maxi-mini<end-start){
                start=mini;
                end=maxi;
            }
            if(temp->col+1<mat[temp->row].size()){//may be all row not have same size
                maxi=max(maxi,mat[temp->row][temp->col+1]);
                h.push(new node(mat[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else{
                break;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};