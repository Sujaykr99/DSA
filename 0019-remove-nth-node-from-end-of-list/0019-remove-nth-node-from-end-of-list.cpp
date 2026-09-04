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

        ListNode* temp = head;
        int count = 0;

        if (head->next == NULL && n == 1)
            return NULL;

        while (temp != NULL) {
            temp = temp->next;
            count++;
        }

        if (count == n) {
            head = head->next;
            return head;
        }
        temp = head;

        for (int i = 0; i < count - n - 1; i++) {

            temp = temp->next;
        }
        ListNode* curr = temp->next;

        temp->next = curr->next;

        return head;
    }
};