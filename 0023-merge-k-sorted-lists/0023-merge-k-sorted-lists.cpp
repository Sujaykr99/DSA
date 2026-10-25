class Solution {
    class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minheap;

        int k = lists.size();

        if (k == 0) {
            return NULL;
        }

        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                minheap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (minheap.size() > 0) {
            ListNode* temp = minheap.top();
            minheap.pop();

            if (temp->next != NULL) {
                minheap.push(temp->next);
            }

            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }

        return head;
    }
};