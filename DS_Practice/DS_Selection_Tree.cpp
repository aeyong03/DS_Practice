#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int key;
    int runIndex; // 노드가 속한 run의 인덱스

    TreeNode(int k = INT_MAX, int rIndex = -1) : key(k), runIndex(rIndex) {}

    bool operator<(const TreeNode &other) const
    {
        return key < other.key;
    }
};

class WinnerTree{
    public:
    vector<TreeNode> tree;
    int numLeaves;
    int size;
}