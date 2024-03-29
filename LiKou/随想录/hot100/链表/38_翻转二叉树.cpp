/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-06 15:57:59
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-06 16:03:46
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\38_翻转二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// 递归实现  也可以层序遍历实现
TreeNode* invertTree(TreeNode* root){
    if(root == nullptr) return nullptr;

    if(root->left) invertTree(root->left);
    if(root->right) invertTree(root->right);

    swap(root->left, root->right);

    return root;
}
