class Solution {
private:
    void inorder(Node* root, vector<int>& in){
        if(root == NULL) return;
        
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    
    void postorder(Node* root, vector<int>& in, int &index){
        if(root == NULL) return;
        
        postorder(root->left, in, index);
        postorder(root->right, in, index);
        
        root->data = in[index++];
    }

public:
    void convertToMaxHeapUtil(Node* root) {
        vector<int> in;
        
        // Step 1: store sorted values
        inorder(root, in);
        
        int index = 0;
        
        // Step 2: fill tree in postorder
        postorder(root, in, index);
    }
};