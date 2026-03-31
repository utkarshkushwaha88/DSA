class Solution
{
    private:
        void insertAtTail(Node* & head,Node* &tail,int d){
            Node* newNode=new Node(d);
            if(head==NULL){
                head=newNode;
                tail=newNode;
                return;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        }x
    public:
    Node* copyList(Node *head)

    //step1:create a clone list
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    Node* temp=head;

    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    //step2: create a map
    unordered_map<Node*,Node*>oldToNewNode;

    Node*originalNode=head;
    Node* cloneNode=cloneHead;
    while(originalNode!=NULL && cloneNode!=NULL){
        oldToNewNode[originalNode]=cloneNode;
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }
    originalNode=head;
    cloneNode=cloneHead;
    while(originalNode!=NULL){
        clontNode->random=oldToNewNode [originalNode->random];
        originalNode=original->next;
        cloneNode=clone->next;
    }
    return cloneHead;  
}



                        //Method 2


class Solution {
public:
    Node* cloneLinkedList(Node* head) {

        if(head == NULL)
            return NULL;

        // STEP 1: Insert clone nodes in between
        Node* temp = head;

        while(temp != NULL) {
            Node* nextNode = temp->next;
            Node* clone = new Node(temp->data);

            temp->next = clone;
            clone->next = nextNode;

            temp = nextNode;
        }

        // STEP 2: Copy random pointers
        temp = head;

        while(temp != NULL) {
            if(temp->random != NULL)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        // STEP 3: Separate both lists
        Node* original = head;
        Node* cloneHead = head->next;
        Node* clone = cloneHead;

        while(original != NULL) {

            original->next = clone->next;

            if(clone->next != NULL)
                clone->next = clone->next->next;

            original = original->next;
            clone = clone->next;
        }

        return cloneHead;
    }
};