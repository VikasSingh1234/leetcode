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
    TreeNode* tree(TreeNode* node,int l,int h,vector<int>& postorder, vector<int>& inorder,int &idx){
        if(l>h || idx<0){
            return NULL;
        }
        int eleidx=0;
        for(int i=0;i<postorder.size();i++){
            if(inorder[i]==postorder[idx]){
                eleidx = i;
                idx--;
                break;
            }
        } 
        
        node = new TreeNode(inorder[eleidx]);
        node->right = tree(node->right,eleidx+1,h,postorder,inorder,idx);
        node->left = tree(node->left,l,eleidx-1,postorder,inorder,idx);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = NULL;
        int idx = postorder.size()-1;
        root = tree(root,0,postorder.size()-1,postorder,inorder,idx);
        return root;
    }
};