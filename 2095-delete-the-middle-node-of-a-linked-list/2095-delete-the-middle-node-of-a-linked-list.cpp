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
private:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
        }

        return slow;
    }

public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* middle = getMiddle(head);

        ListNode* prev = head;

        while (prev->next != middle) {
            prev = prev->next;
        }

        prev->next = middle->next;

        return head;
    }
};