class Solution {
public:
    TreeNode* normalBst(int s,int e,vector<TreeNode*>&result){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        //TreeNode* root= new TreeNode(result[mid]);

        result[mid]->left=normalBst(s,mid-1,result);
        result[mid]->right=normalBst(mid+1,e,result);
        return result[mid];
    }
    void inorderTraversal(TreeNode* root,vector<TreeNode*>&result){
        if(root==NULL){
            return ;
        }
        inorderTraversal(root->left,result);
        result.push_back(root);
        inorderTraversal(root->right,result);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>result;
        inorderTraversal(root,result);
        int s=0;
        int e=result.size()-1;
        return normalBst(s,e,result);
    }
};