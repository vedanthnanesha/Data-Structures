#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
      this->data=data;
      this->left=this->right=NULL;
    }
};

Node* add(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    else if(root->data==data){
        return root;
    }

    else if(data>root->data){
        root->right = add(root->right,data);
    }
    else {
        root->left=add(root->left,data);
    }
    return root;
}

void printinorder(Node* root){
    if(root==NULL){
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

bool search(Node* root,int key){
   Node* current;
   bool found = false;

   if (root==NULL){
    cout<<"Cannot search an empty tree"<<endl;
   }
   else{
    current = root;
    while(current!=NULL && found==false){
        if(current->data==key){
            found=true;
        }
        else if(current->data>key){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    }
    return found;
}

Node* insert(Node* root,int item){
    Node* newnode = new Node(item);
    Node* current;
    Node* trailcurrent;

    if (root==NULL){
        root=newnode;
    }
    else{
        current=root;
        while(current!=NULL){
            trailcurrent=current;
            if(current->data==item){
                cout<<"The element "<<item<<" is already present,duplicates are not allowed"<<endl;
                return root;

            }
            else if(current->data>item){
                current=current->left;
            }
            else{
                current=current->right;
            }
        }
        if(trailcurrent->data>item){
            trailcurrent->left=newnode;
        }
        else{
            trailcurrent->right=newnode;
        }

    }
    return root;
}

Node* deletenode(Node* root, int value){
    if(root==NULL){
        return root;
    }
    else if(root->data>value){
        root->left=deletenode(root->left,value);
        return root;
    }
    else if(root->data<value){
    root->right=deletenode(root->right,value);
    return root;
    }

    if(root->left==NULL){
       Node* temp = root->right;
       delete root;
       return temp;
    }
     else if(root->right==NULL){
       Node* temp = root->left;
       delete root;
       return temp;
    }
    else{
      Node* succparent=root;
      Node* succ = root->right;
      while(succ->left!=NULL){
         succparent=succ;
         succ=succ->left;
      }
      if(succparent!=root){
         succparent->left=succ->right;
      }
      else{
         succparent->right=succ->right;
      }

      root->data=succ->data;
      delete succ;
      return root;
    }




}





int main(){
    Node* root = NULL;
    int a[]={50,30,80,10,100,60,40,20,90};
    for (int x:a){
        root=add(root,x);
    }
    printinorder(root);
    cout<<endl;
    string result = search(root,1000)? "element was found" : "element was not found";
    search(root, 99) ? cout<<"found" : cout<<"not found";
    cout<<result<<endl;
    deletenode(root,20);
    printinorder(root);



    return 0;
}


