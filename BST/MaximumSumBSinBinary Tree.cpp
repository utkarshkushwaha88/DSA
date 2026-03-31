class Solution {
public:

    struct info{
        int mini;
        int maxi;
        int sum;
        bool isBST;
    };

    int ans = 0;

    info solve(TreeNode* root){
        if(root == NULL){
            return {INT_MAX, INT_MIN, 0, true};
        }

        info left = solve(root->left);
        info right = solve(root->right);

        info curr;

        curr.sum = left.sum + right.sum + root->val;
        curr.mini = min(root->val, left.mini);
        curr.maxi = max(root->val, right.maxi);

        if(left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini){
            curr.isBST = true;
            ans = max(ans, curr.sum);
        }
        else{
            curr.isBST = false;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};