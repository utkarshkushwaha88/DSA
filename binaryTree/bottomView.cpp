class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int,int>bottomNode;
        queue<pair<Node*,int> > q;
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* bottom=temp.first;
            int hd=temp.second;
            bottomNode[hd]=bottom->data;
            if(bottom->left){
                q.push(make_pair(bottom->left,hd-1));
            }
            if(bottom->right){
                q.push(make_pair(bottom->right,hd+1));
            }
        }
        for(auto i:bottomNode){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};