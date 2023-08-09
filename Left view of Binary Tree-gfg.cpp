void  getleft(Node* root,vector<int>& ans,int level){
    if(root==NULL) return;
    
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    if(root->left){
        getleft(root->left,ans,level+1);
    }
    if(root->right){
        getleft(root->right,ans,level+1);
    }
    
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   getleft(root,ans,0);
   return ans;
}
