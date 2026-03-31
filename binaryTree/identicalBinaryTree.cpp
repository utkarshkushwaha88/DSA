class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        
        // Case 1: both NULL
        if(r1 == NULL && r2 == NULL)
            return true;
        
        // Case 2: one NULL
        if(r1 == NULL || r2 == NULL)
            return false;
        
        // Case 3: value mismatch
        if(r1->data != r2->data)
            return false;
        
        // Case 4: check left and right subtree
        return isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};