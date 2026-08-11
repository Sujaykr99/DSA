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
 public :
  ListNode * reverse(ListNode* head)  {
     if(head == NULL ) return head ;

     ListNode * curr = head ; 
     ListNode * prev = NULL ;
     while(curr!=NULL){
        ListNode * temp = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = temp ;
     }
 return prev ;
  }
public: 
    ListNode * getMiddle(ListNode* head){
         ListNode *  slow = head ;
         ListNode * fast = head->next ; 
         while(fast!=NULL && fast->next != NULL){
            fast= fast->next->next;
            
            slow = slow ->next ;
         }

       return slow ; 
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL|| head->next == NULL) return true ;

        // step1 : get middle of data 

        ListNode * middle = getMiddle(head) ;

        //step 2: reverse from the middle ;

        ListNode * temp = middle ->next ;
        middle->next = reverse(temp) ;

        // step 3 : compare the data from head and middle->next 

        ListNode* head1 = head ; 
        ListNode* head2 = middle->next ;

        while(head2!=NULL){
            if(head1->val != head2->val){
                return false ;
                
            }
            head1= head1->next ;
            head2= head2 ->next ;

        }
       // step 4: revert the step 2 or orginal linked list(not compelsary)
        temp = middle ->next ;
        middle->next = reverse(temp) ; 

        return true ;

        
    }
};