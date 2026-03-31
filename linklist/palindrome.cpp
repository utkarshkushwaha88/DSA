class Solution {
  public:
    bool isPalindrome(Node *head) {

        if(head == NULL || head->next == NULL)
            return true;

        Node* slow = head;
        Node* fast = head;

        // Find middle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // If odd length, skip middle
        if(fast != NULL){
            slow = slow->next;
        }

        // Reverse second half
        Node* prev = NULL;
        Node* curr = slow;

        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Compare both halves
        Node* first = head;
        Node* second = prev;

        while(second){
            if(first->data != second->data)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};