class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right)
            return head;

        ListNode *prev = nullptr;
        ListNode *curr = head;

        // Move to the left-th node
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Store pointers
        ListNode *leftPrev = prev;
        ListNode *leftNode = curr;

        // Reverse
        ListNode *next = nullptr;
        for (int i = 0; i <= right - left; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect left part
        if (leftPrev != nullptr)
            leftPrev->next = prev;
        else
            head = prev;

        // Connect right part
        leftNode->next = curr;

        return head;
    }
};