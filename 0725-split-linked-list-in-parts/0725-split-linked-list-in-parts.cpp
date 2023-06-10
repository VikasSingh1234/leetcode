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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        
        ListNode* temp = head;
        int n = 0;
        
        while(temp){
            temp = temp->next;
            n++;
        }
        
        int parts = n/k;
        int left = n%k;
        temp  = head;
        ListNode* prev = temp;
        
        for(int i=0;i<k;i++){
            ans.push_back(temp);
            
            for(int j=0;j<parts;j++){
                if(temp){
                    prev = temp;
                    temp = temp->next;
                }
            }
            
            if(left && temp){
                prev = temp;
                temp = temp->next;
                left--;
            }
            
            if(prev){
                prev->next=NULL;
            }
        }
        return ans;
    }
};