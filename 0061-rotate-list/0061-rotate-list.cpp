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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode* curr = head;
        ListNode* end = head;
        
        while(curr){
            end = curr;
            curr = curr->next;
            n++;
        }
        
        k = k%n;
        
        if(k==0){
            return head;
        }
        
        //first n-k
        int nodes = n-k-1;
        curr = head;
        
        while(nodes--){
            curr=curr->next; 
        }
        
        end->next = head;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};