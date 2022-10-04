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
    bool sum(TreeNode* node, int t){
        
        if(node->left==NULL && node->right==NULL){
            if(t==node->val){
                return true;
            }
            else{
                return false;
            }
        }
        if(node->left!=NULL && node->right!=NULL){
            return (sum(node->left,t - node->val)||sum(node->right,t - node->val));
        }
        else if(node->left!=NULL){
            return sum(node->left,t-node->val);
        }
        else{
            return sum(node->right,t-node->val);
        }
        
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        
        return sum(root,targetSum);
    }
};