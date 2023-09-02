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

class BSTIterator {
    stack<TreeNode*> mystack;
    bool reverse;
    public: 
        BSTIterator(TreeNode* root,bool isReverse){
            reverse = isReverse;
            pushAll(root);
        }
        
        int next(){
            TreeNode* temp = mystack.top();
            mystack.pop();
            
            if(reverse){
                pushAll(temp->left);
            }
            else{
                pushAll(temp->right);
            }
            return temp->val;
        }
    
    private:
        void pushAll(TreeNode* root){
            while(root){
                mystack.push(root);
                if(reverse){
                    root = root->right;
                }
                else{
                    root = root->left;
                }
            }
        }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        
        while(i<j){
            if(i+j==k){
                return true;
            }
            (i+j) < k ? i = l.next():j = r.next(); 
        }
        
        return false;
        
    }
};