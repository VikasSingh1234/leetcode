/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void ancestor(TreeNode* node, TreeNode* search,vector<int> &v){
        
        if(node==NULL){
            return ;
        }
        if(node->val == search->val){
            v.push_back(node->val);
            return ;
        }
        v.push_back(node->val);
        if(node->val > search->val){
            ancestor(node->left,search,v);
        }
        else{
            ancestor(node->right,search,v);
        }
        return ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> v1,v2;
        ancestor(root,p,v1);
        ancestor(root,q,v2);
        int res;
        int n = min(v1.size(),v2.size());
        for(int i=0;i<n;i++){
            if(v1[i]==v2[i]){
                res = v1[i];
            }
            else{
                break;
            }
        }
        return new TreeNode(res);
    }
    
    
};