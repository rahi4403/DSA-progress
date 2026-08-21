class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head; //to check if there are at least k nodes,this creates a temporary pointer
        int count=0;
        while(temp!=NULL && count<k){
            temp=temp->next;//moves to the next node 
            count++;
        }
        if(count<k){ //when there are fewer nodes than the count
            return head;
        }
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        count=0;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;//this part does the reversal
            prev=curr;
            curr=next;//moves to the next node
            count++;
        } 
        if(next!=NULL){ //recursive call for other sections of the LL
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};