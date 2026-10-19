#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 이진 탐색 트리에 노드 삽입 함수
TreeNode *insert(TreeNode *root, int data)
{
    // 빈 트리인 경우, 새 노드를 생성하여 반환
    if (root == nullptr)
    {
        return new TreeNode(data);
    }

    // 데이터가 현재 노드와 같은지 탐색
    if (data == root->data)
    {
        return root;
    }
    // 데이터가 현재 노드보다 작으면 왼쪽에 삽입
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// 이진 탐색 트리에서 노드 삭제 함수

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    // 삭제할 노드 찾음
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // 삭제할 노드 찾았을 때
        // case1. 리프노드일 결루
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        // case2. 차수가 1인 노드일 경우
        else if (root->left == nullptr)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        // case3. 두개의 서브트리를 갖는경우
        else
        {
            // 오른쪽 서브트리에서 가장 작은 값을 탐색
            TreeNode *temp = findMin(root->right);
            //
        }
    }
}