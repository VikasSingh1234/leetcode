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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast!=NULL){
            int temp =  slow->val;
            slow->val = fast->val;
            fast->val = temp;
            if(fast->next!=NULL)
                slow = fast->next;
            else
                break;
            fast = slow->next;
        }
        
        return head;
    }
};