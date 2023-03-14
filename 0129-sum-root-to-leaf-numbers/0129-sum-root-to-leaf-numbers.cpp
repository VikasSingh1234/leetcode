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
    void helper(TreeNode* root,string s,int &ans){
        s.push_back(root->val+'0');
        if(root->left==NULL && root->right==NULL){
            ans+=stoi(s);
            return ; 
        }
        
        if(root->left){
            helper(root->left,s,ans);
        }
        if(root->right){
            helper(root->right,s,ans);
        }
    }
    int sumNumbers(TreeNode* root) {
        string s;
        int ans = 0;
        helper(root,s,ans);
        return ans;
    }
};