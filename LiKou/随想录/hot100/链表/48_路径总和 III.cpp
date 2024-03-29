#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.17
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int counts = 0;
vector<TreeNode*> nodes;
void pathTrack(TreeNode* root, int targetSum, long long sum){
    if(root == nullptr) return;
    sum += root->val;
    if(sum == targetSum){
        counts++;
    }
    pathTrack(root->left, targetSum, sum);
    pathTrack(root->right, targetSum, sum);

}
// 前序遍历 拿到所有的节点
void frontTrack(TreeNode* root){
    if(root == nullptr) return;

    nodes.push_back(root);
    frontTrack(root->left);
    frontTrack(root->right);

}
// 题解：https://leetcode.cn/problems/path-sum-iii/solutions/100992/qian-zhui-he-di-gui-hui-su-by-shi-huo-de-xia-tian/
// 前缀和，递归，回溯 更好

// 自己写的暴力   590 题也是一样的
int pathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return 0;
    frontTrack(root);
    // 遍历所有的节点 暴力
    for(auto node : nodes){
        pathTrack(node, targetSum, 0);
    }

    return counts;
}