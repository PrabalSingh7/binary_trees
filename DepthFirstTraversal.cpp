//  DEPTH-FIRST TYRAVERSALS (recurssively) :-
//       PRE-PORDER TRAVERSAL : Node left right
//       IN-PORDER TRAVERSAL :  left Node right
//       POST-PORDER TRAVERSAL : left right Node

#include<iostream>
using namespace std;

class node  {
    public:
        int data;
        node *left;
        node *right;

        node(int d)  {              //constructor 
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

node *buildTree(node *root) {      //recurssive function that will take inpuit bfrom the user and create the binary treee accordingly.

    cout<<"enter the data  : "<<endl;
    int data;
    cin>>data;
    root = new node(data);                //creating the current node 

    if(data == -1)  {           // whenever -1 is entered by the user we consider it as NULL,thus returning to prev node.
        return NULL;
    }

    cout<<"enter data for inserting in the left of "<<root->data<<endl;      
    root->left = buildTree(root->left);     //recurssive call for the left child node of curr node.
    cout<<"enter data for inserting in the right of "<<root->data<<endl;
    root->right = buildTree(root->right);   //recurssive call for the right child node of curr node.
    return root;

}

void preOrder(node* root)   {
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root)   {
    if(root==NULL)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root)   {
    if(root==NULL)
    return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main()  {

    node* root = NULL;
    root = buildTree(root);

    cout<<"PRE-ORDER TRAVERSAL : "<<endl;
    preOrder(root);
    cout<<endl;
    
    cout<<"IN-ORDER TRAVERSAL : "<<endl;
    inOrder(root);
    cout<<endl;

    cout<<"POST-ORDER TRAVERSAL : "<<endl;
    postOrder(root);
    cout<<endl;


    return 0;

}
