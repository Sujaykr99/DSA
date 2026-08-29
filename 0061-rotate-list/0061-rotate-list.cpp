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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* count = head;

        int n = 1;

        while (count->next != NULL) {
            count = count->next;
            n++;
        }

        k = k % n;

        if (k == 0) {
            return head;
        }
        
        count->next = head;

        ListNode* temp = head;

        for (int i = 1; i < n - k; i++) {

            temp = temp->next;
        }

        head = temp->next;

        temp->next = NULL;

        return head;
    }
};