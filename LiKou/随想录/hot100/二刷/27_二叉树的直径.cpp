/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-25 14:29:02
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-25 14:41:53
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\27_二叉树的直径.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int maxLine(TreeNode* root, int& maxline){
    if(root == nullptr) return 0;

    int left = maxLine(root->left, maxline);
    int right = maxLine(root->right, maxline);

    // 记录最大直径
    maxline = max(maxline, left + right);

    return max(left, right) + 1;

}
int diameterOfBinaryTree(TreeNode* root){
    if(root == nullptr) return 0;

    int maxline = 0;

    maxLine(root, maxline);
    return maxline;
}
