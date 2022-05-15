//  PRE-ORDER TRAVERSAL ITERATIVE APPROACH, USING A STACK OF NODE* TYPE

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

void preOrderTraversal(node *root)  {

    stack<node*> s;     //creating node* type stack
    s.push(root);

    while(!s.empty())   {
        
        node *temp = s.top();
        s.pop();
        cout<<temp->data<<" ";      //as in preorder traversal, the node is printed first then l & r
        
        if(temp->right)     //as stack follows LIFO ,thus pushing right first and the on top of it left.
        s.push(temp->right);
        if(temp->left)
        s.push(temp->left);
    

    }

}

int main()  {

    node* root = NULL;
    root = buildTree(root);
    preOrderTraversal(root);
    return 0;

}
