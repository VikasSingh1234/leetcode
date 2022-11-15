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
    int traversal(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        
        int l = 1+traversal(node->left);
        int r = traversal(node->right);
        
        return l+r;
    }
    int countNodes(TreeNode* root) {
        return traversal(root);
    }
};