/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    
private:
    void totalNode(Node* node,int &cnt){
        if(node==NULL){
            return;
        }
        cnt++;
        totalNode(node->left,cnt);
        totalNode(node->right,cnt);
    }
  public:
    int getSize(Node* node) {
        int cnt=0;
        totalNode(node,cnt);
        return cnt;
        
    }
};