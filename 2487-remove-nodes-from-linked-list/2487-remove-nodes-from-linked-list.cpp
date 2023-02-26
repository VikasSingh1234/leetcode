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
    
    void reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward;
        
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        head = prev;
        return ;
        
    }
    ListNode* removeNodes(ListNode* head) {
        reverse(head);
        
        int m = head->val;
        ListNode* temp = head;
        
        while(temp->next!=NULL){
            if(temp->next->val<m){
                temp->next = temp->next->next;
            }
            else{
                m = temp->next->val;
                temp = temp->next;
            }
        }
        reverse(head);
        return head;
    }
};