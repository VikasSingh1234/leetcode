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
    int minDiffInBST(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> st;
        TreeNode* node = root;
        int ans = INT_MAX;
        
        while(true){
            if(node){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                values.push_back(node->val);
                node = node->right;
            }
        }
        for(auto it:values)
            cout<<it<<" ";
        int n = values.size();
        for(int i = 1;i<n;i++){
            //cout<<values[i]<<" "<<values[i-1]<<endl;
            ans = min(ans,abs(values[i]-values[i-1]));
        }
        return ans;
    }
};