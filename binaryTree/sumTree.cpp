/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
private:
    int valid(Node* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        int left=valid(root->left);
        if(left==-1)return -1;
        int right=valid(root->right);
        if(right==-1)return -1;
        if(root->data!=left+right){
            return -1;
        }
        else{
           return root->data+left+right; //Or 2* root->data;
        }
    }
  public:
    bool isSumTree(Node* root) {
        return valid(root)!=-1;
        
    }
};