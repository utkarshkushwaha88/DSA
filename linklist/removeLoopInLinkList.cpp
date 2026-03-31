public:
    void removeLoop(Node* head) {
        
        if(head == NULL || head->next == NULL) {
            return;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        // Step 1: Detect Cycle
        while(fast != NULL && fast->next != NULL) {
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                break;
            }
        }
        
        // No loop
        if(fast == NULL || fast->next == NULL) {
            return;
        }
        
        // Step 2: Find starting node of loop
        slow = head;
        
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Step 3: Find last node of loop
        Node* temp = fast;
        
        while(temp->next != slow) {
            temp = temp->next;
        }
        
        // Step 4: Break loop
        temp->next = NULL;
    }



                                         // Method 2


class Solution {
  public:
    void removeLoop(Node* head) {
        
        if(head == NULL) {
            return;
        }
        
        map<Node*, bool> visited;
        
        Node* curr = head;
        Node* prev = NULL; 
        
        while(curr != NULL) {
            
            if(visited[curr] == true) {
                prev->next = NULL;  // break loop
                return;             // stop
            }
            
            visited[curr] = true;
            prev = curr;           // FIXED
            curr = curr->next;
        }
    }
};
 