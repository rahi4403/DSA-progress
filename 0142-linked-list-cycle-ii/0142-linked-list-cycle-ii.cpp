class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;//moving back slow to head or starting of the list 
                while(fast!=slow){//we need to keep moving until both fast and slow meet each other again,which will be our meeting point
                slow=slow->next;
                fast=fast->next;
                }
                return slow;//meeting point of the cycle
            }
        }
        return NULL; //if list is empty
    }
};