class Solution {
private:
    int heightTree(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int left = heightTree(root->left);
        int right = heightTree(root->right);
        
        return max(left, right) + 1;
    }

public:
    int height(Node* root) {
        return heightTree(root)-1;
    }
};


// 🔥 Complexity

// Time: O(n)

// Space: O(h) (recursion stack)

// Worst case O(n)

// Best case O(log n)