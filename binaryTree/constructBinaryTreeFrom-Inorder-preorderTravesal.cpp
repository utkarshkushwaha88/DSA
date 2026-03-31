class Solution {
private:
    void createMapping(vector<int> &in,unordered_map<int,int>&nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
    }
    Node* solve(vector<int> &in,vector<int>&pre,int &index,int inorderStart,int inorderEnd,int n,unordered_map<int,int>&nodeToIndex){
        if((index==n)||(inorderStart>inorderEnd)){
            return NULL;
        }
        int element=pre[index++];
        Node* root=new Node(element);
        int position=nodeToIndex[element];
        
        root->left=solve(in,pre,index,inorderStart,position-1,n,nodeToIndex);
        root->right=solve(in,pre,index,position+1,inorderEnd,n,nodeToIndex);
        
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n=inorder.size();
        int preOrderIndex=0;
        unordered_map<int,int>nodeToIndex;
        createMapping(inorder,nodeToIndex,n);
        
        Node* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
        
        
    }
};