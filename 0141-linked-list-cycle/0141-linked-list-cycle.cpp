/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
       ListNode* fast = head->next;
       ListNode* slow = head;
        
       while(slow && fast){
           if(slow==fast){
               return true;
           }
           
           slow = slow->next;
           if(fast->next==NULL)
               return false;
           else
               fast = fast->next->next;
       } 
        
        return false;
    }
};