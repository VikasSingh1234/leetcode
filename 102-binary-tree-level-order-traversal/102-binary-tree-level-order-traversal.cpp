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
    void levelOrderTraversal(TreeNode* node,int d,map<int,list<int>> &v1){
        if(node==NULL){
            return ;
        }
        
        v1[d].push_back(node->val);
        levelOrderTraversal(node->left,d+1,v1);
        levelOrderTraversal(node->right,d+1,v1);
        return ;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,list<int>> v;
        vector<vector<int>> ans;
        levelOrderTraversal(root,0,v);
        for(auto it: v)
        {
            vector<int> temp;
            for(auto i:it.second)
            {
                temp.push_back(i);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};


