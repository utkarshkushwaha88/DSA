class Solution {
public:

    bool validBST(TreeNode* root,long long min,long long max){

        if(root == NULL)
            return true;

        if(root->val <= min || root->val >= max)
            return false;

        return validBST(root->left, min, root->val) && validBST(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validBST(root, LLONG_MIN, LLONG_MAX);
    }
}; 