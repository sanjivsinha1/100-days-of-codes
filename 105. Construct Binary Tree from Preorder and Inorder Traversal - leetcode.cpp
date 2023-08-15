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
    TreeNode* construct(vector<int> &preorder,int prestart,int preend, vector<int> &inorder,int instart,int inend,map<int,int> &mp){
        // this indiacte that no futher child node to add
        if(prestart>preend || instart>inend) return NULL;

        TreeNode* root= new TreeNode(preorder[prestart]);

        // rlocation tell about the location of subtree root or root location in the inorder and betweenlength tells about the number of elements between start of inorder and that root node
        int rlocation=mp[root->val];
        int betweenlength = rlocation - instart;

        root->left = construct(preorder,prestart+1,prestart+betweenlength,inorder,instart,rlocation -1,mp);
        
        root->right = construct(preorder,prestart+betweenlength+1,preend,inorder,rlocation+1,inend,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prestart = 0, preend = preorder.size()-1;
        int instart = 0, inend = inorder.size()-1;
        //map to easly find the loation of that root in the inorder
        map<int, int> mp;
        for(int i=0;i<=inend;i++){
            mp[inorder[i]]=i;
        }
        return construct(preorder,prestart,preend,inorder,instart,inend,mp);
    }

};
