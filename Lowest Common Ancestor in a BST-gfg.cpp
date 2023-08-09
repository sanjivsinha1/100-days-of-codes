class Solution{
    public:
    //The function LCA takes three arguments: a pointer to the root of the BST (Node *root), and two integer values representing the values of the nodes for which we want to find the LCA (int n1 and int n2).
        Node* LCA(Node *root, int n1, int n2)
        {
            // The first condition if (root == NULL) checks if the current node being examined is NULL (i.e., we have reached a leaf node or an empty subtree). If it is NULL, the function returns NULL, indicating that no LCA exists
            if(root==NULL)
               return root;
               
            //The next two conditions compare the values n1 and n2 with the value of the current root->data, which is the value of the current node being examined. if (n1 > root->data && n2 > root->data) checks if both n1 and n2 are greater than the current node's value. If so, it means both nodes are in the right subtree of the current node. In this case, the function recursively calls itself with the right child of the current node: LCA(root->right, n1, n2). This step continues the search in the right subtree.

            //else if (n1 < root->data && n2 < root->data) checks if both n1 and n2 are less than the current node's value. If so, it means both nodes are in the left subtree of the current node. In this case, the function recursively calls itself with the left child of the current node: LCA(root->left, n1, n2). This step continues the search in the left subtree.
            
             if(n1>root->data && n2>root->data)
               LCA(root->right,n1,n2);
            else if(n1<root->data && n2<root->data)
               LCA(root->left,n1,n2);
            
            //If neither of the above conditions is satisfied, it means that one of the nodes lies in the left subtree and the other lies in the right subtree of the current node. This is the point where the LCA is found. The code returns root, which is the lowest common ancestor of nodes with values n1 and n2.
            
            else
              return root;
        }

};
