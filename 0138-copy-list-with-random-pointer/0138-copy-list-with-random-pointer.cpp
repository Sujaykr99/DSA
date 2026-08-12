/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
 void Insertattail(Node*&head , Node* &tail , int data){
    
   Node *newNode = new Node(data) ;

   if(head==NULL){
    head = newNode ;
    tail = newNode ;
    return ;
   }
   else {
    tail->next = newNode ;
    tail = newNode ;
   }


   }
public:
    Node* copyRandomList(Node* head) {
    
    Node * temp = head ;
    Node * clonehead = NULL ;
    Node * clonetail = NULL ;
      while(temp!=NULL){
        Insertattail(clonehead , clonetail , temp->val) ;
        temp = temp->next ;
      }

      unordered_map<Node* , Node* >oldtonew ;
      temp = head ;
      Node * orgNode = temp ;
      Node* cloneNode = clonehead ;

      while(orgNode !=NULL && cloneNode != NULL){
        oldtonew[orgNode] = cloneNode ;
        orgNode = orgNode->next ;
        cloneNode = cloneNode->next ;

      }

      orgNode = head ;
      cloneNode = clonehead ; 

      while(orgNode!=NULL){

        cloneNode->random = oldtonew[orgNode->random];
        orgNode = orgNode->next ;
        cloneNode = cloneNode->next ;
      }
   return clonehead  ;
        
    }
};