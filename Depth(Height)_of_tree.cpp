//  FINDING THE DEPTH / HEIGHT OF THE TREE .
//      basic idea is to give out the max(ht 0f left subtree, ht of right subtree) + 1. // +1 for root node itself.

#include<iostream>
#include<algorithm>
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

int height(node *root)  {

    if(root == NULL)    {
        return 0;       //as the height of leaf node will be 0 .
    }

    int l_h = height(root->left);       //ht of left subtree.
    int r_h = height(root->right);      //ht of right subtree.

    return max(l_h,r_h) + 1 ;
}

int main()  {

    node* root = NULL;
    root = buildTree(root);

    cout<<"\n \n height of tree is : "<<height(root);

    return 0;

}
