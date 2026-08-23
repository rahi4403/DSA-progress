class Solution {
public:
    ListNode* Solve(ListNode* first, ListNode* second) {
        ListNode* curr1 = first;//current node in the 1st list which moves forward
        ListNode* curr2 = second;//current node in the 2nd list which moves forward
        ListNode* next1 = curr1->next;//points to the node after curr1 in list1
        ListNode* next2 = curr2->next;//points to the node after curr2 in list2
        if (next1 == NULL) {//if list1 contains only 1 element
            curr1->next = curr2;//then connect the list1 to the list2 nodes
            return first;//return the merged list
        }
        while (next1 != NULL && curr2 != NULL) {//checks if there are still nodes in list1 and list2 contains elements as well
            if (curr2->val >= curr1->val && curr2->val <= next1->val) {//checks if the curr2 belongs b/w curr1 and next1(curr1 is still pointing to the first node of list1 and next1 moves forward in list1 so points to the next node)
                curr1->next = curr2;//first change to include curr2 b/w curr1 and next1
                next2 = curr2->next;//we also need to connect the next nodes of curr2 so that entire list is included in list1
                curr2->next = next1;//connects the next node in list2 to the next pointed node of list1
                curr1 = curr2;//curr1 shifts to curr2 so that now evaluation starts from curr2
                curr2 = next2;//moves to the next to evaluate other nodes of list2
            }
            else {//if curr2 does not belong b/w curr1 and next1
                curr1 = next1;//moving curr1 forward
                next1 = next1->next;//moving next forward too to point to the next 2 elements as curr1 and next1
                if (next1 == NULL) {//if there is not next node
                    curr1->next = curr2;//then the curr1 of list1 directly connects to the list2 since it doesnt have to check if curr2 belongs between curr1 and next1 since next1 does not exist
                    return first;
                }
            }
        }
        return first;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)//list1 empty,return list2
            return list2;
        if (list2 == NULL)//list2 empty,return list1
            return list1;
        if (list1->val <= list2->val) {//if list1 smaller,then the list1 elements come first since we need a sorted merged list
            return Solve(list1, list2);
        }
        else {
            return Solve(list2, list1);
        }
    }
};