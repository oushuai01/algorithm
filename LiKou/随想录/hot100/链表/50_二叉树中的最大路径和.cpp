#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.21
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
int maxpath = INT_MIN;

int maxval_(TreeNode* root){
    if(root == nullptr) return 0;

    // 递归计算左右子节点的最大贡献值
    // 左右两边 小于 0 的不要
    int leftNode = max(maxval_(root->left), 0);
    int rightNode = max(maxval_(root->right), 0);

    // 节点的最大路径取决于 该节点的值和该节点左右子节点的最大贡献值
    int maxval = root->val + leftNode + rightNode;

    // 更新答案
    maxpath = max(maxpath, maxval);

    // 返回节点的最大贡献值
    return root->val + max(leftNode, rightNode);
}
int maxPathSum(TreeNode* root) {
    maxval_(root);
    return maxpath;
}