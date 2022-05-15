// CRTEATING A BINARY TREE RECURSSIVELY

#include<iostream>
#include<stack>
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


void iterativePostOrderTraversal(node *root)    {

    stack<node* > s1,s2;
    s1.push(root);

    while(!s1.empty())  {
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
    while(!s2.empty())  {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }

}


int main()  {

    node* root = NULL;
    root = buildTree(root);
    iterativePostOrderTraversal(root);
    return 0;

}
