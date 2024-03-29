/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-26 14:03:24
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-26 14:15:02
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\31_二叉搜索树中第K小的元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int index = 0;
int res = 0;
void midtraversal(TreeNode* root){
    if(root == nullptr) return;

    midtraversal(root->left);

    // 不用遍历完整棵树
    if(index == 0) return;
    if(--index == 0) res = root->val;

    midtraversal(root->right);
}

// 中序遍历 小到大
// 找到第k小的
int kthSmallest(TreeNode* root, int k){
    if(root == nullptr || k <= 0) return 0;

    index = k;

    midtraversal(root);

    return res;

}