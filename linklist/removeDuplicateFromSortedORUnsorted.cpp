                                    // FOR SORTED LINKLIST
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (!head) return head;

        ListNode* temp = head;
        while (temp) {
            if (temp->next && temp->val == temp->next->val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;
        
    }
};
// Complexity:

// Time: O(n)

// Space: O(1)





                            //FOR SORTED AND UNSORTED LINKLIST
                    
class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        map<int,bool> visited;
        Node* temp =head;
        Node* prev=NULL;
        while(temp!=NULL){
            if(visited[temp->data]==true){
                prev->next=temp->next;
                temp->next=NULL;
                temp=prev->next;
            }
            else{
                visited[temp->data]=true;
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};
// ⏱ Complexity:

// Time: O(n log n)
// (because map in C++ is implemented using Red-Black Tree)

// Space: O(n)
// (storing visited elements)