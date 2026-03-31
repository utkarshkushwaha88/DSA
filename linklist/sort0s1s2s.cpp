
class Solution {
  public:
    Node* segregate(Node* head) {
        if(head==NULL && head->next==NULL){
            return head;
        }
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0){
                cnt0++;
            }
            else if(temp->data==1){
                cnt1++;
            }
            else if(temp->data==2){
                cnt2++;
            }
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            while(cnt0!=0){
                temp->data=0;
                cnt0--;
                temp=temp->next;
            }
            while(cnt1!=0){
                temp->data=1;
                cnt1--;
                temp=temp->next;
            }
            while(cnt2!=0){
                temp->data=2;
                cnt2--;
                temp=temp->next;
            }
        }
        return head;
    }
};