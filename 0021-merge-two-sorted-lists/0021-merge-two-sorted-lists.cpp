class Solution {

public:

    ListNode* Solve(ListNode* first, ListNode* second) {

        ListNode* curr1 = first;
        ListNode* curr2 = second;

        ListNode* next1 = curr1->next;
        ListNode* next2 = curr2->next;

        // If first list has only one node
        if (next1 == NULL) {
            curr1->next = curr2;
            return first;
        }

        while (next1 != NULL && curr2 != NULL) {

            if (curr2->val >= curr1->val &&
                curr2->val <= next1->val) {

                // Insert curr2 between curr1 and next1
                curr1->next = curr2;

                // Save next node of second list
                next2 = curr2->next;

                // Connect curr2 to next1
                curr2->next = next1;

                // Move curr1 forward
                curr1 = curr2;

                // Move curr2 forward
                curr2 = next2;
            }

            else {

                // Move forward in first list
                curr1 = next1;
                next1 = next1->next;

                // Reached end of first list
                if (next1 == NULL) {
                    curr1->next = curr2;
                    return first;
                }
            }
        }

        return first;
    }


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        // Make sure first starts with smaller value
        if (list1->val <= list2->val) {
            return Solve(list1, list2);
        }
        else {
            return Solve(list2, list1);
        }
    }
};