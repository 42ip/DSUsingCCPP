#include <iostream>
using namespace std;
#define null NULL
 struct BStree
{
    int data;
    struct BStree *left, *right;
};

struct BStree *newnode(BStree *temp,int key)
{
    /* data */
    if (temp == NULL) 
    {
        struct BStree *temp = new struct BStree();
        temp->data = key;
        temp->left = temp -> right = NULL;
        return temp;
    }
    if(key < temp->data)
    {
        temp->left = newnode(temp->left,key);
    } else {
        temp->right = newnode(temp->right,key);
    }
    return temp;
    
};

void inorder(BStree *root) 
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root -> data << " ";
        inorder(root->right);
    }
}

int main() 
{
    struct BStree *root = NULL;
    root = newnode(root,50);
    newnode(root,30);
    newnode(root,20);
    newnode(root,40);
    newnode(root,70);
    newnode(root,60);
    inorder(root);
    
}
