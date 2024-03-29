/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-27 15:16:48
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-27 15:43:20
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\37_二叉树中的最大路径和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxpath = INT_MIN;

int maxval_(TreeNode* root){
    if(root == nullptr) return 0;

    // 递归计算左右子节点的最大贡献值
    // 左右两边 小于 0 的不要
    int left = max(maxval_(root->left), 0);
    int right = max(maxval_(root->right), 0);

    // 节点的最大路径取决于 该节点的值和该节点左右子节点的最大贡献值
    int maxval = root->val + left + right;

    // 更新答案
    maxpath = max(maxpath, maxval);

    // 返回节点的最大贡献值
    return root->val + max(left, right);

}

int maxPathSum(TreeNode* root) {
    maxval_(root);
    return maxpath;
}

