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
    
    void addnode(TreeNode* node,int val,int depth){
        if(node==NULL){
            return ;
        }
        if(depth-1==1){
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            
            l->left = node->left;
            r->right = node->right;
            
            node->left = l;
            node->right = r;
            return ; 
        }
        else{
            addnode(node->left,val,depth-1);
            addnode(node->right,val,depth-1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL){
            return root;
        }
        if(depth==1){
            TreeNode* head = new TreeNode(val);
            head->left=root;
            return head;
        }
        addnode(root,val,depth);
        return root;
    }
};