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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* even = new ListNode(0);
        ListNode* odd = new ListNode(-1);
        ListNode* eventail = even;
        ListNode* oddtail = odd;
        
        
        ListNode* temp = head;
        int idx = 1;
        while(temp){
            if((idx)%2){
                oddtail->next = temp;
                temp = temp->next;
                oddtail = oddtail->next;
                oddtail->next = NULL;
            }
            else{
                eventail->next = temp;
                temp = temp->next;
                eventail = eventail->next;
                eventail->next = NULL;
            }
            idx++;
        }
        
        even = even->next;
        odd = odd->next;
        if(odd==NULL){
            return even;
        }
        oddtail->next = even;
        
        return odd;
    }
};