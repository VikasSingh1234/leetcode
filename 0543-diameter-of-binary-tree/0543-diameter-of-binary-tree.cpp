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
    int ans= -1;
public:
    int dia(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh = dia(root->left);
        int rh = dia(root->right);
        
        ans = max(ans,lh+rh);
        
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia(root);
        return ans;
    }
};