                                        // // Reverse of singly linkList

// # include <iostream>
// # include <math.h>
// # include <vector>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }
// };
////method1
// Node* reverseLinkList(Node* head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     Node* prev=NULL;
//     Node* curr=head;
//     Node* next=NULL;
//     while(curr!=NULL){
//         next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     return prev;
// }
////method 2
// void reverse(Node* head,Node* curr,Node* prev){
//     //base case
//     if(curr==NULL){
//         head=prev;
//         return;
//     }
//     Node* next=curr->next;
//     reverse(head,next,curr);
//     curr->next=prev;
// }
// int main() {

// return 0;
// }

                                    // // Reverse in doubly linklist
// Node* reverseDLL(Node* head) {
//     Node* temp = NULL;
//     Node* current = head;

//     // Swap next and prev pointers for all nodes
//     while (current != NULL) {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;

//         current = current->prev; // move to next node (which is previous before swapping)
//     }

//     // Update head of the reversed list
//     if (temp != NULL)
//         head = temp->prev;

//     return head;
// }
// # include <iostream>
// # include <math.h>
// # include <vector>
// using namespace std;
// int main() {
// return 0;
// }

                                    // // Middle of Linked list


//     Node* getMiddle(Node* head){
//         If(head==NULL || head->next==NULL)
//         return head;
//         Node* slow=head;
//         Node* fast=head->next;
//         while(fast!=NULL){
//             fast=fast->next;
//             if(fast!=NULL){
//                 fast=fast->next;
//             }
//             slow=slow->next;
//         }
//         return slow;
//     } 


                                // // Reverse LL in Kth group

// Node* kReverse(Node* head, int k) {
//     //base call
//     if(head == NULL) {
//         return NULL;
//     }
    
//     //step1: reverse first k nodes
//     Node* next = NULL;
//     Node* curr = head;
//     Node* prev = NULL;
//     int count= 0;
    
//     while( curr != NULL && count < k ) {
//         next = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = next;
//         count++;
//     }
    
//     //step2: Recursion dekhlega aage ka 
//     if(next != NULL) {
//         head -> next = kReverse(next,k);
//     }
    
//     //step3: return head of reversed list
//     return prev;
// }


                                    //// isCircularList or not(when there is no loop)

// bool isCircularList(Node* head){
//     //empty  list
//     if(head==NULL)
//     return true;
//     Node* temp=head;
//     while(temp->next!=NULL && temp!=head){
//         temp=temp->next;
//     }
//     if(temp==head)
//     return true;

//     return false;
// }



                                        //// Detect loop or not
                                            // // method 1
// bool detectLoop(Node* head){
//     if(head==NULL)
//         return false;
//     map<Node*,bool>visited;
//     Node* temp=head;
//     while(temp!=NULL){
//         //cycle is present 
//         if(visited[temp]==true){
//             return true;
//         }
//         visited[temp]=true;
//         temp=temp->next;
//     }
//     return false;
// }
                                                // //method 2
// bool floyddetectloop(Node*head){
//     Node* fast=head;
//     Node*slow=head;
//     while(fast!=NULL && fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//         if(fast==slow){
//             return true;
//         }
//     }
//     retutn false;
// }
                                    // //how to get starting node of loop
                                    // //because it can intersect at any point on loop
// Node* getStartingNode(Node* head){
//     if(head==NULL)
//         return NULL;

//     Node* intersection=floyddetectloop(head)//if it return point of intersection
//     Node* slow=head;
//     while(slow!=intersection){
//         slow=slow->next;
//         intersection=intersection->next;
//     }
//     return slow; 
// }
                                            // // remove loop
// void removeLoop(Node* head){
//     if(head==NULL)
//         return ;
//     Node* startofloop=getStartingNode(head);
//     Node* temp=startofloop;
//     while(temp->next!=startofloop){
//         temp=temp->next;}
//     temp->next=NULL;
// }

                                //// Remove duplicate from sorted list
// void removeDuplicate(Node* head){
//     if(head==NULL)
//         return NULL;
//     Node* curr=head;
//     while (curr->next!=NULL){
//         if(curr->data==curr->next->data){
//             Node* next_next=curr->next->next;
//             Node* nodeToDelete=curr->next;
//             delete(nodeToDelete);
//             curr->next=next_next;
//         }
//         else{
//             curr=curr->next;
//         }
//     }
//     return head;
// }

                                            // //Remove duplicate from unsorted list

//                                                             // method 1
// void removeDuplicate(Node* head){
//     Node*curr=head;
//     while(curr!=NULL){
//         Node* temp=curr->next;
//         Node* prev=curr;

//         while(temp!=NULL){
//             if(curr->data==temp->data){
//                 Node* next=temp->next;
//                 delete(temp);
//                 prev->next=next;

//             }
                // temp=temp->next;
                // prev=temp;
//         }
//     }
// }

                                    ////Split Circular Linked List into Two Circular Halves
