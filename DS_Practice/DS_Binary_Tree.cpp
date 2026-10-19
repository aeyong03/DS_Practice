#include <iostream>

using namespace std;

class TreeNode
{
public:
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char data, TreeNode *left = nullptr, TreeNode *right = nullptr) : data(data), left(left), right(right) {}

    ~TreeNode() {}
};

void inorder(TreeNode *ptr) // 중위순회
{
    if (ptr != nullptr)
    {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void preorder(TreeNode *ptr) // 전위순회
{
    if (ptr != nullptr)
    {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(TreeNode *ptr) // 후위순회
{
    if (ptr != nullptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

TreeNode *makeRootNode(char data, TreeNode *leftNode, TreeNode *rightNode)
{
    TreeNode *root = new TreeNode(data, leftNode, rightNode);
    return root;
}

int main()
{
    TreeNode *n7 = makeRootNode('D', nullptr, nullptr);
    TreeNode *n6 = makeRootNode('C', nullptr, nullptr);
    TreeNode *n5 = makeRootNode('B', nullptr, nullptr);
    TreeNode *n4 = makeRootNode('A', nullptr, nullptr);
    TreeNode *n3 = makeRootNode('/', n6, n7);
    TreeNode *n2 = makeRootNode('*', n4, n5);
    TreeNode *n1 = makeRootNode('-', n2, n3);

    cout << "preorder : ";
    preorder(n1);

    cout << "\ninorder : ";
    inorder(n1);

    cout << "\npostorder : ";
    postorder(n1);
}