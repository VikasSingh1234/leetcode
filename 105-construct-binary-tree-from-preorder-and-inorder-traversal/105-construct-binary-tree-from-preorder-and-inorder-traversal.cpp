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
    TreeNode* tree(TreeNode* node,int l,int h,vector<int>& preorder, vector<int>& inorder,int &idx){
        if(l>h){
            return NULL;
        }
        int eleidx=0;
        for(int i=0;i<preorder.size();i++){
            if(inorder[i]==preorder[idx]){
                eleidx = i;
                idx++;
                break;
            }
        } 
        
        if(eleidx>=l && eleidx<=h){
            node = new TreeNode(inorder[eleidx]);
            node->left = tree(node->left,l,eleidx-1,preorder,inorder,idx);
            node->right = tree(node->right,eleidx+1,h,preorder,inorder,idx);
        }
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = NULL;
        int idx = 0;
        root = tree(root,0,preorder.size()-1,preorder,inorder,idx);
        return root;
    }
};