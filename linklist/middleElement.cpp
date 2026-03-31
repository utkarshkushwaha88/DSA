/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        Node* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int middle=cnt/2 +1;
        int pos=1;
        Node* curr=head;
        while(pos!=middle){
            curr=curr->next;
            pos++;
        }
        return curr->data;
        
    }
};





//second method
int getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}
