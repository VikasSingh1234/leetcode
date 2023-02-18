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
    void mirror(TreeNode* root,TreeNode* invert){
        if(root==NULL){
            return ;
        }
        if(root->left){
            invert->right = new TreeNode(root->left->val);
            mirror(root->left,invert->right);
        }
        if(root->right){
            invert->left = new TreeNode(root->right->val);
            mirror(root->right,invert->left);
        }
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        TreeNode* invert = new TreeNode(root->val);
        mirror(root,invert);
        
        return invert;
    }
};