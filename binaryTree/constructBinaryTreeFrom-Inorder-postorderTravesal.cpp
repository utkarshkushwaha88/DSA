class Solution {
public:
    TreeNode* solve(vector<int>& inorder,
                    vector<int>& postorder,
                    int& index,
                    int inorderStart,
                    int inorderEnd,
                    unordered_map<int,int>& nodeToIndex) {
        
        // Base Case
        if (index < 0 || inorderStart > inorderEnd)
            return NULL;

        // Step 1: Pick root from postorder
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        // Step 2: Find position in inorder
        int position = nodeToIndex[element];

        // Step 3: Build Right Subtree First
        root->right = solve(inorder, postorder, index,
                            position + 1, inorderEnd,
                            nodeToIndex);

        // Step 4: Build Left Subtree
        root->left = solve(inorder, postorder, index,inorderStart, position - 1,nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int n = inorder.size();
        int postIndex = n - 1;

        unordered_map<int,int> nodeToIndex;

        // Create mapping
        for (int i = 0; i < n; i++)
            nodeToIndex[inorder[i]] = i;

        return solve(inorder, postorder, postIndex,0, n - 1, nodeToIndex);
    }
};

// ✅ Time Complexity
// O(n)

// Each node processed once

// Hash lookup O(1)

// ✅ Space Complexity
// O(n)

// Recursion stack (worst case skewed tree)

// Hash map storage