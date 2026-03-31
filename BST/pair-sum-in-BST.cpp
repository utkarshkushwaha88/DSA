class Solution {
private:
    void inorderTraversal(Node*root,vector<int>&result){
        if(root==NULL){
            return ;
        }
        inorderTraversal(root->left,result);
        result.push_back(root->data);
        inorderTraversal(root->right,result);
    }
  public:
    bool findTarget(Node *root, int target) {
        vector<int>result;
        inorderTraversal(root,result);
        int i=0;
        int j=result.size()-1;
        int sum=0;
        while(i<j){
            sum=result[i]+result[j];
            if(sum==target){
                return true;
            }
            else if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};