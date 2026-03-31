class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp{
public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
public:

    void traverse(Node* root, vector<string>& ans, string temp){
        if(root == NULL) return;
        
        // leaf node
        if(root->left == NULL && root->right == NULL){
            ans.push_back(temp);
            return;
        }
        
        traverse(root->left, ans, temp + '0');
        traverse(root->right, ans, temp + '1');
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        // Step 1: create leaf nodes
        for(int i = 0; i < N; i++){
            pq.push(new Node(f[i]));
        }
        
        // Step 2: build tree
        while(pq.size() > 1){
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();
            
            Node* newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;
            
            pq.push(newNode);
        }
        
        Node* root = pq.top();
        
        vector<string> ans;
        traverse(root, ans, "");
        
        return ans;
    }
};