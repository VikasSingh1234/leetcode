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
    
    TreeNode* remove(TreeNode* node){
        if(node->right==NULL) return node->left;
        TreeNode* lchild = node->left;
        TreeNode* rchild = node->right;
        TreeNode* lr = rchild;
        
        while(lr->left){
            lr = lr->left;
        }
        
        lr->left = lchild;
        return rchild;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // search the node to be deleted
        
        if(root==NULL) return NULL;
        
        TreeNode* head = root;
        
        if(root->val==key) return remove(root);
        bool flag = true;
        while(root && root->val!=key){
            if(root->val > key){
                if(root->left && root->left->val==key){
                    root->left = remove(root->left);
                    return head;
                }
                else{
                    root = root->left;
                }
            }
            else {
                if(root->right!=NULL && root->right->val==key){
                    root->right = remove(root->right);
                    return head;
                }
                else{
                    root = root->right;
                }
            }
        }
        
        return head;
        
        
    }
};