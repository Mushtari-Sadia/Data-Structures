#include<iostream>
using namespace std;

class Node{

    public:
        Node *left;
        Node *right;
        int data;

        Node()
        {
            data = -1;
            left=right=NULL;
        }
        Node(int item)
        {
            data = item;
            left=right=NULL;
        }
};

Node* create_tree()
{
    Node* two = new Node(2);
    Node* seven = new Node(7);
    Node* nine = new Node(9);
    Node* one = new Node(1);
    Node* six = new Node(6);
    Node* eight = new Node(8);
    Node* five = new Node(5);
    Node* ten = new Node(10);
    Node* three = new Node(3);
    Node* four = new Node(4);

    two->left = seven;
    two->right = nine;

    seven->left = one;
    seven->right = six;

    six->left = five;
    six->right = ten;

    nine->right = eight;

    eight->left = three;
    eight->right = four;

    return two;
}

void pre_order(Node *node)
{
    cout << node->data << endl;

    if(node->left != NULL)
        pre_order(node->left);

    if(node->right != NULL)
        pre_order(node->right);
}

void post_order(Node *node)
{
    if(node->left != NULL)
       post_order(node->left);

    if(node->right != NULL)
       post_order(node->right);

    cout << node->data << endl;
}

void in_order(Node *node)
{
    if(node->left != NULL)
       in_order(node->left);

    cout << node->data << endl;

    if(node->right != NULL)
       in_order(node->right);
}

int main()
{
    Node *root = create_tree();
    cout << "pre-order traversal : " << endl;
    pre_order(root);
    cout << endl;

    cout << "post-order traversal : " << endl;
    post_order(root);
    cout << endl;

    cout << "in-order traversal : " << endl;
    in_order(root);
    cout << endl;

}
