/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-16 19:08:37
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-16 19:37:31
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\46_二叉树展开为链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.16
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* preNode = nullptr;
// 反前序遍历  递归加回溯的思想
void frontTrack(TreeNode* root){
    if(root == nullptr) return;
    
    frontTrack(root->right);
    frontTrack(root->left);

    root->left = nullptr;
    root->right = preNode;
    preNode = root;
}
void flatten(TreeNode* root) {
    if(root == nullptr) return;
    frontTrack(root);
}