class Solution {
private:
    void isTrue(Node* root,int key,bool &result){
        if(root==NULL){
            return;
        }
        if(root->data==key){
            result=true;
            return;
        }
        if(root->data<key){
            isTrue(root->right,key,result);
        }
        if(root->data>key){
            isTrue(root->left,key,result);
        }
        return;
    }
  public:
    bool search(Node* root, int key) {
        // code here
        bool result=false;
         isTrue(root,key,result);
         if(result){
             return true;
         }
         else{
             return false;
         }
    }
};