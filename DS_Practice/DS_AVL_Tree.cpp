#include <iostream>
using namespace std;

class Node
{
    int key;
    Node *left;
    Node *right;
    Node() : key(key), left(nullptr), right(nullptr) {}

    Node *rotateLL(Node *node)
    {
        Node *child = node->left;
        node->left = child->right;
        child->right = node;
        return child;
    }

    Node *rotateRR(Node *node)
    {
        Node *child = node->right;
        node->right = child->left;
        child->left = node;

        return child;
    }

    Node *rotateLR(Node *node)
    {
        Node *child = node->left;
        node->left = rotateRR(child);
        return rotateLL(node);
    }

    Node *rotateRL(Node *node)
    {
        Node *child = node->right;
        node->right = rotateLL(child);
        return rotateRR(node);
    }
};
