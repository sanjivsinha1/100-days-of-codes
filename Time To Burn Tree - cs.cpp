/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

BinaryTreeNode<int>* method(BinaryTreeNode<int>* root,unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&parent_track,int start){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* res;
    while(!q.empty()){
        BinaryTreeNode<int>* temp=q.front();
        q.pop();
        if(temp->data==start) res=temp;
        if(temp->left){
            q.push(temp->left);
            parent_track[temp->left]=temp;
        }
        if(temp->right){
            q.push(temp->right);
            parent_track[temp->right]=temp;
        }
    }
    return res;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    if(root==NULL){
        return 0;
    }
    
    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> parent_track;
    
    BinaryTreeNode<int>* target=method(root,parent_track,start);

    unordered_map<BinaryTreeNode<int>*,bool> visited;

    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    visited[target]=true;
    int count=0;
    while(!q.empty()){
        int s=q.size();
        count++;
        for(int i=0;i<s;i++){
            BinaryTreeNode<int>* temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(parent_track[temp] && !visited[parent_track[temp]]){
                q.push(parent_track[temp]);
                visited[parent_track[temp]]=true;
            }
        }
    }
    return count-1;
}
