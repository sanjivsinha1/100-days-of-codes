int Floor(BinaryTreeNode<int> *node, int input)
{
		/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	int val=-1;
	while(node){
		if(node->data==input){
			return node->data;
		}
		else if(node->data<input){
			val=node->data;
			node=node->right;
		}
		else{
			node=node->left;
		}
	}
	return val;
}
