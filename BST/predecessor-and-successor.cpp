class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;

        while(curr){

            if(curr->data < key){
                pre = curr;
                curr = curr->right;
            }

            else if(curr->data > key){
                suc = curr;
                curr = curr->left;
            }

            else{
                
                // predecessor
                Node* temp = curr->left;
                while(temp){
                    pre = temp;
                    temp = temp->right;
                }

                // successor
                temp = curr->right;
                while(temp){
                    suc = temp;
                    temp = temp->left;
                }

                break;
            }
        }

        return {pre, suc};
    }
};