// // Function to split the list
// void splitCircularList(Node* head, Node*& head1, Node*& head2) {
//     if (!head || head->next == head) {
//         head1 = head;
//         head2 = NULL;
//         return;
//     }

//     Node *slow = head, *fast = head;

//     // Find middle
//     while (fast->next != head && fast->next->next != head) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     head1 = head;

//     // For even number of nodes
//     if (fast->next->next == head) {
//         fast = fast->next;
//     }

//     head2 = slow->next;

//     // Make first half circular
//     slow->next = head1;

//     // Make second half circular
//     fast->next = head2;
// }


                                       //// sort 0s,1s,2s in  linklist
                                       // method 1
// void sortLink(Node* head){
//     int zeroNodes=0;
//     int oneNodes=0;
//     int twoNodes=0;
//     Node* temp=head;
//     while(temp!=NULL){
//         if(temp->data==0){
//             zeroNodes++;
//             temp=temp->next;
//         }
//         else if(temp->data==1){
//             oneNodes++;
//             temp=temp->next;
//         }
//         else if(temp->data==2){
//             twoNodes++;
//             temp=temp->next;
//         }
//     }
//     temp=head;
//     while(temp!=NULL){
//         if(zeroNodes!=0){
//             temp->data=0;
//             zeroNodes--;
//         }
//         else if(oneNodes!=0){
//             temp->data=1;
//             twoodes--;
//         }
//         else if(twoNodes!=0){
//             temp->data=2;
//             twoNodes--;
//         }
//     }
// }
                                                // method2
// void insertAtTail(Node* tail,Node* curr){
//     tail->next=curr;
//     tail=curr;
// }
// Node* sortlist(Node*head){
//     Node*zeroHead=new Node(-1);
//     Node*zeroTail=zeroHead;
//     Node*oneHead=new Node(-1);
//     Node*oneTail=oneHead;
//     Node*twoHead=new Node(-1);
//     Node*twoTail=twoHead;
//     Node* curr=head;
//     while(curr!=NULL){
//         int value=curr->data;
//         if(value==0){
//             insertAtTail(zeroTail,curr)
//         }
//         else if(value==1){
//             insertAtTail(oneTail,curr)
//         }
//         else if(value==2){
//             insertAtTail(twoTail,curr)
//         }
//         curr=curr->next;
//     }
//     //merge 3 sublist
//     //1s list not empty
//     if(oneHead->next!=NULL){
//         zeroTail->next=oneHead->next;
//     }
//     else{
//         //1s may be empty
//         zeroTail->next=twoHead->next;
//     }
//     oneTail->next=twoHead->next;
//     twoTail->next=NULL;
//     //setup head
//     head=zeroHead->next;
//     //delete dummy nodes
//     delete zeroHead;
//     return head;
// }
// // method2
// void solve(Node*first,Node*second){
//     //if onlt one element is present in first list
//     if(first->next==NULL){
//         first->next=second;
//         return first;
//     }
//     Node* curr1=first;
//     Node* next1=curr1->next;
//     Node* curr2=second;
//     Node* next2=curr2-next;
//     while(next1!=NULL && curr2!=NULL){
//         if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){
//             //add node in between the first list
//             curr1->next=curr2;
//             next2=curr2->next;
//             curr2->next=next1;
//             //update pointers
//             curr1=curr2;
//             curr2=next2;
//         }
//         else{
//             //curr1 and next1 ko aage badhana padaga
//             curr1=next1;
//             next1=next1->next;
//             if(next1==NULL){
//                 curr1->next=curr2;
//                 return first;
//             }
//         }
//     }
// }
// Node* sortTwoLists(Node*first,Node*second){
//     if(first==NULL)
//         return second;
//     if(second==NULL)
//         return first;
//     if(first->data<=second->data){
//         return solve(first,second);
//     }
//     else{
//         return solve(second,first);
//     }
// }


//                             //Palindrome

// Node*getMid(Node* head){
//     Node*slow=head;
//     Node* fast=head->next;
//     while(fast!=NULL && fast->next!=NULL){
//         fast=fast->next->next;
//         slow=slow->next;
//     }
//     return slow;
// }
// Node* reverse(Node* head){
//     Node* curr=head;
//     Node* prev=NULL;
//     Node* next=NULL;
//     while(curr!=NULL){
//         next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     return prev;
// }
// bool isPalindrome(Node* head){
//     if(head->next==NULL){
//         return true;
//     }
//     //step1->find Middle
//     Node* middle=getMid(head);
//     //step2->reverse list after middle
//     Node* temp=middle->next;
//     middle->next=reverse(temp);
//     //step3->compare both halves
//     Node* head1=head;
//     Node* head2=middle->next;
//     while(head2!=NULL){
//         if(head2->data!=head1->data){
//             return 0;
//         }
//     }
//     //step4->repeat step2
//     temp=middle->next;
//     middle->next=reverse(temp);
//     return 1;
// }

                                // // Add two numbers represented by linklist

