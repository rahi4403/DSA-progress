class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* curr = head;
        ListNode* temp = NULL;
        ListNode* before = NULL;

        // Move curr to the left position
        for(int i = 1; i < left; i++) {
            before = curr;
            curr = curr->next;
        }

        int range = right - left + 1;

        ListNode* prev = before;

        // Reverse the required portion
        for(int i = 0; i < range; i++) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        if(before == NULL) {
            head->next = curr;
            head = prev;
        }
        else {
            before->next->next = curr;
            before->next = prev;
        }

        return head;
    }
};