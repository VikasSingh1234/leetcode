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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right || head==NULL){
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tempHead;
        ListNode* forward;
        ListNode* tail;
        int i = 1;
        
        while(left>1){
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        tempHead = prev,tail = curr;
        while(right>0){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            right--;
        }
        
        if(tempHead!=NULL){
            tempHead->next = prev;
        }
        else{
            head = prev;
        }
        
        tail->next  = curr;
        return head;
    }
};