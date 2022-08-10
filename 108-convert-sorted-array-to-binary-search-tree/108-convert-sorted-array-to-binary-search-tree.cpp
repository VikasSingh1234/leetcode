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
    TreeNode* BalanceBST(vector<int>& nums,int l,int r){
        if(l<r){
            int mid = (l+r)/2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = BalanceBST(nums,l,mid);
            node->right = BalanceBST(nums,mid+1,r);
            
            return node;
        }
        
        return NULL;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size()/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = BalanceBST(nums,0,mid);
        root->right = BalanceBST(nums,mid+1,nums.size());
        
        return root;
    }
};