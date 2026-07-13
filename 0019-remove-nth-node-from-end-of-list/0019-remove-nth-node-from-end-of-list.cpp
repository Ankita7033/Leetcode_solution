/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = 0;
        ListNode* temp = head;

        // Count nodes
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int pos = count - n + 1;

        // Delete head
        if (pos == 1) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // Reach previous node
        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        // Delete node
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};