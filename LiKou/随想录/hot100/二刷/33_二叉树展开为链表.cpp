/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-26 14:44:44
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-26 14:52:51
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\33_二叉树展开为链表.cpp
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

// 反前序遍历
TreeNode* preNode = nullptr;
void frontTrack(TreeNode* root){
    if(root == nullptr) return;

    frontTrack(root->right);
    frontTrack(root->left);

    root->left = nullptr;
    root->right = preNode;
    preNode = root;

    return;
}
// 原地展开
void flatten(TreeNode* root){
    if(root == nullptr) return;

    frontTrack(root);
}

