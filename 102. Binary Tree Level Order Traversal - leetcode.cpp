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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //base case if root is empty
        if(root==NULL)return{};

        vector<vector<int>> ans; //to store answer 
        vector<int> level; // to store each level values 

        queue<TreeNode*>q;
        q.push(root);  // inserting the root node (first node of tree)
        q.push(NULL);  //used to indicate the whole elemnt in that level is traversed 

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            //this indicate that the level order traversal for one level is done
            if(temp==NULL){
                //adding the values we got in that level to the main answer vector
                ans.push_back(level);
                level.clear(); // clearing the vector to store next level elements

                // also if the queue is not empty meaning there are still child nodes present in it we would enter another separator in the queue
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            // else if temp is not NULL
            else{

                //inserting all the values we iterate in a single level
                level.push_back(temp->val);
                
                // also check if the left and right nodes of temp are not NULL then insert them into queue as well
                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }

            }
        }
        return ans;
    }
};
