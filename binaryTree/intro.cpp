#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};
Node* buildTree(Node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    if(root==NULL) return ;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            //purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void reverseLevelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    vector<vector<int>> levels;

    q.push(root);

    // Normal Level Order Traversal
    while(!q.empty()){
    
        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();

            level.push_back(temp->data);

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        levels.push_back(level);
    }

    // Print levels in reverse order
    for(int i = levels.size() - 1; i >= 0; i--){
        for(int val : levels[i]){
            cout << val << " ";
        }
        cout << endl;
    }
}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(Node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void buildFromLevelOrder(Node* &root){
    queue<Node*>q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->data);
        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main() {
    Node* root =NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    //creating a tree
    // root= buildTree(root);

    // //level order
    // cout<<"Printing the level order traversal output "<<endl;
    // levelOrderTraversal(root);

    // cout<<"Printing the reverse order traversal output: "<<endl;
    // reverseLevelOrder(root);
    cout<<"inorder traversal is: ";
    inorder(root);
    cout<<"postorder traversal is: ";
    postorder(root);
    cout<<"preorder traversal is : ";
    preorder(root);
    

}