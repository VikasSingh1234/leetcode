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
    int findMax(TreeNode* root)
    {
        if (root == NULL)
            return INT_MIN;
        
        int res = root->val;
        int lres = findMax(root->left);
        int rres = findMax(root->right);
        if (lres > res)
            res = lres;
        if (rres > res)
            res = rres;
        return res;
    }
    
    
    void traversal(TreeNode* root,vector<int> graph[]){
        if(root && root->left){
            graph[root->val - 1].push_back(root->left->val - 1);
            graph[root->left->val - 1].push_back(root->val - 1);
            traversal(root->left,graph);
        }
        if(root && root->right){
            graph[root->val - 1].push_back(root->right->val - 1);
            graph[root->right->val - 1].push_back(root->val - 1);
            traversal(root->right,graph);
        }
    }
    
    
    
    int amountOfTime(TreeNode* root, int start) {
        int n = findMax(root);
        vector<int> graph[n];
        traversal(root,graph);
        
        vector<int> vis(n,0);
        vis[start-1]  = 1;
        
        queue<int> q;
        q.push(start-1);
        
        int steps = -1;
        
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                int node = q.front();
                q.pop();
                for(auto it:graph[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            steps++;
        }
        
        return steps;
    }
};