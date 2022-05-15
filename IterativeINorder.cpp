//  IN-ORDER TRAVERSAL ITERATIVE APPROACH, USING A STACK OF NODE* TYPE
//  THIS APPROACH BASIC FLOW :-
//      1. TRAVERSE IN LEFT TILL NULL(ie leaf node)
//      2. PRINT TOP OF STACK AND THEN POP IT TO A TEMP NODE AND PRINT THE VALUE OF TEMP.
//      3. NOW IF RIGHT NODE IS NOT NULL, THEN PUSH IT IN STACK AND FOLLOW STEP 1 & 2.
//


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

void inOrderTraversal(node *root)  {

    stack<node*> s;     //creating node* type stack

    while(true)   {     //this (true) will check execute till all loops are non executable
        
        if(root!=NULL)  {       //for pushing node in s, and traverse in only left as far as possible
            s.push(root);
            root = root->left;
        }
        else{       //execute when leftest node is null 
            if(s.empty())       
                break;
            node *temp = s.top();       //popping top node in s and storing it in temp
            s.pop();
            cout<<temp->data<<" ";      //pribnt the freshly popped nodes data
            root = temp->right;         //traverse one node in right(then condition will be checked for left)
        }                               //if left is present then traverse again in left till null and if not            
                                        //present then again one node in right , as per the princilpe LNR.             
    }

}

int main()  {

    node* root = NULL;
    root = buildTree(root);
    inOrderTraversal(root);
    return 0;

}
