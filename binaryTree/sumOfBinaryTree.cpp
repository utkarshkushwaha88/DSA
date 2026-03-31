/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
private:
    void  sumBTree(Node* root,int &sum){
        if(root==NULL){
            return;
        }
        sum=sum+root->data;
        sumBTree(root->left,sum);
        sumBTree(root->right,sum);
    }
  public:
    int sumBT(Node* root) {
        int sum =0;
        sumBTree(root,sum);
        return sum;
        
    }
};