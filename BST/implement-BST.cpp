#include <bits/stdc++.h>

using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* minVal(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
Node* deleteFromBST(Node* root,int val){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        //0 Child
        
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 Child
        
        //left Child
        
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right Child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2 Child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
            }
    }
    else if(root->data>val){
        //left part me jao
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        //right part me jao
        root->right=deleteFromBST(root->right,val);
        return root;
    }

}
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            //purana level complete travese ho chuka hai
            cout<<endl;
            if(!q.empty()){
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
Node* insertIntoBST(Node* root,int d){
    //base case
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d > root->data){
        //right part me insert karna hai
        root->right=insertIntoBST(root->right,d);
    }
    else{
        //left part me insert karna hai
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(Node* &root){
    int data ;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}
int main() {
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    //50 20 70 10 30 90 25 35 110 -1
    root=deleteFromBST(root,20);
    cout<<"Printing the BST after deletion"<<endl;
    levelOrderTraversal(root);b
return 0;
}