/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-16 15:21:04
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-16 15:42:35
 * @FilePath: \algorithm\LiKou\随想录\二叉树\17_二叉树中的搜索.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;
//10.16
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* result = nullptr;
    //判空指针一定写在前面
    if(root == nullptr || root->val == val) return root;
    if(root->val > val) result = searchBST(root->left, val);
    if(root->val < val) result = searchBST(root->right, val);
    return result;
}
