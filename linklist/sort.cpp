class Solution {
private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        curr->next = head1 ? head1 : head2;

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {

        // Base case
        if (!head || !head->next)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split list
        prev->next = NULL;

        // Recursive sort
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge
        return merge(left, right);
    }
};


                            //METHOD2
                
class Solution {
  public:
    Node* insertionSort(struct Node* head_ref) {

        // If list is empty or has one node
        if(head_ref == NULL || head_ref->next == NULL)
            return head_ref;

        Node* sorted = NULL;   // New sorted list

        Node* curr = head_ref;

        while(curr != NULL) {

            Node* nextNode = curr->next;  // Store next node

            // Insert curr into sorted list
            if(sorted == NULL || curr->data <= sorted->data) {
                curr->next = sorted;
                sorted = curr;
            }
            else {
                Node* temp = sorted;

                while(temp->next != NULL && temp->next->data < curr->data) {
                    temp = temp->next;
                }

                curr->next = temp->next;
                temp->next = curr;
            }

            curr = nextNode;  // Move to next node
        }

        return sorted;
    }
};