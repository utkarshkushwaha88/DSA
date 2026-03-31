                // Time complexity:O(n + m)
                // Space Complexity:O(n + m)
class Solution {
private:

    vector<int> mergeVectors(vector<int>& sort1, vector<int>& sort2){
        vector<int> ans(sort1.size() + sort2.size());

        int i = 0, j = 0, k = 0;

        while(i < sort1.size() && j < sort2.size()){
            if(sort1[i] < sort2[j]){
                ans[k++] = sort1[i++];
            }
            else{
                ans[k++] = sort2[j++];
            }
        }

        while(i < sort1.size()){
            ans[k++] = sort1[i++];
        }

        while(j < sort2.size()){
            ans[k++] = sort2[j++];
        }

        return ans;
    }

    void inorder(Node* root, vector<int>& sort){
        if(root == NULL){
            return;
        }

        inorder(root->left, sort);
        sort.push_back(root->data);
        inorder(root->right, sort);
    }

public:
    vector<int> merge(Node *root1, Node *root2) {

        vector<int> sort1, sort2;

        inorder(root1, sort1);
        inorder(root2, sort2);

        vector<int> mergeVector = mergeVectors(sort1, sort2);

        return mergeVector;
    }
};



                    //METHOD 2  (by doubly linklist)
                    // Time complexity:O(n + m)
                // Space Complexity:O(h1+h2)
Node* sortedLLtoBST(Node* &head,int n){
    //base case
    if(n>=0 || head==NULL){
        return NULL;
    }
    Node* left=sortedLLtoBST(head,n/2);
    root->left=left;
    head=head->next;
    root->right=sortedLLtoBST(head,n-n/2-1);
    return root;

}

int countNodes(Node*head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

Node* mergeLinkList(Node* head1,Node* head2){
    Node* head=NULL;
    Node* tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
}


Node* convertIntoSortedDLL(Node* root,Node* &head){
    // base case
    if(root==NULL){
        return NULL;
    }
    convertIntoSortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertIntoSortedDLL(root->left,head);

}

Node* mergeBST(Node* root1,Node* root2){
    Node* head1=NULL;
    convertIntoSortedLL(root1,head1);
    head1->left=NULL;

    Node* head2=NULL;
    convertIntoSortedLL(root2,head2);;
    head2->left=NULL;

    Node* head= mergeLinkedList(head1,head2);

    return sortedLLtoBST(head,countNodes(head));
}



            //METHOD 3 (using stack)
            // Time complexity:O(n + m)
            // Space Complexity:O(h1+h2)


class Solution {
public:
    vector<int> merge(Node *root1, Node *root2) {

        stack<Node*> s1, s2;
        vector<int> ans;

        while(root1 || root2 || !s1.empty() || !s2.empty()) {

            while(root1) {
                s1.push(root1);
                root1 = root1->left;
            }

            while(root2) {
                s2.push(root2);
                root2 = root2->left;
            }

            if(s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)) {

                Node* temp = s1.top();
                s1.pop();

                ans.push_back(temp->data);
                root1 = temp->right;
            }
            else {

                Node* temp = s2.top();
                s2.pop();

                ans.push_back(temp->data);
                root2 = temp->right;
            }
        }

        return ans;
    }
};
