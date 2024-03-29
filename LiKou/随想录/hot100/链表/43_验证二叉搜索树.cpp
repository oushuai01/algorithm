/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-15 20:50:19
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-15 21:18:01
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\43_验证二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.15
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
// 二叉搜索树是左边节点比中间节点小  右边节点比中间节点大  从小到排列的
// 1. 可以直接中序遍历  得到的数组看是否有序
// 2. 利用中序遍历 判断是否从小到大

// 下面的做法只做了 判断一个节点的两边是否符合  没有判断总体是否符合
bool backTrack(TreeNode* root){
    if(root == nullptr) return true;

    if(root->left)
    if(root->left->val >= root->val)
    return false;

    if(root->right)
    if(root->right->val <= root->val)
    return false;

    bool left = backTrack(root->left);
    bool right = backTrack(root->right);

    return left && right;
}

long long maxVal = LONG_LONG_MIN;
bool backTrack(TreeNode* root){
    if(root == nullptr) return true;

    bool left = backTrack(root->left);

    if(maxVal < root->val) maxVal = root->val;
    else return false;

    bool right = backTrack(root->right);

    return left && right;
}



bool isValidBST(TreeNode* root){
    if(root == nullptr) return false;
    else return backTrack(root);
}
