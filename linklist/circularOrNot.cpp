bool isCircular(Node *head) {
    
    // Empty list is considered circular
    if(head == NULL) {
        return true;
    }
    
    Node* temp = head->next;
    
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
    
    if(temp == head) {
        return true;
    }
    
    return false;
}



// 💡Idea

// Take two pointers

// slow → moves 1 step

// fast → moves 2 steps

// If the linked list has a cycle:

// They will meet at some point

// If no cycle:

// fast will reach NULL

bool isCircular(Node *head) {
    
    if(head == NULL) {
        return true;   // as per GFG convention
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        
        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps
        
        if(slow == fast) {
            return true;   // Cycle detected
        }
    }
    
    return false;  // No cycle
}

// Traversal Method	                                Floyd’s Method

// Works only if cycle connects to head	            Works for ANY cycle

// O(n) time	                                            O(n) time

// O(1) space	                                            O(1) space
// Less common in interviews	                        ⭐ Very common in interviews