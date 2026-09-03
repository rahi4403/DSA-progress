class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* LA=headA;
        ListNode* LB=headB;
        while(LA!=LB){ //until they find the common node between the two lists
        if(LA==NULL){ //if list A is shorter it moves to the head of List B
            LA=headB;
        }
        else{
            LA=LA->next;//otherwise keeps moving
        }
        if(LB==NULL){ //if list b is shorter
            LB=headA;
        }
        else{
            LB=LB->next;
        }
    }
    return LB;//or return LA//returns the common node to both the lists,when LA==LB,i.e,common node found
    }
};