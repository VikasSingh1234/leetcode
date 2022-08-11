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
    bool validNode(TreeNode* node,double min,double max)
    {
        if(node==NULL){
            return true;
        }   
        else{
            if(node->val <= min || node->val >= max)
                return false;
            else
                return validNode(node->left,min,node->val) && validNode(node->right,node->val,max);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return validNode(root,-2e31,2e31-1);
    }
};