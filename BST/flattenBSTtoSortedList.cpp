class Solution {
private:
    void inorderTraversal(Node* root,vector<int>&result){
        if(root==NULL){
            return ;
        }
        inorderTraversal(root->left,result);
        result.push_back(root->data);
        inorderTraversal(root->right,result);
    }
  public:
    Node *flattenBST(Node *root) {
        vector<int>result;
        inorderTraversal(root,result);
        Node* rootNode=new Node(result[0]);
        Node* curr=rootNode;
        int n=result.size();
        for(int i=1;i<n;i++){
            Node* temp=new Node(result[i]);
            curr->right=temp;
            curr->left=NULL;
            curr=temp;
        }
        curr->left=NULL;
        curr->right=NULL;
        return rootNode;
        
    }
}; 