class Solution {
    private:
    int getLength(ListNode* head){
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
        int ans=(l)/2;
        ListNode* temp=head;
        int count=0;
        while(count<ans){
            temp=temp->next;
            count++;
        }
        return temp;
    }
};