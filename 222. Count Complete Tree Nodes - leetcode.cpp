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
     int findleftheight(TreeNode* root)
    {
        int height = 0;
        while(root!=NULL)
        {
            height++;
            root=root->left;
        }
        return height;
    }
    
    int findrightheight(TreeNode* root)
    {
        int height = 0;
        while(root!=NULL)
        {
            height++;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftheight = findleftheight(root);
        int rightheight =findrightheight(root);
        //formula for complete binary tree number of nodes
        if(leftheight == rightheight) return pow(2,leftheight) -1;
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right +1;
        
    }
};
