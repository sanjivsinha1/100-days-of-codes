/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(temp->val)+',');
            }
            if(temp!=NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        //StringStream in C++ allows performing insertion, extraction, and other operations
        stringstream s(data);
        string str;
        //this will get the words and ',' act as a seprator and will take one word or element at a time and when called again it will take the next element
        getline(s,str,',');
        //stoi will convert the string to intiger
        TreeNode* root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                temp->left=NULL;
            }
            else{
                TreeNode* k=new TreeNode(stoi(str));
                temp->left=k;
                q.push(k);;
            }
            getline(s,str,',');
            if(str=="#"){
                temp->right=NULL;
            }
            else{
                TreeNode* k=new TreeNode(stoi(str));
                temp->right=k;
                q.push(k);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
