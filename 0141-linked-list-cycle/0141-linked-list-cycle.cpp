class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){ //empty list 
        return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
            return false;
        }
    };
    /*{
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head->next;
        while(temp!=NULL && temp!=head){ //TLE because this runs forever,but the circle can start from somewhere in the middle too
            temp=temp->next;
        }
        if(temp==head){
            return true;
        }
        return false;
    }
};*/