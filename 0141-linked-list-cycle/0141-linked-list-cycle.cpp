class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){ //empty list 
        return NULL;
        }
        ListNode* slow=head; //initialise 2 pointers to the same position(head)
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){ //checks if the fast has a next node and till it reaches the end of the list
            slow=slow->next; //slow moves to the next node
            fast=fast->next->next;//fast moves 2 nodes forward
            if(slow==fast){ //checks for loops,i.e,same nodes at two points so it ends up becoming a circularly linked list
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