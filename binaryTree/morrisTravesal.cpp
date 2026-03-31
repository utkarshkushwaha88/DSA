class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* IP=curr->left;
                while(IP->right!=NULL && IP->right!=curr){
                    IP=IP->right;
                }
                if(IP->right==NULL){
                    IP->right=curr;
                    curr=curr->left;
                }
                else{
                    IP->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
                }
        }
        return ans;
        
    }
};