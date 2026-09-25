class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!= NULL && head->val==val){ //list is not empty and the current head contains value to remove
            head=head->next; //move head pointer to the next node
        }
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){ //to check if curr exists and the next node after curr exists
            if(curr->next->val==val){ //checks if the next node matches the value
                curr->next=curr->next->next;//skips the actual value to be removed,by connecting the next of curr to next-to-next of curr
            }
            else{
                curr=curr->next;//update curr
            }
        }
        return head;
    }
};