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
// class Solution {
// public:
// int getlength(ListNode * head){
//     int len = 0 ;
//     while(head !=NULL){
//         len++ ;
//         head = head->next ;
//     }
//     return len ;
// }
//     ListNode* middleNode(ListNode* head) {

//         int len = getlength(head) ;

//         int ans = len/2 ;

//         ListNode * temp = head ;

//         int count=0 ; 

//         while(count<ans){

//             temp = temp->next ;
//             count++ ;
//         }
//         return temp ;
//     }
// };

//approch 2

class Solution {
public:

ListNode * getmiddle(ListNode * head){

    if(head==NULL || head->next == NULL) return head ;


    if(head->next->next==NULL) return head->next ;
     
     ListNode * fast = head->next ;
     ListNode * slow = head ;

     while(fast!=NULL){
        fast = fast->next ; 

        if(fast!=NULL){
            fast = fast -> next ;

        }
        slow = slow->next ;
     }
     return slow ;
    
}
    ListNode* middleNode(ListNode* head) {
     
     return getmiddle(head) ;
       
    }
};