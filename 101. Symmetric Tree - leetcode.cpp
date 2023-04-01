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
    bool issame(TreeNode*p, TreeNode*q){
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p==NULL&&q!=NULL){
            return false;
        }
        if(p!=NULL&&q==NULL){
            return false;
        }

        bool left=issame(p->left,q->right);
        bool right=issame(p->right,q->left);
        bool val=p->val==q->val;
        if(left&&right&&val){
            return true;
        }
        else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return issame(root->left,root->right);
    }
};
