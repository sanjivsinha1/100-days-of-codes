/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //this function is used to store all the parents so to help in reverse traversal of the tree
    void method(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                parent_track[temp->left] = temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent_track[temp->right] = temp;
            }
        }
    }
    //approach we will traverse from target node to all the direction even upwords and count will tell the distance covered
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        //to store all nodes parents
        unordered_map<TreeNode*,TreeNode*>parent_track;
        method(root,parent_track);
        //to keep track of nodes already visited
        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int count = 0;

        while(!q.empty()){
            int s = q.size();
            if(count == k) break;
            count++;
            for(int i = 0; i < s; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parent_track[temp] && !visited[parent_track[temp]]){
                    q.push(parent_track[temp]);
                    visited[parent_track[temp]] = true;
                }
            }
        }
        //all the left values in the queue will have the K distance 
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            ans.push_back(current->val);
        }
        
        return ans;
    }
};
