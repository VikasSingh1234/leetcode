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
    map<string,int> mpp;
    string helper(TreeNode* root,vector<TreeNode*> &res){
        if(!root) return "#";
        string s = helper(root->left,res) + ',' + helper(root->right,res) + ',' + to_string(root->val);
        mpp[s] ++;
        if(mpp[s] == 2) res.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        helper(root,res);
        return res;
    }
};