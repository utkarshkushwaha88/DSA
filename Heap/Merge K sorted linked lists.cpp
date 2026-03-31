#include<queue>
class Solution {
  public:
  
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min heap
        }
    };
  
    Node* mergeKLists(vector<Node*>& arr) {
        
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        // push first node of each list
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != NULL){
                pq.push(arr[i]);
            }
        }
        
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while(!pq.empty()){
            Node* temp = pq.top();
            pq.pop();
            
            tail->next = temp;
            tail = tail->next;
            
            if(temp->next != NULL){
                pq.push(temp->next);
            }
        }
        
        return dummy->next;
    }
};