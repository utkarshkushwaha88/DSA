
   //             TIME AND SPACE COMPLEXITY-->O(N) and O(H);
class Solution {
  public:
    void inorderTraversal(Node* root,vector<int>&result){
        
        if(root==NULL){
            return ;
        }
        inorderTraversal(root->left,result);
        result.push_back(root->data);
        inorderTraversal(root->right,result);
        
        
    }
    int kthSmallest(Node *root, int k) {
        vector<int>result;
        inorderTraversal(root,result);
        int size=result.size();
        if(k>size){
            return -1;
        }
        else
            return result[k-1];
        
        
    }
};



                //TIME AND SPACE COMPLEXITY -->O(N) and O(H)

int solve(BinaryTreeNode<int>*root,int &i,int k){
    //base case
    if(root==NULL){
        return -1;
    }
    //L
    int left=solve(root->left,i,k);

    if(left!=-1){
        return left;
    }
    //N
    i++;
    if(i==k){
        return root->data;
    }
    //R
    return solve(root->right,i,k);

}
int kthsmallest(BinaryTreeNode<int>*root,int k){
    int i=0;
    return solve(root,i,k);
}