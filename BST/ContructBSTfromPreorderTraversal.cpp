class Solution {
public:
    TreeNode* solve(vector<int>& preorder,long long mini,long long maxi,int &i){
        if(i>=preorder.size() || preorder[i]<mini||preorder[i]>maxi){
            return NULL;
        }
        TreeNode* temp=new TreeNode(preorder[i++]);
        
        temp->left=solve(preorder,mini,temp->val,i);
        temp->right=solve(preorder,temp->val,maxi,i);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        long long mini = LLONG_MIN;
        long long maxi = LLONG_MAX;
        int i=0;
        return solve(preorder,mini,maxi,i);
    }
};