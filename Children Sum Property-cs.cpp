bool isParentSum(Node *root){
    int sum=0;
    if(root==NULL ||(root->left==NULL&&root->right==NULL))return true;
    if(root->left!=NULL) sum+=root->left->data;
    if(root->right!=NULL) sum+=root->right->data;

    return (root->data==sum && isParentSum(root->left) && isParentSum(root->right)) ;

}
