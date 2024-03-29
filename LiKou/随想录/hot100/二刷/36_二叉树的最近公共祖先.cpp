/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-27 14:52:02
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-27 15:11:00
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\36_二叉树的最近公共祖先.cpp
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


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr || root == p || root == q) return root;


    // 左右中  天然的回溯
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left != nullptr && right != nullptr) return root;
    if(left != nullptr) return left;
    if(right != nullptr) return right;

    return nullptr;
}
