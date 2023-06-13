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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        
        int nA = 0, nB = 0;
        
        while(currA){
            nA++;
            currA = currA->next;
        }
        
        while(currB){
            nB++;
            currB = currB->next;
        }
        
        currA = headA;
        currB = headB;
        
        if(nA>=nB){
            int diff = nA-nB;
            
            while(diff--){
                currA = currA->next;
            }
        }
        else{
            int diff = nB-nA;
            
            while(diff--){
                currB = currB->next;
            }
        }
        
        
        while(currA && currB){
            if(currA==currB){
                break;
            }
            currA = currA->next;
            currB = currB->next;
        }
        
        return currA;
        
    }
};