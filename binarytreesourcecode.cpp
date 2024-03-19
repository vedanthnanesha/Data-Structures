#include <iostream>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
      this->data=value;
      this->left=NULL;
      this->right=NULL;
    }
};

Node* buildtree(){
    cout<<"enter an integer"<<endl;
    int d;
    cin>>d;
    if (d==-1)
    {
        return NULL;
    }
    Node* n = new Node(d);
    n->left = buildtree();
    n->right = buildtree();
    return n;
}

void printpreorder(Node* root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);

}

void printinorder(Node* root){
   if (root==NULL){
       return;
   }
   printinorder(root->left);
   cout<<root->data<<" ";
   printinorder(root->right);

}

void printpostorder(Node* root){
   if (root==NULL){
    return;
   }
   printpostorder(root->left);
   printpostorder(root->right);
   cout<<root->data<<" ";
}

int height(Node *root){

    if (root==NULL){
        return 0;
    }

    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

int countnode(Node* root){
    if (root==NULL){
        return 0;
    }
    int l=countnode(root->left);
    int r=countnode(root->right);
    return 1+l+r;

}


int main(){
    Node* root = buildtree();
    cout<<"Preorder: ";
    printpreorder(root);

    cout<<"\nInorder: ";
    printinorder(root);

    cout<<"\nPostorder: ";
    printpostorder(root);

    cout<<"\nThe height of the tree is "<<height(root);
    cout<<"\nThe number of nodes in the tree is "<<countnode(root);

    return 0;
}
