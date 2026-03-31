                        // when you have to reverse first
class Solution {
    
  private:
    Node* add(Node* head1, Node* head2){
    int carry = 0;
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    while(head1 != NULL || head2 != NULL || carry != 0){

        int val1 = (head1 != NULL) ? head1->data : 0;
        int val2 = (head2 != NULL) ? head2->data : 0;

        int sum = val1 + val2 + carry;

        carry = sum / 10;
        int digit = sum % 10;

        curr->next = new Node(digit);
        curr = curr->next;

        if(head1 != NULL) head1 = head1->next;
        if(head2 != NULL) head2 = head2->next;
    }

    return dummy->next;
}
    Node* reverse(Node* & head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        head1=reverse(head1);
        head2=reverse(head2);
        
        Node* ans=add(head1,head2);
        
        ans=reverse(ans);
        
        while(ans != NULL && ans->data == 0) {
        ans = ans->next;
    }

    if(ans == NULL) {
        return new Node(0);
    }

    return ans;
        
        
    }
};



                    // when it is already reversed

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = l1;  // store result head
        ListNode* prev = NULL;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL) {
            
            int sum = carry;
            
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            
            carry = sum / 10;
            int digit = sum % 10;
            
            if(l1) {
                l1->val = digit;
                prev = l1;
                l1 = l1->next;
            } else {
                prev->next = new ListNode(digit);
                prev = prev->next;
            }
            
            if(l2) l2 = l2->next;
        }
        
        if(carry) {
            prev->next = new ListNode(carry);
        }
        
        return head;
    }
};




                        //optimized in-place o(1)space


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = l1;  // store result head
        ListNode* prev = NULL;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL) {
            
            int sum = carry;
            
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            
            carry = sum / 10;
            int digit = sum % 10;
            
            if(l1) {
                l1->val = digit;
                prev = l1;
                l1 = l1->next;
            } else {
                prev->next = new ListNode(digit);
                prev = prev->next;
            }
            
            if(l2) l2 = l2->next;
        }
        
        if(carry) {
            prev->next = new ListNode(carry);
        }
        
        return head;
    }
};