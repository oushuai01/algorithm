/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-06 16:04:03
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-06 16:19:03
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\39_对称二叉树.cpp
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

bool campare(TreeNode* left, TreeNode* right){
    if(left != nullptr && right == nullptr) return false;
    else if(left == nullptr && right != nullptr) return false;
    else if(left == nullptr && right == nullptr) return true;
    // 不一样就直接return
    else if(left->val != right->val) return false;

    // 一样接着比下去
    bool outside = campare(left->left, right->right);
    bool inside = campare(left->right, right->left);
    bool isSame = outside && inside;
    return isSame;
}