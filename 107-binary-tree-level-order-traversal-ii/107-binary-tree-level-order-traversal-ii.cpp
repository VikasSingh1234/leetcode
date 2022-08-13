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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> level={};
        queue<TreeNode*> q;
        if(root==NULL){
            return v;
        }
        else{
            q.push(root);
        }
        int nodes = q.size();
        while(!q.empty()){
            if(nodes==0){
                nodes = q.size();
                v.insert(v.begin(),level);
                level = {};
            }
            else{
                TreeNode *d = q.front();
                q.pop();
                level.push_back(d->val);
                nodes--;
                if(d->left!=NULL){
                    q.push(d->left);
                }
                if(d->right!=NULL){
                    q.push(d->right);
                }
                
            }
        }
        
        v.insert(v.begin(),level);
        
        return v;
    }
};