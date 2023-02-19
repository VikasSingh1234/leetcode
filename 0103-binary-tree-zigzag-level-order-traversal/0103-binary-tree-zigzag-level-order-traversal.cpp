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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> level={};
        queue<TreeNode*> q;
        if(root==NULL){
            return v;
        }
        else{
            q.push(root);
        }
        int k = 0;
        int nodes = q.size();
        while(!q.empty()){
            if(nodes==0){
                k++;
                nodes = q.size();
                v.push_back(level);
                level = {};
            }
            else{
                TreeNode *d = q.front();
                q.pop();
                if(k%2)
                    level.insert(level.begin(),d->val);
                else
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
        
        v.push_back(level);
        return v;
    }
};