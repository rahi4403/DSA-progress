class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* curr=head;//curr points to head 
       ListNode* prev=NULL;
       while(curr!=NULL){ //till it reaches the end of the list
       if(curr->next!=NULL && curr->val==curr->next->val){ //checks if the current node has a next node and if the duplicate is present
        while(curr->next!=NULL && curr->val==curr->next->val){ //same condition to keep moving the next node until these conditions come
            curr=curr->next; //keep moving curr till any of the while conditions come
        }
        if(prev==NULL){ //to check if there are no nodes before the duplicates begin
            head=curr->next; //makes head point to the node after the duplicate group
        }
        else{
            prev->next=curr->next; //when duplicate group is not at beginning,deletes the duplicate group by changing the nodes after prev(prev->nodes after duplicates instead of prev->duplicate nodes)
        }
        curr=curr->next; //first node after the duplicate groups,since we need to omit the duplicate group
        }
        else{
            prev=curr; //updation of prev
            curr=curr->next;
        }
       }
        return head; //returns the modified list
       }
    };