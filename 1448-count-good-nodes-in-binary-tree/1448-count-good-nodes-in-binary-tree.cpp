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
    int binarytree(TreeNode* node,int max){
        if(node==NULL){
            return 0;
        }
        
        if(node->val >= max){
            return (1+binarytree(node->left,node->val)+binarytree(node->right,node->val));
        }
        else{
            return (binarytree(node->left,max)+binarytree(node->right,max));
        }
        
    }
    int goodNodes(TreeNode* root) {
        
        return binarytree(root,-1e5);
    }
};