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
    TreeNode* construct(vector<int> &inorder,int instart,int inend, vector<int>&postorder,int poststart,int postend, map<int,int>&mp){

        if(instart>inend || poststart>postend) return NULL;

        TreeNode* root= new TreeNode(postorder[postend]);

        int rlocation=mp[root->val];
        int betweenlength=rlocation -instart;

        root->left=construct(inorder,instart,rlocation-1,postorder,poststart,poststart+betweenlength-1,mp);

        root->right=construct(inorder,rlocation+1,inend,postorder,poststart+betweenlength,postend-1,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int instart=0, inend=inorder.size()-1;
        int poststart=0, postend=postorder.size()-1;

        map<int,int> mp;
        for(int i=0;i<=inend;i++){
            mp[inorder[i]]=i;
        }
        return construct(inorder,instart,inend,postorder,poststart,postend,mp);
    }
};
