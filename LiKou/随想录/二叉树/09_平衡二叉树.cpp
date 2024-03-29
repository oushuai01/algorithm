/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-12 08:58:45
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-12 09:21:48
 * @FilePath: \algorithm\LiKou\随想录\二叉树\09_平衡二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//10.12
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};


int getHeight(TreeNode* node){
    if(node == nullptr) return 0;
    int leftdepth = getHeight(node->left);
    if(leftdepth == -1) return -1;
    int rightdepth = getHeight(node->right);
    if(rightdepth == -1) return -1;

    if(abs(leftdepth - rightdepth) > 1) return -1;
    else return 1 + max(leftdepth, rightdepth);
}

bool isBalanced(TreeNode* root){
    return getHeight(root) == -1 ? false : true;
}