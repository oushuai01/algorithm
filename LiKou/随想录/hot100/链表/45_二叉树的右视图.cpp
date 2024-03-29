/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-16 18:55:35
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-16 19:06:30
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\45_二叉树的右视图.cpp
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

// 可以层序遍历 也可以 如下做法 深度优先  效果都差不多
vector<int> result;
void userTrack(TreeNode* root, int depth){
    if(root == nullptr) return;

    if(result.size() == depth){
        result.push_back(root->val);
    }

    userTrack(root->right, depth + 1);
    userTrack(root->left, depth + 1);
}
vector<int> rightSideView(TreeNode* root){
    if(root == nullptr) return result;

    userTrack(root, 0);

    return result;
}