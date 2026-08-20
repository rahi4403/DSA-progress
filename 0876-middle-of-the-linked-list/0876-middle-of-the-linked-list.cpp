class Solution {
    private:
    int getLength(ListNode* head){ //this function is for traversing the entire length of the linked list to check for all the elements
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int l=getLength(head);
        int ans=(l)/2; //to get the exact middle node of the linked list 
        ListNode* temp=head; //stores so that the original copy remains unchanged
        int count=0;
        while(count<ans){
            temp=temp->next; //checks for the middle element and increases the count 
            count++;
        }
        return temp;//then returns the exact node 
    }
};