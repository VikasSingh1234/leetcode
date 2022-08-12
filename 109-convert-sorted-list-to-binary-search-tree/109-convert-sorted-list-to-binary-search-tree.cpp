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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tree(vector<int> v,int low,int high,TreeNode* node){
        if(low<high){
            int mid = (low+high)/2;
            node = new TreeNode(v[mid]);
            node->left = tree(v,low,mid,node->left);
            node->right = tree(v,mid+1,high,node->right);
            return node;
        }
        return NULL;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        if(head==NULL){
            return NULL;
        }
        
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }
        
        TreeNode* root = NULL;
        root = tree(v,0,v.size(),root);
        
        return root;
    }
};