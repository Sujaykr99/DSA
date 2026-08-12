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
    ListNode* solve(ListNode* left, ListNode* right) {

        ListNode* curr1 = left;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = right;

        while (next1 != NULL && curr2 != NULL) {

            if (curr1->val <= curr2->val &&
                curr2->val <= next1->val) {

                ListNode* temp = curr2->next;

                curr1->next = curr2;
                curr2->next = next1;

                curr1 = curr2;
                next1 = curr2->next;
                curr2 = temp;
            }
            else {
                curr1 = next1;
                next1 = next1->next;
            }
        }

        if (next1 == NULL) {
            curr1->next = curr2;
        }

        return left;
    }

public:
    ListNode* merge(ListNode* left, ListNode* right) {

        if (left == NULL)
            return right;

        if (right == NULL)
            return right;

        if (left->val <= right->val)
            return solve(left, right);
        else
            return solve(right, left);
    }
public:
 ListNode * findmid(ListNode* head){
         ListNode *  slow = head ;
         ListNode * fast = head->next ; 
         while(fast!=NULL && fast->next != NULL){
            fast= fast->next->next;
            
            slow = slow ->next ;
         }

       return slow ; 
    }

public:
    ListNode* sortList(ListNode* head) {

        //base case 

        if(head == NULL || head->next == NULL) return head ;

        ListNode* mid = findmid(head) ;

        ListNode* left = head ; 
        ListNode*right = mid->next ;
        mid->next = NULL ; 

        left = sortList(left) ;
        right = sortList(right) ;

        ListNode * result = merge(left , right) ;

        return result ; 

        
    }
};