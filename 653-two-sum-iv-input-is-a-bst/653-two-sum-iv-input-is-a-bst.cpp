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
    
    void helper(TreeNode* node,unordered_map<int,int> &res){
        if(node==NULL){
            return ;
        }
        
        helper(node->left,res);
        res[node->val]=1;
        helper(node->right,res);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> res;
        helper(root,res);
        
        for(auto x: res){
            if(res.find(k-x.first)!=res.end()){
                if(2*x.first!=k)
                    return true;
            }
        }
        return false;
    }
};