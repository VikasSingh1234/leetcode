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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        if(head==NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast){
            st.push(slow->val);
            // cout<<"Push"<<slow->val<<endl;
            if(fast->next==NULL)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        while(slow){
            if(slow->val == st.top()){
                // cout<<"Pop"<<st.top()<<endl;
                st.pop();
                slow = slow->next;
            }
            else
                break;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};