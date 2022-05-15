// LEVEL ORDER TRAVERSAL (WITH SEPERATOR OF EACH LEVEL)

#include<iostream>
#include<queue>
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

    cout<<"enter data for inserting in the left of : "<<root->data<<endl;      
    root->left = buildTree(root->left);     //recurssive call for the left child node of curr node.
    cout<<"enter data for inserting in the right of : "<<root->data<<endl;
    root->right = buildTree(root->right);   //recurssive call for the right child node of curr node.
    return root;

}

void levelOrderTraversal(node*  root)   {
//in this function, we using NULL as a level separator. We push NULL in the queue as a level is completed.

    queue<node* > q;
    q.push(root);   //pushing rootnode int the queue first.
    q.push(NULL);   //pushing null after rootnode , as the first level is completed.

    while(!q.empty())   {

        node* temp = q.front();     //popping the front element of the q, and storing it in the temporary
        q.pop();        //node temp, so that later we can use temp to push its child in the queue.

        if(temp==NULL)  {       //case when  the front of q is NULL (i.e. current level completed)
            cout<<endl;         //using endl to change the line in the answer.
            if(!q.empty())  {   //if q is not empty (ie it has another level(s) left), pushing NULL that
                q.push(NULL);   //will indicate the end of upcoming level in the q.
            }
        }

        else    {
            cout<<temp->data<<" ";  //printing data of current temp node(freshly popped q fromnt ele)

            if(temp->left)  //pushing left child of temp node in q if it exists.
                q.push(temp->left);    
            if(temp->right) //pushing right child of temp node in q if it exists.
                q.push(temp->right);
        }
    }

}

int main()  {

    node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;

}
