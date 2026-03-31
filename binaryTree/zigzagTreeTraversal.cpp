class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> ans(size);   
            
            for(int i = 0; i < size; i++){  
                
                Node* temp = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - 1 - i;
                ans[index] = temp->data;
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            leftToRight = !leftToRight;  
            
            for(auto i : ans){           
                result.push_back(i);
            }
        }
        
        return result;
    }
};

// Complexity	Value
// Time	O(N)
// Space	O(N)





                //when want output like[[1],[3,4]]
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> ans(size);   
            
            for(int i = 0; i < size; i++){  
                
                Node* temp = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - 1 - i;
                ans[index] = temp->data;
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            
            leftToRight = !leftToRight;  
            
            for(auto i : ans){           
                result.push_back(i);
            }
        }
        
        return result;
    }
};