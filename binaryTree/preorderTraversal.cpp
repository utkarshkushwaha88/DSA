/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    private:
        void preOrderTraverse(Node* root,vector<int> &v){
            if(root==NULL){
                return;
            }
            v.push_back(root->data);
            preOrderTraverse(root->left,v);
            preOrderTraverse(root->right,v);
        }
  public:
    vector<int> preOrder(Node* root) {
        vector<int> v;
        preOrderTraverse(root,v);
        return v;
        
    }
};