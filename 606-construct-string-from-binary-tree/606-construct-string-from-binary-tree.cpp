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
    
    void preorder(TreeNode* node,string &res){
        
        if(node==NULL){
            return ;
        }
        res.push_back('(');
        res+=to_string(node->val);
        if(node->left==NULL && node->right!=NULL){
            res.push_back('(');
            res.push_back(')');
            preorder(node->right,res);
            res.push_back(')');
        }
        else{
            preorder(node->left,res);
            preorder(node->right,res);
            res.push_back(')');
        }
        
    }
    string tree2str(TreeNode* root) {
        if(root==NULL)
            return "";
        string res;
        preorder(root,res);
        
        res.erase(0,1);;
        res.pop_back();
        
        return res;
    }
};