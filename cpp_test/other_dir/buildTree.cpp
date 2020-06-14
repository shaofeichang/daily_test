#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// start from first preorder element 前序遍历的迭代器
int pre_idx = 0;
vector<int> pre;
map<int, int> idx_map;
TreeNode *helper(int in_left, int in_right)
{
    // if there is no elements to construct subtrees 如果没有元素来构造树
    if (in_left == in_right)
        return NULL;
    // pick up pre_idx element as a root
    TreeNode *root = new TreeNode(pre[pre_idx]);

    auto iter = idx_map.find(pre[pre_idx]);
    int index = iter->second;
    // recursion 递归
    pre_idx++;
    // build left subtree 生成左树
    root->left = helper(in_left, index);
    // build right subtree 生成右树
    root->right = helper(++index, in_right);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    pre = preorder;
    // build a hashmap value -> its index 构造map，储存中序遍历的值和位置
    int idx = 0;
    for (auto i = inorder.begin(); i != inorder.end(); i++)
    {
        idx_map.insert(pair<int, int>(*i, idx++));
    }
    return helper(0, inorder.size());
}
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode * tn = buildTree(preorder, inorder);
    system("pause");
    return 0;
}