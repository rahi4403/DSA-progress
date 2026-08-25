class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head; //reversing function to reverse the LL since we add from right side in general
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void insertAtTail(ListNode*& head, ListNode*& tail, int value) { //to create a new node and add it to the end of a LL
        ListNode* temp = new ListNode(value);//creating a new node
        if (head == NULL) {
            head = temp; //if list is empty,the new node becomes the head
            tail = temp;//and also becomes the tail
            return;
        }
        tail->next = temp; //if the list is not empty,the old list is connected to the new node
        tail = temp;//assigns tail to the new last node
    }
    ListNode* addList(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ansHead = NULL; //points to the beginning of the LL
        ListNode* ansTail = NULL;//points to the end of the LL
        while (l1 != NULL || l2 != NULL || carry != 0) { //the addition should continue in case any of these is true,l1 has nodes left or l2 has nodes left or there is still a carry 
            int val1 = 0;
            if (l1 != NULL) //if l1 has a node
                val1 = l1->val; //takes the value from that node in the LL
            int val2 = 0;
            if (l2 != NULL)
             val2 = l2->val; //same with l2
            int sum = carry + val1 + val2; //performs the addition with those values
            int digit = sum % 10; //gets the last digit of the sum so that its stored first in the answer list
            insertAtTail(ansHead, ansTail, digit); //the digit is added to the last of the answer list
            carry = sum / 10; //moves to the next position of the sum 
            if (l1 != NULL) //if l1 still has a node
                l1 = l1->next; //it moves to the next node,i.e,updates the position
         if (l2 != NULL)
                l2 = l2->next;//same with l2
        }
        return ansHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1); //first reverses the 2 lists
        l2 = reverse(l2);
        ListNode* ans = addList(l1, l2); //adds the nodes
        ans = reverse(ans);//reverses the ans back to get the original order 
        return ans;
    }
};