                    //O(h) Time and O(h) Space
class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root==NULL){
            return NULL;
        }
        if(root->data<n1->data && root->data<n2->data){
            return LCA(root->right,n1,n2);
        }
        if(root->data>n1->data && root->data>n2->data){
            return LCA(root->left,n1,n2);
        }
        return root;
    }
};


                //O(h) Time and O(1) Space

Node* LCA(Node* root, Node* n1, Node* n2) {

    while (root != nullptr) {
      
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1->data && root->data > n2->data)
            root = root->left;

        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1->data && root->data < n2->data)
            root = root->right;
        
        // Else Ancestor is found
        else
            break;
    }

    return root;
}