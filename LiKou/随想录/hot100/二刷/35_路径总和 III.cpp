/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-27 14:38:26
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-27 14:50:13
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\35_路径总和 III.cpp
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

vector<TreeNode*> nodes;
int counts = 0;
// 将每个根节点都加入到nodes
void frontTrack(TreeNode* root){
    if(root == nullptr) return;

    nodes.push_back(root);
    frontTrack(root->left);
    frontTrack(root->right);

}

// 找到路径和等于targetSum的路径
void pathTrack(TreeNode* root, int targetSum, int sum){
    if(root == nullptr) return;
    sum += root->val;
    if(sum == targetSum) counts++;

    pathTrack(root->left, targetSum, sum);
    pathTrack(root->right, targetSum, sum);
}

int pathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return 0;
    // 将每个根节点都加入到nodes
    frontTrack(root);

    // 遍历每个根节点
    for(auto node : nodes){
        pathTrack(node, targetSum, 0);
    }

    return counts;

}