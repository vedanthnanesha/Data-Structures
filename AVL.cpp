#include<bits/stdc++.h>
using namespace std;

class Node
{
        public:
        int key;
        Node *left;
        Node *right;
        int height;

        Node(int data){
            this->key=data;
            this->left=NULL;
            this->right=NULL;
            this->height=1;

    }
};

int height(Node *N)
{
        if (N == NULL)
            return 0;
        return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int getBalance(Node *N)
{
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
}


Node *rightrotation(Node *y)
{
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;

        x->height = max(height(x->left),height(x->right)) + 1;

        return x;
}

Node *leftrotation(Node *x)
{
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;

        x->height = max(height(x->left),height(x->right)) + 1;

        y->height = max(height(y->left), height(y->right)) + 1;

       return y;
}


Node* insert(Node* node, int key)
{
        if (node == NULL)
            return(new Node(key));

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left),height(node->right));


        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightrotation(node);

        if (balance < -1 && key > node->right->key)
            return leftrotation(node);
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftrotation(node->left);
            return rightrotation(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightrotation(node->right);
            return leftrotation(node);
        }
        return node;
}

Node * minvalue(Node* node)
{
    Node* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}


Node* deleteNode(Node* root, int key)
{

        if (root == NULL)
            return root;

        if ( key < root->key )
            root->left = deleteNode(root->left, key);

        else if( key > root->key )
            root->right = deleteNode(root->right, key);

        else
        {
            if( (root->left == NULL) ||
                (root->right == NULL) )
            {
                Node *temp = root->left ? root->left : root->right;

                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                *root = *temp;
                free(temp);
            }
            else
            {

                Node* temp = minvalue(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right,
                                         temp->key);
            }
        }
        if (root == NULL)
        return root;

        root->height = 1 + max(height(root->left),height(root->right));

        int balance = getBalance(root);

        if (balance > 1 &&
            getBalance(root->left) >= 0)
            return rightrotation(root);

        if (balance > 1 &&
            getBalance(root->left) < 0)
        {
            root->left = leftrotation(root->left);
            return rightrotation(root);
        }

        if (balance < -1 &&
            getBalance(root->right) <= 0)
            return leftrotation(root);

        if (balance < -1 &&
            getBalance(root->right) > 0)
        {
            root->right = rightrotation(root->right);
            return leftrotation(root);
        }

        return root;
}

void InOrder(Node *root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        cout << root->key << " ";
        InOrder(root->right);
    }
}

int main()
{

    Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 25);
    root = insert(root, 58);
    root = insert(root, 80);
    root = insert(root, 15);
    root = insert(root, 82);
    root = insert(root, 6);
    root = insert(root, 65);
    root = insert(root, 29);
    root = insert(root, 70);
    root = insert(root, 68);

    cout << "inorder traversal of the AVL tree before deletion: ";
    InOrder(root);

    root = deleteNode(root,25);
    root = deleteNode(root,80);
    root = deleteNode(root,15);
    root = deleteNode(root,65);
    root = deleteNode(root,70);

    cout << "\ninorder traversal of the AVL tree after deletion: ";
    InOrder(root);



    return 0;
}
