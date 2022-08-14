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
    void inorder(TreeNode* node,int k,int &pk,int &ans){
        if(node==NULL){
            return ;
        }
        
        inorder(node->left,k,pk,ans);
        pk = pk+1;
        if(pk == k){
            ans = node->val;
            return ;
        }
        inorder(node->right,k,pk,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int pk = 0;
        int ans=0;
        inorder(root,k,pk,ans);
        
        return ans;
    }
};