// Node*reverse(Node*head){
//     Node* curr=head;
//     Node*prev=NULL;
//     Node*next=NULL;
//     while(curr!=NULL){
//         next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     return prev;
// }
// void inserAtTail(Node* &head,Node* &tail,int val){
//     Node*temp=new Node(val);
//     //empty list
//     if(head==NULL){
//         head=temp;
//         tail=temp;
//         return;
//     }
//     else{
//         tail->next=temp;
//         tail=temp;
//     }
// }

// Node*add(Node* first,Node*second){
//     int carry=0;
//     Node*ansHead=NULL;
//     Node*ansTail=NULL;
//     while(first!=NULL || second!=NULL || carry!=0){
//         int val1=0;
//         if(first!=NULL){
//             val1=first->data;
//         }
//         int val2=0;
//         if(second!=NULL){
//             val2=second->data;
//         }
//         int sum=carry + val1 + val2;
//         int digit=sum%10;
//         //create node and add in answer linked list
//         insertAtTail(ansHead,ansTail,digit);
//         carry=sum/10;
//         if(first!=NULL){
//             first=first->next;
//         }
//         if(second!=NULL){
//             second=second->next;
//         }
//         return ansHead;
//     }
// }
// Node* addTwoLists(Node* first,Node* second){
//     //step1-reverse input LL
//     first=reverse(first);
//     second=reverse(second);
//     //step2-add 2 LL
//     Node*ans=add(first,second);
//     //step3
//     ans=reverse(ans);
//     return ans;
// }

                                    // //clone a linklist with next and random pointer
                                    // //Method1
// void insertAtTail(Node* &head,Node* &tail,int d){
//     Node*  newNode=new Node(d);
//     if(head==NULL){
//         head=newNode;
//         tail=newNode;
//     }
//     else{
//         tail->next=newNode;
//         tail=newNode;
//     }
// }
// Node* copyList(Node*head){
//     //step1:create a clone
//     Node* cloneHead=NULL;
//     Node* cloneTail=NULL;
//     Node*temp=head;
//     while(temp!=NULL){
//         insertAtTail(cloneHead,cloneTail,temp->data);
//         temp=temp->next;
//     }
//     //step2: insert nodes of clone list in between originagl list
//     unordered_map<Node*,Node*>oldToNewNode;
//     Node* originalNode=head;
//     Node* cloneNode=cloneHead;
//     while(originalNode!=NULL){
//         oldToNewNode[originalNode]=cloneNode;
//         originalNode=originalNode->next;
//         cloneNode=cloneNode->next;
//     }
//     originalNode=head;
//     cloneNode=cloneHead;
//     while(originalNode!=NULL){
//         cloneNode->random=oldToNewNode[original->random];
//         originalNode=originalNode->next;
//         cloneNode=cloneNode->next;
//         return cloneHead;
//     }

// }
                                            // // method2
//     void insertAtTail(Node* &head, Node* &tail, int d) {
//         Node* newNode = new Node(d);
//         if(head == NULL) {
//             head = newNode;
//             tail = newNode;
//         }
//         else
//         {
//             tail -> next = newNode;
//             tail = newNode;
//         }
//     }
//     Node *copyList(Node *head)
//     {
//         //step 1: Create a Clone List
//         Node* cloneHead = NULL;
//         Node* cloneTail = NULL;
        
//         Node* temp = head;
//         while(temp != NULL) {
//             insertAtTail(cloneHead, cloneTail, temp->data);
//             temp = temp -> next;
//         }
        
//         // step 2: insert nodes of Clone List in between originalList
        
//         Node* originalNode = head;
//         Node* cloneNode = cloneHead;
        
//         while(originalNode != NULL && cloneNode != NULL) {
//             Node* next = originalNode -> next;
//             originalNode -> next = cloneNode;
//             originalNode = next;
            
//             next = cloneNode -> next;
//             cloneNode -> next = originalNode;
//             cloneNode  = next;
//         }
        
//         // step 3: Random pointer copy
//         originalNode = head;
//         cloneNode = cloneHead;
        
//         while(originalNode != NULL && cloneNode != NULL) { 
            
//             if(originalNode -> arb != NULL) {
//                 cloneNode -> arb = originalNode -> arb -> next;
//             }
//             else
//             {
//                 cloneNode -> arb  = NULL;
//             }
            
//             cloneNode = cloneNode -> next;
//             originalNode = originalNode -> next;
//         }
        
//         //step 4: revert step 2 changes
//         Node* original = head;
//         Node* copy = cloneHead;
        
//          while (original && copy)
//             {
//                 original->next =
//                  original->next? original->next->next : original->next;
//                 copy->next = copy->next?copy->next->next:copy->next;
//                 original = original->next;
//                 copy = copy->next;
//             }

//         // step 5 answer return
//         return cloneHead;
//     }
// };