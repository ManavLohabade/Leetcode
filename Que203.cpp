// 203. Remove Linked List Elements

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // create a dimmy head node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = dummy;
        while (curr->next != nullptr) {
            // check for the value
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};