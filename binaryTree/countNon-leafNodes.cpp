/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
class Solution {
    private:
       void totalLeaves(Node* root,int &cnt){
           if(root==NULL){
               return ;
           }
            if(root->left != NULL || root->right != NULL){
                cnt++;
            }
            totalLeaves(root->left,cnt);
            totalLeaves(root->right,cnt);
        }
  public:
    int countNonLeafNodes(Node* root) {
        int cnt=0;
        totalLeaves(root,cnt);
        return cnt;
        
        
    }
};