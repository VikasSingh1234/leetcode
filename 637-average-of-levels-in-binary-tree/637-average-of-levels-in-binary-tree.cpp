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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        double sum=0;
        
        queue<TreeNode*> q;
        int k=1;
        int nodes=1;
        q.push(root);
        
        while(!q.empty()){
            
            if(k==0){
                ans.push_back(sum/nodes);
                sum = 0;
                k = q.size();
                nodes = q.size();
            }
            else{
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                k--;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        
        ans.push_back(sum/nodes);
        
        return ans;
        
    }
};