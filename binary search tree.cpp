#include<iostream>
using namespace std;

class Node
{
    public :
        int data;
        Node *left;
        Node *right;
};

class BST
{

    public :

    Node *root;
    BST()
    {
        root = NULL;
    }

    bool search(int x,Node* t)
    {
        if(!t)
            return false;
        if(x > t->data)
            search(x,t->right);
        else if(x < t->data)
            search(x,t->left);
        else
            return true;
    }

    Node* smallestNode(Node *t)
    {
        Node *temp;
        if(!t)
            return NULL;
        if(!t->left)
            return t;
        else
            return smallestNode(t->left);
    }

    Node* del(int x,Node* t)
    {
        if(!t)
            return NULL;
        if(x == t->data)
        {
            if(t->left && !t->right)
            {
                t = t->left;
            }
            else if(t->right && !t->left)
            {
                t = t->right;
            }
            else if(t->right && t->left)
            {
                Node* successor = smallestNode(t->right);
                t->data = successor->data;
                t->right = del(t->data,t->right);

            }
            else
            {
                t = NULL;
            }
        }
        else if(x < t->data)
            t->left = del(x,t->left);
        else
            t->right = del(x,t->right);

        return t;

    }


    Node* insert(int x,Node* t)
    {
        if(!t)
        {
            t = new Node;
            t->data = x;
            t->left = NULL;
            t->right = NULL;
        }
        else
        {
            if(x < t->data)
            {
                t->left = insert(x,t->left);
            }
            else if(x > t->data)
            {
                t->right = insert(x,t->right);
            }
            else
            {
                return t;
            }
        }
        return t;
    }

    void inOrderTraversal(Node *root)
    {
        if(!root)
            return;

        inOrderTraversal(root->left);

        cout << root->data << " " ;

        inOrderTraversal(root->right);
    }

    void preOrderTraversal(Node *root)
    {
        if(!root)
            return;
        cout << root->data << " " ;

        preOrderTraversal(root->left);

        preOrderTraversal(root->right);
    }

};


int main()
{
    BST tree;
    int x,choice;

    do
    {
        cout << "\n1.insert\n2.search\n3.delete\n4.inorder traversal\n5.preorder traversal\n6.exit\n";
        cin >> choice;
        if(choice==1)
        {
            cout << "insert element : " << endl;
            cin>>x;
            tree.root = tree.insert(x,tree.root);
        }
        else if(choice==2)
        {
            cout << "search element : " << endl;
            cin>>x;
            if(tree.search(x,tree.root))
            {
                cout << "****found****" << endl;
            }
            else
            {
                cout << "****not found****" << endl;
            }
        }
        else if(choice==3)
        {
            cout << "delete element : " << endl;
            cin>>x;
            tree.root = tree.del(x,tree.root);
        }
        else if(choice==4)
        {
            tree.inOrderTraversal(tree.root);
            cout << "\n";
        }
        else if(choice==5)
        {
            tree.preOrderTraversal(tree.root);
            cout << "\n";
        }

    } while(choice!=6);

}
